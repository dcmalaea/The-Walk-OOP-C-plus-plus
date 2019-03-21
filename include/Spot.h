#ifndef SPOT_H
#define SPOT_H
#include <iostream>
using namespace std;


class Spot
{
    char symbol;
    char visibleSymbol;
    bool goal;
    bool empty;
    bool item;
    bool trap;
    int itemType;
    int trapType;

    int X;
    int Y;
    pair<int,int> position;

    public:
        Spot();
        virtual ~Spot();
        void setSymbol(char tempSymbol);
        void setVisibleSymbol(char tempSymbol);
        void setIfEmpty(bool value);
        void setIfGoal(bool value);
        void setIfItem(bool value);
        void setIfTrap(bool value);
        void setItemType(int tempType);
        void setTrapType(int tempType);
        void setX(int tempX);
        void setY(int tempY);
        char getSymbol() const;
        char getVisibleSymbol() const;
        bool isEmpty() const;
        bool isGoal() const;
        bool isItem() const;
        bool isTrap() const;
        int getItemType() const;
        int getTrapType() const;
        int getX() const;
        int getY() const;
        pair<int,int> getPosition() const;

    protected:

    private:
};

#endif // SPOT_H
