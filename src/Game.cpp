#include "Game.h"

void clearMap(Spot **&tempMap,int tempSize)
{
        for(int i=0;i<tempSize;i++)
        for(int j=0;j<tempSize;j++)
               {
                   tempMap[i][j].setIfEmpty(true);
                   tempMap[i][j].setSymbol('O');
                   tempMap[i][j].setVisibleSymbol('*');
               }
}
void showMap(Spot **&tempMap,int tempSize)
{
  for(int i=0;i<tempSize;i++)
    {
        for(int j=0;j<tempSize;j++)
            cout<<tempMap[i][j].getSymbol()<<" ";
        cout<<endl;
    }
}
Game::Game(int size)
{
    mapSize=size;
    map=new Spot*[mapSize];
    for(int i=0;i<mapSize;i++)
        map[i]=new Spot[mapSize];

    clearMap(map,mapSize);

    nrOfItems=mapSize*3;
    nrOfTraps=mapSize*5;


    enum TrapTypes {Fire,Water,Smoke};
    enum ItemTypes {Red,Yellow,Blue,Green,Purple};


}
Game::~Game()
{
    if(map!=NULL)
    {
      for(int i=0;i<mapSize;i++)
           delete[] map[i];
       delete[] map;
    }
    for(int i=0;i<nrOfItems;i++)
        delete itemsOnMap[i];
    delete[] itemsOnMap;
    for(int i=0;i<nrOfTraps;i++)
        delete trapsOnMap[i];
    delete[] trapsOnMap;
}
void Game::SetUpDefault(BaseRobot &Robot) const
{
    Robot.setVRadius(4);
    Robot.setEnergy(mapSize);
    Robot.setPosition(0,0);
    Robot.setLastX(0);
    Robot.setLastY(0);
    Robot.setStrength(1);
}
void Game::PlaceRobot(const BaseRobot &Robot)
{
    map[Robot.getX()][Robot.getY()].setVisibleSymbol(Robot.getSymbol());
}
void Game::PlaceItem(const BaseItem &Item)
{
    map[Item.getX()][Item.getY()].setSymbol(Item.getSymbol());
    map[Item.getX()][Item.getY()].setIfItem(true);
    map[Item.getX()][Item.getY()].setItemType(Item.getType());
}
void Game::PlaceTrap(const BaseTrap &Trap)
{
    map[Trap.getX()][Trap.getY()].setSymbol(Trap.getSymbol());
    map[Trap.getX()][Trap.getY()].setIfTrap(true);
    map[Trap.getX()][Trap.getY()].setTrapType(Trap.getType());
}
void Game::GenerateItems()
{
    int type;
    int X,Y;
    itemsOnMap=new BaseItem*[nrOfItems];
    for(int i=0;i<nrOfItems;i++)
    {
        type=rand()%5+1;
        if(type==1)
            itemsOnMap[i]=new RedItem;
        if(type==2)
            itemsOnMap[i]=new YellowItem;
        if(type==3)
            itemsOnMap[i]=new BlueItem;
        if(type==4)
            itemsOnMap[i]=new GreenItem;
        if(type==5)
            itemsOnMap[i]=new PurpleItem;

        while(true)
        {
            X=rand()%mapSize;
            Y=rand()%mapSize;
            if(map[X][Y].isEmpty()&&!(X==0&&Y==0))
            {
                itemsOnMap[i]->setPosition(X,Y);
                PlaceItem(*itemsOnMap[i]);
                break;
            }
        }
    }
}
void Game::GenerateTraps()
{
    int type;
    int X,Y;
    trapsOnMap=new BaseTrap*[nrOfTraps];
    //trapsOnMap.resize(nrOfTraps);
    for(int i=0;i<nrOfTraps;i++)
    {
            type=rand()%3+1;
            if(type==1)
                trapsOnMap[i]=new WaterTrap;
                //trapsOnMap.push_back(new WaterTrap);
            if(type==2)
                trapsOnMap[i]=new FireTrap;
                //trapsOnMap.push_back(new FireTrap);
            if(type==3)
                trapsOnMap[i]=new SmokeTrap;
                //trapsOnMap.push_back(new SmokeTrap);
            while(true)
            {
                X=rand()%mapSize;
                Y=rand()%mapSize;
                if(map[X][Y].isEmpty()&&!(X==0&&Y==0))
                    {
                        trapsOnMap[i]->setPositon(X,Y);
                        PlaceTrap(*trapsOnMap[i]);
                        break;
                    }
            }
    }
}
void Game::GenerateGoal()
{
    int X,Y;
    while(true)
    {
       X=rand()%mapSize;
       Y=rand()%mapSize;
       if(map[X][Y].isEmpty()&&!(X==0&&Y==0))
       {
           map[X][Y].setIfGoal(true);
           goalLocation.first=X;
           goalLocation.second=Y;
           break;
       }
    }
}
void Game::ShowVisibleMap(const BaseRobot &Robot)
{
    int left=Robot.getY()-Robot.getVRadius();
    int right=Robot.getY()+Robot.getVRadius();

    for(int i=0;i<mapSize;i++)
        for(int j=0;j<mapSize;j++)
            map[i][j].setVisibleSymbol('*');

    for(int i=0;i<Robot.getVRadius()+1;i++)
         for(int j=left+i;j<right-i+1;j++)
            {
                if(Robot.getX()-i>=0&&Robot.getX()-i<mapSize&&j>=0&&j<mapSize)
                {
                    map[Robot.getX()-i][j].setVisibleSymbol(map[Robot.getX()-i][j].getSymbol());
                }
                if(Robot.getX()+i>=0&&Robot.getX()+i<mapSize&&j>=0&&j<mapSize)
                {
                    map[Robot.getX()+i][j].setVisibleSymbol(map[Robot.getX()+i][j].getSymbol());
                }
            }
    map[goalLocation.first][goalLocation.second].setVisibleSymbol(map[goalLocation.first][goalLocation.second].getSymbol());
    map[Robot.getX()][Robot.getY()].setVisibleSymbol(Robot.getSymbol());
    for(int i=0;i<mapSize;i++)
    {
        for(int j=0;j<mapSize;j++)
            cout<<map[i][j].getVisibleSymbol()<<" ";
        cout<<endl;
    }

}
pair<int,int> Game::getNextMove(pair<int,int>*pairs,int nrOfPairs,const BaseRobot &Robot) const
{
    pair<int,int> nextMove;
    if(Robot.checkAround(goalLocation))//IF THE GOAL IS NEARBY BUT CAN'T REACH IT
    {
        nextMove.first=-1;
        nextMove.second=-1;
        return nextMove;
    }
    bool found=false;
    for(int i=0;i<nrOfPairs&&found==false;i++) //IF CAN REACH GOAL
    {
        if(pairs[i].first<mapSize&&pairs[i].second<mapSize)
            if(map[pairs[i].first][pairs[i].second].isGoal())
            {
                nextMove.first=pairs[i].first;
                nextMove.second=pairs[i].second;
                found=true;
                break;
            }
    }
    for(int i=0;i<nrOfPairs&&found==false;i++) //IF CAN REACH EQUIPABLE ITEM
    {
        if(pairs[i].first<mapSize&&pairs[i].second<mapSize)
            if(map[pairs[i].first][pairs[i].second].isItem())
                if(Robot.canPickUp(map[pairs[i].first][pairs[i].second].getItemType()))
                {
                    nextMove.first=pairs[i].first;
                    nextMove.second=pairs[i].second;
                    found=true;
                    break;
                }
    }
    for(int i=0;i<nrOfPairs&&found==false;i++) //IF CAN REACH CLEAR WAY
    {
        if(pairs[i].first<mapSize&&pairs[i].second<mapSize)
                if(map[pairs[i].first][pairs[i].second].isEmpty()||map[pairs[i].first][pairs[i].second].isItem())
                    if((pairs[i].first!=Robot.getLastX())||(pairs[i].second!=Robot.getLastY()))
                    {
                        nextMove.first=pairs[i].first;
                        nextMove.second=pairs[i].second;
                        found=true;
                        break;
                    }
    }
    if(!found) //HAVE TO GO THROUGH TRAP
    {
        if(pairs[0].first<mapSize&&pairs[0].second<mapSize)
        {
            nextMove.first=pairs[0].first;
            nextMove.second=pairs[0].second;
            found=true;
        }
        if(!found)
        {
            cout<<"CAN'T GO ANYWHERE"<<endl;
        }
    }
    //cout<<"NEXT AVAILABLE MOVE: "<<nextMove.first<<" "<<nextMove.second<<endl;
    return nextMove;
}

