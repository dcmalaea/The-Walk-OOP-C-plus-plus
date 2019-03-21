#ifndef BASEROBOT_H
#define BASEROBOT_H
#include <BaseItem.h>
#include <iostream>
using namespace std;

class BaseRobot
{
    int x; //linie
    int y; //coloana

    //pozitia anterioara
    int lastX;
    int lastY;

    int type; //1 - red , 2 - yellow, 3 - blue, 4 - green, 5 - purple
    char symbol;
    int nrWaysCanGo; //Nr. directiilor in care robotul se poate deplasa


    //RESURSE
    int energy;
    int vRadius; //BONUS PT ITEME
    int strength;


    public:
        BaseRobot(int tempType,char tempSymbol,int nrWays):type(tempType),symbol(tempSymbol),nrWaysCanGo(nrWays){}
        virtual ~BaseRobot();
        void setPosition(int tempX,int tempY);
        int getX() const;
        int getY() const;
        int getLastX() const;
        int getLastY() const;
        void setLastX(int tempX);
        void setLastY(int tempY);
        void showStats() const;

        //Verifica daca poate echipa un tip de item
        virtual bool canPickUp(int type)const=0;

        //Se deplaseaza pe o noua pozitie
        virtual int move(int tempX,int tempY)=0;

        //Echipeaza un item
        virtual void pickUp(BaseItem &tempItem)=0;

        //Verifica daca comoara e intr-o pozitie unde robotul nu poate ajunge
        virtual bool checkAround(pair<int,int> goalLocation)const=0;

        //Returneaza coordonate unde se poate deplasa (sortate dupa distanta fata de comoara)
        virtual pair<int,int>* computeNextMove(int mapSize,pair<int,int> goalLocation)const=0;

        void setSymbol(char tempSymbol);
        char getSymbol() const;
        void setType(int tempType);
        int getType() const;
        void setEnergy(int tempEnergy);
        int getEnergy() const;
        void setVRadius(int tempVRadius);
        int getVRadius() const;
        void setStrength(int tempStrength);
        int getStrength() const;
        void setNrWaysCanGo(int value);
        int getNrWaysCanGo() const;

    protected:


    private:
};

#endif // BASEROBOT_H
