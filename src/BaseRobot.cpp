#include "BaseRobot.h"
using namespace std;

BaseRobot::~BaseRobot()
{
    //dtor
}
int BaseRobot::getNrWaysCanGo() const
{
    return nrWaysCanGo;
}
void BaseRobot::setNrWaysCanGo(int value)
{
    nrWaysCanGo=value;
}
void BaseRobot::setPosition(int tempX,int tempY)
{
    x=tempX;
    y=tempY;
}
int BaseRobot::getX() const
{
    return x;
}
int BaseRobot::getY() const
{
    return y;
}
void BaseRobot::showStats() const
{
    cout<<"ENERGY: "<<energy<<endl;
    cout<<"STRENGTH: "<<strength<<endl;
    cout<<"BONUS ON ITEMS: "<<vRadius<<endl;
    cout<<endl;
}

void BaseRobot::setSymbol(char tempSymbol)
{
    symbol=tempSymbol;
}
char BaseRobot::getSymbol() const
{
    return symbol;
}
void BaseRobot::setType(int tempType)
{
    type=tempType;
}
int BaseRobot::getType() const
{
    return type;
}
void BaseRobot::setEnergy(int tempEnergy)
{
    energy=tempEnergy;
}
int BaseRobot::getEnergy() const
{
    return energy;
}
void BaseRobot::setVRadius(int tempVRradius)
{
    vRadius=tempVRradius;
}
int BaseRobot::getVRadius() const
{
    return vRadius;
}
void BaseRobot::setStrength(int tempStrength)
{
    strength=tempStrength;
}
int BaseRobot::getStrength() const
{
    return strength;
}
int BaseRobot::getLastX() const
{
    return lastX;
}
int BaseRobot::getLastY() const
{
    return lastY;
}
void BaseRobot::setLastX(int tempX)
{
    lastX=tempX;
}
void BaseRobot::setLastY(int tempY)
{
    lastY=tempY;
}