bool Game::MainLoop(BaseRobot &Robot)
{
    int X,Y,lastX,lastY;
    pair<int,int> nextMove;
    while(true)
    {
        if(Robot.getEnergy()<=0)
        {
            cout<<"YOU RAN OUT OF ENERGY"<<endl;
            return false;
        }
        if(Robot.getStrength()<=0)
        {
            cout<<"YOU HAVE BEEN KILLED BY A TRAP"<<endl;
            return false;
        }
        lastX=Robot.getX();
        lastY=Robot.getY();

        //COMPUTE NEXT MOVE
        nextMove=getNextMove(Robot.computeNextMove(mapSize,goalLocation),Robot.getNrWaysCanGo(),Robot);
        X=nextMove.first;
        Y=nextMove.second;
        if(X==-1&&Y==-1)
        {
            ShowVisibleMap(Robot);
            cout<<"YOU WON"<<endl;
            return true;
        }
        //MOVE TO THE NEXT POSITION
        if(Robot.move(X,Y))
        {
            Robot.showStats();
            Robot.setLastX(lastX);
            Robot.setLastY(lastY);
            PlaceRobot(Robot);
            //IF THE ROBOT REACHED TO GOAL
            if(map[X][Y].isGoal())
            {
                ShowVisibleMap(Robot);
                cout<<"YOU WON"<<endl;
                return true;
            }
            //IF THE ROBOT REACHED AN ITEM
            if(map[X][Y].isItem())
            {
               for(int i=0;i<nrOfItems;i++)
                    if((*itemsOnMap[i]).getX()==X&&(*itemsOnMap[i]).getY()==Y)
                          if(Robot.canPickUp(itemsOnMap[i]->getType()))
                             {
                                Robot.pickUp(*itemsOnMap[i]);
                                cout<<"PICKED UP AN ITEM: "<<itemsOnMap[i]->getColour()<<endl;
                                map[X][Y].setIfEmpty(true);
                                Robot.showStats();
                             }
            }
            //IF THE ROBOT HIT A TRAP
            if(map[X][Y].isTrap())
            {
               for(int i=0;i<mapSize;i++)
                 if((*trapsOnMap[i]).getX()==X&&(*trapsOnMap[i]).getY()==Y)
                    {
                        cout<<"HIT A TRAP "<<trapsOnMap[i]->getName()<<endl;
                        trapsOnMap[i]->dealDamage(Robot);
                        map[X][Y].setIfEmpty(true);
                        Robot.showStats();
                    }
            }
        }
        ShowVisibleMap(Robot);
    }
}
void Game::Reset()
{
    cout<<"RESETING"<<endl;
    clearMap(map,mapSize);
    for(int i=0;i<nrOfItems;i++)
        delete itemsOnMap[i];
    delete[] itemsOnMap;

    for(int i=0;i<nrOfTraps;i++)

        delete trapsOnMap[i];
    delete[] trapsOnMap;


}
void Game::Start(BaseRobot &Robot)
{
    srand(time(NULL));
    SetUpDefault(Robot);
    PlaceRobot(Robot);
    GenerateItems();
    GenerateTraps();
    GenerateGoal();
    ShowVisibleMap(Robot);
    if(MainLoop(Robot))
    {
        cout<<"PRESS 1 TO CONTINUE"<<endl;
        int input;
        cin>>input;
        if(input==1)
        {
            Reset();
            Start(Robot);
        }
    }
}


