#include "Food.h"
#include <stdlib.h>
#include <time.h>

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    boardX = mainGameMechsRef->getBoardSizeX();
    boardY = mainGameMechsRef->getBoardSizeY();

    // generate a random starting position for the food
    foodPos.x = (rand() % (boardX-2)) +1;
    foodPos.y = (rand() % (boardY-2)) +1;
    foodPos.symbol = 'o';
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff, objPosArrayList* playerBody)
{
    srand(time(NULL));
    int a, b;
    char symb = 'o';

    bool valid = false;

    // Continue randomly generating food while the flag variable is false
    while (valid == false) {
        a = (rand() % (boardX-2)) +1;
        b = (rand() % (boardY-2)) +1;

        // ensure the food is not generated on top of the player body
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