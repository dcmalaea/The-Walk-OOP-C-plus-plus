#include "BaseTrap.h"

BaseTrap::~BaseTrap()
{
    delete[] name;
}
void BaseTrap::setName(char *tempName)
{
    name=new char[strlen(tempName)];
    name=tempName;
}
char* BaseTrap::getName() const
{
    return name;
}
int BaseTrap::getType() const
{
    return type;
}
void BaseTrap::setType(int tempType)
{
    type=tempType;
}
int BaseTrap::getDamage() const
{
    return damage;
}
void BaseTrap::setDamage(int tempDmg)
{
    damage=tempDmg;
}
int BaseTrap::getX() const
{
    return X;
}
int BaseTrap::getY() const
{
    return Y;
}
void BaseTrap::setX(int tempX)
{
    X=tempX;
}
void BaseTrap::setY(int tempY)
{
    Y=tempY;
}
void BaseTrap::setPositon(int tempX,int tempY)
{
    this->setX(tempX);
    this->setY(tempY);
}
char BaseTrap::getSymbol() const
{
    return symbol;
}
void BaseTrap::setSymbol(char tempSymbol)
{
    symbol=tempSymbol;
}
void BaseTrap::removeTrap()
{
    this->setPositon(-1,-1);
}
