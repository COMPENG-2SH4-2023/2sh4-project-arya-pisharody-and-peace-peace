#include "Food.h"
#include <time.h>

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
    objPos currentSegment;

    bool valid = false;

    while (valid == false) {
        a = (rand() % boardX) +1;
        b = (rand() % boardY) +1;

        for(int k = 0; k < playerBody->getSize(); k++) {
            valid = true;
            playerBody->getElement(currentSegment,k);

            if (a == currentSegment.x && b == currentSegment.y) {
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