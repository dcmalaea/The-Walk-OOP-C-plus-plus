#include "Robots.h"

//RED ROBOT
RedRobot::~RedRobot()
{

}
int RedRobot::move(int tempX,int tempY)
{

    if(this->getEnergy()>0)
    {
        this->setEnergy(this->getEnergy()-1);
        if(tempX==getX()-1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else
           {
               this->setEnergy(this->getEnergy()+1);
               cout<<"CAN'T MOVE THERE"<<endl;
               return 0;
           }
        cout<<"MOVED TO: "<<tempX<<" "<<tempY<<endl;
        return 1;
    }
    return 0;
}
bool RedRobot::canPickUp(int tempType) const
{
    if(tempType==1||tempType==2)
        return true;
    return false;
}
void RedRobot::pickUp(BaseItem &tempItem)
{
      int bonusEnergy=0,bonusStrength=0,bonusVRadius=0;
      if(canPickUp(tempItem.getType()))
      {
          tempItem.removeItem();
          tempItem.grantBonus(bonusEnergy,bonusStrength,bonusVRadius);
          this->setEnergy(bonusEnergy+this->getEnergy()+this->getVRadius());
          this->setStrength(bonusStrength+this->getStrength()+this->getVRadius());
          this->setVRadius(bonusVRadius+this->getVRadius());
      }
}
bool RedRobot::checkAround(pair<int,int> goalLocation) const
{
    if(this->getX()-1==goalLocation.first&&this->getY()==goalLocation.second)
        return true;
    if(this->getX()+1==goalLocation.first&&this->getY()==goalLocation.second)
        return true;
    if(this->getX()==goalLocation.first&&this->getY()-1==goalLocation.second)
        return true;
    if(this->getX()==goalLocation.first&&this->getY()+1==goalLocation.second)
        return true;
    return false;
}
pair<int,int>* RedRobot::computeNextMove(int mapSize,pair<int,int> goalLocation) const
{
    double* dist=new double[getNrWaysCanGo()];
    pair<int,int>* pairs=new pair<int,int>[getNrWaysCanGo()];
    for(int i=0;i<getNrWaysCanGo();i++)
    {
        dist[i]=INT_MAX;
        pairs[i].first=INT_MAX;
        pairs[i].second=INT_MAX;
    }
    if((this->getX()-1)>=0&&(this->getX()-1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[0]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[0].first=this->getX()-1;
            pairs[0].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[1]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[1].first=this->getX()-1;
            pairs[1].second=this->getY()+1;
        }
    }
    if((this->getX()+1)>=0&&(this->getX()+1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[2]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[2].first=this->getX()+1;
            pairs[2].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[3]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[3].first=this->getX()+1;
            pairs[3].second=this->getY()+1;
        }
    }
    for(int i=0;i<getNrWaysCanGo();i++)
        for(int j=i;j<getNrWaysCanGo();j++)
    {
        if(dist[j]<dist[i])
            {
                swap(dist[j],dist[i]);
                swap(pairs[j],pairs[i]);
            }
    }
    return pairs;
}

//YELLOW ROBOT

YellowRobot::~YellowRobot()
{
    //dtor
}
int YellowRobot::move(int tempX,int tempY)
{
    //cout<<"IM AT "<<getX()<<" "<<getY()<<endl;
    //cout<<"ATTEMPT "<<tempX<<" "<<tempY<<endl;
    if(getEnergy()>0)
    {
        setEnergy(getEnergy()-2);
        if(tempX==getX()-1&&tempY==getY())
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY())
            setPosition(tempX,tempY);
        else if(tempX==getX()&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else
        {
            setEnergy(getEnergy()+2);
            cout<<"CAN'T MOVE THERE"<<endl;
            return 0;
        }
        cout<<"MOVED TO: "<<tempX<<" "<<tempY<<endl;
        return 1;
    }
    return 0;
}
bool YellowRobot::canPickUp(int tempType) const
{
    if(tempType==2||tempType==3)
        return true;
    return false;
}
void YellowRobot::pickUp(BaseItem &tempItem)
{
    int bonusEnergy=0,bonusStrength=0,bonusVRadius=0;
    if(canPickUp(tempItem.getType()))
    {
        tempItem.removeItem();
        tempItem.grantBonus(bonusEnergy,bonusStrength,bonusVRadius);
        this->setEnergy(bonusEnergy+this->getEnergy()+2);
        this->setStrength(bonusStrength+this->getStrength()+2);
        this->setVRadius(bonusVRadius+this->getVRadius());
    }
}

bool YellowRobot::checkAround(pair<int,int> goalLocation) const
{
    if(getX()-1==goalLocation.first&&getY()-1==goalLocation.second)
        return true;
    if(getX()-1==goalLocation.first&&getY()+1==goalLocation.second)
        return true;
    if(getX()+1==goalLocation.first&&getY()+1==goalLocation.second)
        return true;
    if(getX()+1==goalLocation.first&&getY()-1==goalLocation.second)
        return true;
    return false;
}
pair<int,int>* YellowRobot::computeNextMove(int mapSize,pair<int,int> goalLocation) const
{
    double* dist=new double[getNrWaysCanGo()];
    pair<int,int>* pairs=new pair<int,int>[getNrWaysCanGo()];
    for(int i=0;i<getNrWaysCanGo();i++)
    {
        dist[i]=INT_MAX;
        pairs[i].first=INT_MAX;
        pairs[i].second=INT_MAX;
    }
    if(getX()>=0&&getX()<mapSize)
    {
        if(getY()-1>=0&&getY()-1<mapSize)
        {
            dist[0]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[0].first=getX();
            pairs[0].second=getY()-1;
        }
        if(getY()+1>=0&&getY()-1<mapSize)
        {
            dist[1]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()+1-goalLocation.second,2));
            pairs[1].first=getX();
            pairs[1].second=getY()+1;
        }
    }
    if(getY()>=0&&getY()<mapSize)
    {
        if(getX()-1>=0&&getX()-1<mapSize)
        {
            dist[2]=sqrt(pow(getX()-1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[2].first=getX()-1;
            pairs[2].second=getY();
        }
        if(getX()+1>=0&&getX()+1<mapSize)
        {
            dist[3]=sqrt(pow(getX()+1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[3].first=getX()+1;
            pairs[3].second=getY();
        }
    }

    for(int i=0;i<getNrWaysCanGo();i++)
        for(int j=i;j<getNrWaysCanGo();j++)
    {
        if(dist[j]<dist[i])
            {
                swap(dist[j],dist[i]);
                swap(pairs[j],pairs[i]);
            }
    }
    return pairs;
}

//BLUE ROBOT
BlueRobot::~BlueRobot()
{
    //dtor
}
int BlueRobot::move(int tempX,int tempY)
{
    //cout<<"IM AT "<<getX()<<" "<<getY()<<endl;
    //cout<<"ATTEMPT "<<tempX<<" "<<tempY<<endl;
    if(getEnergy()>0)
    {
        setEnergy(getEnergy()-2);
        if(tempX==getX()-1&&tempY==getY())
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY())
            setPosition(tempX,tempY);
        else if(tempX==getX()&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else
        {
            setEnergy(getEnergy()+2);
            cout<<"CAN'T MOVE THERE"<<endl;
            return 0;
        }
        cout<<"MOVED TO: "<<tempX<<" "<<tempY<<endl;
        return 1;
    }
    return 0;
}
bool BlueRobot::canPickUp(int tempType) const
{
    if(tempType==3)
        return true;
    return false;
}
void BlueRobot::pickUp(BaseItem &tempItem)
{
    int bonusEnergy=0,bonusStrength=0,bonusVRadius=0;
    if(canPickUp(tempItem.getType()))
    {
        tempItem.removeItem();
        tempItem.grantBonus(bonusEnergy,bonusStrength,bonusVRadius);
        this->setEnergy(bonusEnergy+this->getEnergy()+1+this->getVRadius());
        this->setStrength(bonusStrength+this->getStrength()+this->getVRadius());
        this->setVRadius(bonusVRadius+this->getVRadius());
    }
}
bool BlueRobot::checkAround(pair<int,int> goalLocation) const
{
    return false;
}
pair<int,int>* BlueRobot::computeNextMove(int mapSize,pair<int,int> goalLocation) const
{
    double* dist=new double[getNrWaysCanGo()];
    pair<int,int>* pairs=new pair<int,int>[getNrWaysCanGo()];
    for(int i=0;i<getNrWaysCanGo();i++)
    {
        dist[i]=INT_MAX;
        pairs[i].first=INT_MAX;
        pairs[i].second=INT_MAX;
    }
    if(getX()>=0&&getX()<mapSize)
    {
        if(getY()-1>=0&&getY()-1<mapSize)
        {
            dist[0]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[0].first=getX();
            pairs[0].second=getY()-1;
        }
        if(getY()+1>=0&&getY()-1<mapSize)
        {
            dist[1]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()+1-goalLocation.second,2));
            pairs[1].first=getX();
            pairs[1].second=getY()+1;
        }
    }
    if(getY()>=0&&getY()<mapSize)
    {
        if(getX()-1>=0&&getX()-1<mapSize)
        {
            dist[2]=sqrt(pow(getX()-1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[2].first=getX()-1;
            pairs[2].second=getY();
        }
        if(getX()+1>=0&&getX()+1<mapSize)
        {
            dist[3]=sqrt(pow(getX()+1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[3].first=getX()+1;
            pairs[3].second=getY();
        }
    }
    if(getX()-1>=0&&getX()-1<mapSize)
    {
        if(getY()-1>=0&&getY()-1<mapSize)
        {
            dist[4]=sqrt(pow(getX()-1-goalLocation.first,2)+pow(getY()-1-goalLocation.second,2));
            pairs[4].first=getX()-1;
            pairs[4].second=getY()-1;
        }
        if(getY()+1>=0&&getY()+1<mapSize)
        {
            dist[5]=sqrt(pow(getX()-1-goalLocation.first,2)+pow(getY()+1-goalLocation.second,2));
            pairs[5].first=getX()-1;
            pairs[5].second=getY()+1;
        }
    }
    if(getX()+1>=0&&getX()+1<mapSize)
    {
        if(getY()-1>=0&&getY()-1<mapSize)
        {
            dist[6]=sqrt(pow(getX()+1-goalLocation.first,2)+pow(getY()-1-goalLocation.second,2));
            pairs[6].first=getX()+1;
            pairs[6].second=getY()-1;
        }
        if(getY()+1>=0&&getY()+1<mapSize)
        {
            dist[7]=sqrt(pow(getX()+1-goalLocation.first,2)+pow(getY()+1-goalLocation.second,2));
            pairs[7].first=getX()+1;
            pairs[7].second=getY()+1;
        }
    }

    for(int i=0;i<getNrWaysCanGo();i++)
        for(int j=i;j<getNrWaysCanGo();j++)
    {
        if(dist[j]<dist[i])
            {
                swap(dist[j],dist[i]);
                swap(pairs[j],pairs[i]);
            }
    }
    return pairs;
}
//GREEN ROBOT
GreenRobot::~GreenRobot()
{
    //dtor
}
int GreenRobot::move(int tempX,int tempY)
{
    //cout<<"IM AT "<<getX()<<" "<<getY()<<endl;
    //cout<<"ATTEMPT "<<tempX<<" "<<tempY<<endl;
    if(getEnergy()>0)
    {
        setEnergy(getEnergy()-3);
        if(tempX==getX()-1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY())
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY())
            setPosition(tempX,tempY);
        else
        {
            setEnergy(getEnergy()+2);
            cout<<"CAN'T MOVE THERE"<<endl;
            return 0;
        }
        cout<<"MOVED TO: "<<tempX<<" "<<tempY<<endl;
        return 1;
    }
    return 0;
}
bool GreenRobot::canPickUp(int tempType) const
{
    if(tempType==2||tempType==3||tempType==4)
        return true;
    return false;
}
void GreenRobot::pickUp(BaseItem &tempItem)
{
    int bonusEnergy=0,bonusStrength=0,bonusVRadius=0;
    if(canPickUp(tempItem.getType()))
    {
        tempItem.removeItem();
        tempItem.grantBonus(bonusEnergy,bonusStrength,bonusVRadius);
        this->setEnergy(bonusEnergy+this->getEnergy()+3+this->getVRadius());
        this->setStrength(bonusStrength+this->getStrength()+this->getVRadius());
        this->setVRadius(bonusVRadius+this->getVRadius());
    }
}
bool GreenRobot::checkAround(pair<int,int> goalLocation) const
{
    if(getX()==goalLocation.first&&getY()-1==goalLocation.second)
        return true;
    if(getX()==goalLocation.first&&getY()+1==goalLocation.second)
        return true;
    return false;
}
pair<int,int>* GreenRobot::computeNextMove(int mapSize,pair<int,int> goalLocation) const
{
    double* dist=new double[getNrWaysCanGo()];
    pair<int,int>* pairs=new pair<int,int>[getNrWaysCanGo()];
    for(int i=0;i<getNrWaysCanGo();i++)
    {
        dist[i]=INT_MAX;
        pairs[i].first=INT_MAX;
        pairs[i].second=INT_MAX;
    }
    if((this->getX()-1)>=0&&(this->getX()-1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[0]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[0].first=this->getX()-1;
            pairs[0].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[1]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[1].first=this->getX()-1;
            pairs[1].second=this->getY()+1;
        }
    }
    if((this->getX()+1)>=0&&(this->getX()+1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[2]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[2].first=this->getX()+1;
            pairs[2].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[3]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[3].first=this->getX()+1;
            pairs[3].second=this->getY()+1;
        }
    }
    if(getY()>=0&&getY()<mapSize)
    {
        if(getX()-1>=0&&getX()-1<mapSize)
        {
            dist[4]=sqrt(pow(getX()-1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[4].first=getX()-1;
            pairs[4].second=getY();
        }
        if(getX()+1>=0&&getX()+1<mapSize)
        {
            dist[5]=sqrt(pow(getX()+1-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[5].first=getX()+1;
            pairs[5].second=getY();
        }
    }
    for(int i=0;i<getNrWaysCanGo();i++)
        for(int j=i;j<getNrWaysCanGo();j++)
    {
        if(dist[j]<dist[i])
            {
                swap(dist[j],dist[i]);
                swap(pairs[j],pairs[i]);
            }
    }
    return pairs;
}
//PURPLE ROBOT
PurpleRobot::~PurpleRobot()
{
    //dtor
}
int PurpleRobot::move(int tempX,int tempY)
{
    //cout<<"IM AT "<<getX()<<" "<<getY()<<endl;
    //cout<<"ATTEMPT "<<tempX<<" "<<tempY<<endl;
    if(getEnergy()>0)
    {
        setEnergy(getEnergy()-3);
        if(tempX==getX()&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else if(tempX==getX()-1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()+1)
            setPosition(tempX,tempY);
        else if(tempX==getX()+1&&tempY==getY()-1)
            setPosition(tempX,tempY);
        else
        {
            setEnergy(getEnergy()+3);
            cout<<"CAN'T MOVE THERE"<<endl;
            return 0;
        }
        cout<<"MOVED TO: "<<tempX<<" "<<tempY<<endl;
        return 1;
    }
    return 0;
}
bool PurpleRobot::canPickUp(int tempType) const
{
    if(tempType==1||tempType==2||tempType==3||tempType==4||tempType==5)
        return true;
    return false;
}
void PurpleRobot::pickUp(BaseItem &tempItem)
{
      int bonusEnergy=0,bonusStrength=0,bonusVRadius=0;
      if(canPickUp(tempItem.getType()))
      {
          tempItem.removeItem();
          tempItem.grantBonus(bonusEnergy,bonusStrength,bonusVRadius);
          this->setEnergy(bonusEnergy+this->getEnergy()+4+this->getVRadius());
          this->setStrength(bonusStrength+this->getStrength()+2+this->getVRadius());
          this->setVRadius(bonusVRadius+this->getVRadius());
      }
}
bool PurpleRobot::checkAround(pair<int,int> goalLocation) const
{
    if(getX()-1==goalLocation.first&&getY()==goalLocation.second)
        return true;
    if(getX()+1==goalLocation.first&&getY()==goalLocation.second)
        return true;
    return false;
}
pair<int,int>* PurpleRobot::computeNextMove(int mapSize,pair<int,int> goalLocation) const
{
    double* dist=new double[getNrWaysCanGo()];
    pair<int,int>* pairs=new pair<int,int>[getNrWaysCanGo()];
    for(int i=0;i<getNrWaysCanGo();i++)
    {
        dist[i]=INT_MAX;
        pairs[i].first=INT_MAX;
        pairs[i].second=INT_MAX;
    }
    if((this->getX()-1)>=0&&(this->getX()-1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[0]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[0].first=this->getX()-1;
            pairs[0].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[1]=sqrt(pow(this->getX()-1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[1].first=this->getX()-1;
            pairs[1].second=this->getY()+1;
        }
    }
    if((this->getX()+1)>=0&&(this->getX()+1)<mapSize)
    {
        if((this->getY()-1)>=0&&(this->getY()-1)<mapSize)
        {
            dist[2]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()-1-goalLocation.second,2));
            pairs[2].first=this->getX()+1;
            pairs[2].second=this->getY()-1;
        }
        if((this->getY()+1)>=0&&(this->getY()+1)<mapSize)
        {
            dist[3]=sqrt(pow(this->getX()+1-goalLocation.first,2)+pow(this->getY()+1-goalLocation.second,2));
            pairs[3].first=this->getX()+1;
            pairs[3].second=this->getY()+1;
        }
    }
    if(getX()>=0&&getX()<mapSize)
    {
        if(getY()-1>=0&&getY()-1<mapSize)
        {
            dist[4]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()-goalLocation.second,2));
            pairs[4].first=getX();
            pairs[4].second=getY()-1;
        }
        if(getY()+1>=0&&getY()-1<mapSize)
        {
            dist[5]=sqrt(pow(getX()-goalLocation.first,2)+pow(getY()+1-goalLocation.second,2));
            pairs[5].first=getX();
            pairs[5].second=getY()+1;
        }
    }
    for(int i=0;i<getNrWaysCanGo();i++)
        for(int j=i;j<getNrWaysCanGo();j++)
    {
        if(dist[j]<dist[i])
            {
                swap(dist[j],dist[i]);
                swap(pairs[j],pairs[i]);
            }
    }
    return pairs;
}
