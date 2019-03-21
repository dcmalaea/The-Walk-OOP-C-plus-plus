#ifndef BASEITEM_H
#define BASEITEM_H


class BaseItem
{
    int type; //tipul
    //Locatia
    int x;
    int y;
    char symbol;
    //Denumirea
    char *colour;

    public:
        BaseItem(int tempType,char tempSymbol,char*tempColour):type(tempType),symbol(tempSymbol),colour(tempColour){}
        virtual ~BaseItem();

        char getSymbol() const;
        void setSymbol(char tempSymbol);
        int getType() const;
        void setType(int tempType);
        int getX() const;
        void setX(int tempX);
        int getY() const;
        void setY(int tempY);
        void setPosition(int tempX,int tempY);
        void setColour(char *tempColour);
        char* getColour() const;

        //Pozitia devine -1,-1
        void removeItem();

        //Adauga bonusuri robotului
        virtual void grantBonus(int &energy,int &strength,int &VRadius)=0;

    protected:

    private:
};

#endif // BASEITEM_H
