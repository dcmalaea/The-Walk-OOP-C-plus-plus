#include <iostream>
#include "Game.h"
#include "Robots.h"
using namespace std;

int main()
{
    int input;
    int mapSize;
    cout<<" CHOOSE YOUR ROBOT "<<endl;
    cout<<" 1 - RED ROBOT "<<endl;
    cout<<" 2 - YELLOW ROBOT "<<endl;
    cout<<" 3 - BLUE ROBOT "<<endl;
    cout<<" 4 - GREEN ROBOT "<<endl;
    cout<<" 5 - PURPLE ROBOT "<<endl;
    cout<<" 0 - EXIT "<<endl;
    cin>>input;
    if(input==1)
    {
        RedRobot *Robot=new RedRobot();
        cout<<" ENTER MAP SIZE" <<endl;
        cin>>mapSize;
        Game START(mapSize);
        START.Start(*Robot);
    }
    else if(input==2)
    {
        YellowRobot *Robot=new YellowRobot;
        cout<<" ENTER MAP SIZE" <<endl;
        cin>>mapSize;
        Game START(mapSize);
        START.Start(*Robot);
    }
    else if(input==3)
    {
        BlueRobot *Robot=new BlueRobot;
        cout<<" ENTER MAP SIZE" <<endl;
        cin>>mapSize;
        Game START(mapSize);
        START.Start(*Robot);
    }
    else if(input==4)
    {
        GreenRobot *Robot=new GreenRobot;
        cout<<" ENTER MAP SIZE" <<endl;
        cin>>mapSize;
        Game START(mapSize);
        START.Start(*Robot);
    }
    else if(input==5)
    {
        PurpleRobot *Robot=new PurpleRobot;
        cout<<" ENTER MAP SIZE" <<endl;
        cin>>mapSize;
        Game START(mapSize);
        START.Start(*Robot);
    }
    else if(input==0)
    {
        return 0;
    }
    return 0;
}
