#ifndef TRAPS_H
#define TRAPS_H

#include <BaseTrap.h>

class FireTrap : public BaseTrap
{
    public:
        FireTrap():BaseTrap(1,'F',6,"FIRE"){}
        virtual ~FireTrap();
        void dealDamage(BaseRobot &Robot);

    protected:

    private:
};

class SmokeTrap : public BaseTrap
{
    public:
        SmokeTrap():BaseTrap(3,'S',1,"SMOKE"){}
        virtual ~SmokeTrap();

        void dealDamage(BaseRobot &Robot);

    protected:

    private:
};

class WaterTrap : public BaseTrap
{
    public:
        WaterTrap():BaseTrap(2,'W',5,"WATER"){}
        virtual ~WaterTrap();
        void dealDamage(BaseRobot &Robot);

    protected:

    private:
};




#endif // TRAPS_H
