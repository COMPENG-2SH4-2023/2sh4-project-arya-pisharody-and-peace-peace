#ifndef FOOD_H
#define FOOD_H

#include "objPosArrayList.h"
#include "GameMechs.h"
#include "objPos.h"
#include <time.h>

class Food
{

    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
        int boardX;
        int boardY;
        int a;
        int b;
        char symb;

        bool valid;


    public:

        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff, objPosArrayList* playerBody);
        void getFoodPos(objPos &returnPos);


};

#endif