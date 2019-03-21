#include "Items.h"

RedItem::~RedItem()
{
    //dtor
}
void RedItem::grantBonus(int &energy,int &strength,int &VRadius)
{
    energy++;
}


YellowItem::~YellowItem()
{
    //dtor
}
void YellowItem::grantBonus(int &energy,int &strength,int &VRadius)
{
    VRadius++;
}


BlueItem::~BlueItem()
{
    //dtor
}
void BlueItem::grantBonus(int &energy,int &strength,int &VRadius)
{
    strength++;
}

GreenItem::~GreenItem()
{
    //dtor
}
void GreenItem::grantBonus(int &energy,int &strength,int &VRadius)
{
    energy++;
    strength++;
}

PurpleItem::~PurpleItem()
{
    //dtor
}
void PurpleItem::grantBonus(int &energy,int &strength,int &VRadius)
{
    energy++;
    strength++;
    VRadius++;
}



