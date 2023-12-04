#include "Food.h"
#include <time.h>

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    // mainGameMechsRef = &thisGMRef;
    foodPos.x = 10;
    foodPos.y = 10;
    foodPos.symbol = 'o';
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    int a, b;
    char symb = 'o';

    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    while (1) {
        a = (rand() % boardX) +1;
        b = (rand() % boardY) +1;

        if (a != blockOff.x && b != blockOff.y) {
            foodPos.x = a;
            foodPos.y = b;
            foodPos.symbol = symb;
            break;
        }
    }
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}