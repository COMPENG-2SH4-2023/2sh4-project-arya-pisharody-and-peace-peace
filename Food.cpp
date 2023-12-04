#include "Food.h"
#include <stdlib.h>

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos.x = 10;
    foodPos.y = 10;
    foodPos.symbol = 'o';
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff, objPosArrayList* playerBody)
{
    int a, b;
    char symb = 'o';

    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    bool valid = false;

    while (valid == false) {
        a = (rand() % boardX-2) +1;
        b = (rand() % boardY-2) +1;

        for(int k = 0; k < playerBody->getSize(); k++) {
            valid = true;
            playerBody->getElement(blockOff,k);

            if (a == blockOff.x && b == blockOff.y) {
                valid = false;
                break;
            }    
        }
    }
    foodPos.x = a;
    foodPos.y = b;
    foodPos.symbol = symb;
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}