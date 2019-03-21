#include "BaseItem.h"
#include <string.h>

BaseItem::~BaseItem()
{
    delete[] colour;
}
void BaseItem::setSymbol(char tempSymbol)
{
    symbol=tempSymbol;
}
char BaseItem::getSymbol() const
{
    return symbol;
}
int BaseItem::getType() const
{
    return type;
}
void BaseItem::setType(int tempType)
{
    type=tempType;
}
void BaseItem::removeItem()
{
    this->setPosition(-1,-1);
}
int BaseItem::getX() const
{
    return x;
}
int BaseItem::getY() const
{
    return y;
}
void BaseItem::setX(int tempX)
{
    x=tempX;
}
void BaseItem::setY(int tempY)
{
    y=tempY;
}
void BaseItem::setPosition(int tempX,int tempY)
{
    this->setX(tempX);
    this->setY(tempY);
}
char* BaseItem::getColour() const
{
    return colour;
}
void BaseItem::setColour(char* tempColour)
{
    colour=new char[strlen(tempColour)];
    colour=tempColour;
}
