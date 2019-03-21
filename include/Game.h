#ifndef GAME_H
#define GAME_H
#include "BaseRobot.h"
#include "BaseItem.h"
#include "BaseTrap.h"
#include "Items.h"
#include "Traps.h"
#include "Spot.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class Game
{
    Spot **map; //HARTA
    BaseItem **itemsOnMap; //ITEME
    BaseTrap **trapsOnMap; //CAPCANE
    int nrOfItems;
    int nrOfTraps;
    int mapSize;
    pair<int,int> goalLocation; //POZITIA COMORII
    public:
        Game(int size);
        virtual ~Game();
        void Start(BaseRobot &Robot);

    private:
        //Reseteaza jocul intre runde
        void Reset();

        //Afiseaza harta
        void ShowVisibleMap(const BaseRobot &Robot);

        //Seteaza robotul cu valori implicite
        void SetUpDefault(BaseRobot &Robot)const;

        //Aseaza robotul pe harta
        void PlaceRobot(const BaseRobot &Robot);

        //Aseaza un item pe harta
        void PlaceItem(const BaseItem &Item);

        //Aseaza o capcana pe harta
        void PlaceTrap(const BaseTrap &Trap);

        //Creaza iteme
        void GenerateItems();

        //Creaza comoara
        void GenerateGoal();

        //Creeaza capcane
        void GenerateTraps();

        //Main Loop
        bool MainLoop(BaseRobot &Robot);

        //returneaza coordonatele urmatoarei pozitii unde se va deplasa robotul
        pair<int,int> getNextMove(pair<int,int>*pairs,int nrOfPairs,const BaseRobot &Robot)const;
};

#endif // GAME_H
