#include "Spot.h"

Spot::Spot()
{
    //ctor
}

Spot::~Spot()
{
    //dtor
}
void Spot::setSymbol(char tempSymbol)
{
    symbol=tempSymbol;
}
void Spot::setVisibleSymbol(char tempSymbol)
{
    visibleSymbol=tempSymbol;
}
void Spot::setIfEmpty(bool value)
{
    empty=value;
    if(empty)
    {
        setSymbol('O');
        goal=false;
        item=false;
        trap=false;
    }
}
void Spot::setIfGoal(bool value)
{
    goal=value;
    if(goal)
    {
        setSymbol('G');
        empty=false;
        item=false;
        trap=false;
    }
}
void Spot::setIfItem(bool value)
{
    item=value;
    if(item)
    {
        goal=false;
        empty=false;
        trap=false;
    }
}
void Spot::setIfTrap(bool value)
{
    trap=value;
    if(trap)
    {
        goal=false;
        item=false;
        empty=false;
    }
}
void Spot::setItemType(int tempType)
{
        itemType=tempType;
}
void Spot::setTrapType(int tempType)
{
    trapType=tempType;
}
void Spot::setX(int tempX)
{
    X=tempX;
}
void Spot::setY(int tempY)
{
    Y=tempY;
}
char Spot::getSymbol() const
{
    return symbol;
}
char Spot::getVisibleSymbol() const
{
    return visibleSymbol;
}
bool Spot::isEmpty() const
{
    return empty;
}
bool Spot::isGoal() const
{
    return goal;
}
bool Spot::isItem() const
{
    return item;
}
bool Spot::isTrap() const
{
    return trap;
}
int Spot::getItemType() const
{
    return itemType;
}
int Spot::getTrapType() const
{
    return trapType;
}
int Spot::getX() const
{
    return X;
}
int Spot::getY() const
{
    return Y;
}
pair<int,int> Spot::getPosition()const
{
    return position;
}
