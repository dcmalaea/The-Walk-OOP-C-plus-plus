#ifndef BASETRAP_H
#define BASETRAP_H
#include "BaseRobot.h"
#include <string.h>
using namespace std;

class BaseTrap
{
    int type; //tipul
    char symbol;
    int damage;
    //Denumirea
    char *name;
    //Locatiia
    int X;
    int Y;
    public:
        BaseTrap(int tempType,char tempSymbol,int tempDmg,char *tempName):type(tempType),symbol(tempSymbol),damage(tempDmg),name(tempName){}
        virtual ~BaseTrap();

        int getX() const;
        int getY() const;
        void setX(int tempX);
        void setY(int tempY);
        void setName(char *tempName);
        char* getName() const;
        char getSymbol() const;
        void setSymbol(char tempSymbol);
        void setPositon(int tempX,int tempY);
        void setType(int tempType);
        int getType() const;
        int getDamage() const;
        void setDamage(int tempDmg);

        //Pozitia devine -1,-1
        void removeTrap();

        //Aplica daune robotului
        virtual void dealDamage(BaseRobot &Robot)=0;

    protected:

    private:
};

#endif // BASETRAP_H
