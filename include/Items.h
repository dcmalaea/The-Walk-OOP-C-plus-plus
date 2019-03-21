#ifndef ITEMS_H
#define ITEMS_H

#include <BaseItem.h>

class RedItem : public BaseItem
{
    public:
        RedItem():BaseItem(1,'1',"RED"){}
        virtual ~RedItem();
        void grantBonus(int &energy,int &strength,int &VRadius);

    protected:

    private:
};

class YellowItem : public BaseItem
{
    public:
        YellowItem():BaseItem(2,'2',"YELLOW"){}
        virtual ~YellowItem();
        void grantBonus(int &energy,int &strength,int &VRadius);

    protected:

    private:
};

class BlueItem : public BaseItem
{
    public:
        BlueItem():BaseItem(3,'3',"BLUE"){}
        virtual ~BlueItem();
        void grantBonus(int &energy,int &strength,int &VRadius);

    protected:

    private:
};

class GreenItem : public BaseItem
{
    public:
        GreenItem():BaseItem(4,'4',"GREEN"){}
        virtual ~GreenItem();
        void grantBonus(int &energy,int &strength,int &VRadius);

    protected:

    private:
};

class PurpleItem : public BaseItem
{
    public:
        PurpleItem():BaseItem(5,'5',"PURPLE"){}
        virtual ~PurpleItem();
        void grantBonus(int &energy,int &strength,int &VRadius);

    protected:

    private:
};


#endif // ITEMS_H
