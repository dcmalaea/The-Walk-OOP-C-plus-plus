#ifndef ROBOTS_H
#define ROBOTS_H

#include <BaseRobot.h>
#include <math.h>
#include <limits>

class RedRobot : public BaseRobot
{
    public:
        RedRobot():BaseRobot(1,'#',4){}
        RedRobot(char tempSymbol):BaseRobot(1,tempSymbol,4){}
        virtual ~RedRobot();
        int move(int tempX,int tempY);
        bool canPickUp(int type)const;
        void pickUp(BaseItem &tempItem);
        bool checkAround(pair<int,int> goalLocation)const;
        pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const;

    protected:

    private:
};

class YellowRobot : public BaseRobot
{
    public:
        YellowRobot():BaseRobot(2,'#',4){}
        YellowRobot(char tempSymbol):BaseRobot(2,tempSymbol,4){}
        virtual ~YellowRobot();
        int move(int tempX,int tempY);
        bool canPickUp(int type)const;
        void pickUp(BaseItem &tempItem);
        bool checkAround(pair<int,int> goalLocation)const;
        pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const;

    protected:

    private:
};

class BlueRobot : public BaseRobot
{
    public:
        BlueRobot():BaseRobot(3,'#',8){}
        BlueRobot(char tempSymbol):BaseRobot(3,tempSymbol,8){}
        virtual ~BlueRobot();
        int move(int tempX,int tempY);
        bool canPickUp(int type)const;
        void pickUp(BaseItem &tempItem);
        bool checkAround(pair<int,int> goalLocation)const;
        pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const;

    protected:

    private:
};

class GreenRobot : public BaseRobot
{
    public:
        GreenRobot():BaseRobot(4,'#',6){}
        GreenRobot(char tempSymbol):BaseRobot(4,tempSymbol,6){}
        virtual ~GreenRobot();
        int move(int tempX,int tempY);
        bool canPickUp(int type)const;
        void pickUp(BaseItem &tempItem);
        bool checkAround(pair<int,int> goalLocation)const;
        pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const;

    protected:

    private:
};

class PurpleRobot : public BaseRobot
{
    public:
        PurpleRobot():BaseRobot(5,'#',6){}
        PurpleRobot(char tempSymbol):BaseRobot(5,tempSymbol,6){}
        virtual ~PurpleRobot();
        int move(int tempX,int tempY);
        bool canPickUp(int type)const;
        void pickUp(BaseItem &tempItem);
        bool checkAround(pair<int,int> goalLocation)const;
        pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const;

    protected:

    private:
};

#endif // ROBOTS_H
