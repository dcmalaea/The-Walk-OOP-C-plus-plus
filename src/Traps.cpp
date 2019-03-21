#include "Traps.h"

FireTrap::~FireTrap()
{
    //dtor
}
void FireTrap::dealDamage(BaseRobot &Robot)
{
    Robot.setStrength(Robot.getStrength()-this->getDamage()-Robot.getVRadius()*5);
}


WaterTrap::~WaterTrap()
{
    //dtor
}
void WaterTrap::dealDamage(BaseRobot &Robot)
{
    Robot.setEnergy(Robot.getEnergy()-this->getDamage()-Robot.getVRadius());
}


SmokeTrap::~SmokeTrap()
{
    //dtor
}
void SmokeTrap::dealDamage(BaseRobot &Robot)
{
    Robot.setVRadius(Robot.getVRadius()-this->getDamage());

}

