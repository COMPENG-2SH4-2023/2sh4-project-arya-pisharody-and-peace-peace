#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "Food.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000


Player* player;
GameMechs* thisGMRef;
Food* food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(thisGMRef->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    
    thisGMRef = new GameMechs(30, 15);
    food = new Food(thisGMRef);
    player = new Player(thisGMRef, food);

    // objPos blockOffPos;
    // objPos currentPos;
    // player->getPlayerPos()->getHeadElement(currentPos);
    // blockOffPos = objPos(-1, -1, 'o');
    // blockOffPos = objPos(currentPos.x, currentPos.y, currentPos.symbol);

    // food->generateFood(blockOffPos);


}

void GetInput(void)
{
   

}

void RunLogic(void)
{

    // char collision_symbol;

    // objPos blockOffPos;
    // objPos currentPos;
    // objPos foodPos;

    // player->getPlayerPos()->getHeadElement(currentPos);
    // food->getFoodPos(foodPos);
    // blockOffPos = objPos(currentPos.x, currentPos.y, currentPos.symbol);

    player->updatePlayerDir();
    player->movePlayer();
    // thisGMRef->clearInput();

    // // check for collision
    // if((currentPos.x == foodPos.x)&&(currentPos.y == foodPos.y)) {
    //     food->generateFood(blockOffPos);
    // }

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // x = rows, y = columns
    int x, y;
    bool flag;

    int boardX = thisGMRef->getBoardSizeX();
    int boardY = thisGMRef->getBoardSizeY();

    objPosArrayList* playerBody = player->getPlayerPos();
    objPos currentSegment;
    objPos foodPos;
    
    food->getFoodPos(foodPos);

    for(y = 0; y < boardY; y++) {
        for(x = 0; x < boardX; x++) {

            flag = false;

            for(int k = 0; k < playerBody->getSize(); k++) {
                playerBody->getElement(currentSegment,k);

                if((currentSegment.x == x) && (currentSegment.y == y)) {
                    MacUILib_printf("%c", currentSegment.symbol);
                    flag = true;
                    break;
                }
            }

            if(flag){
                continue;
            }

            if((x == foodPos.x) && (y == foodPos.y)) {
                MacUILib_printf("%c", foodPos.symbol);
                
            } else {

                if((y == 0) || (y == (boardY-1))) {
                    MacUILib_printf("#");

                } else if ((y != 0) || (y != (boardY-1))) {

                    if((x == 0) || (x == (boardX-1))) {
                        MacUILib_printf("#");
                    } else {
                        MacUILib_printf(" ");
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Food pos: (%d,%d)\n", foodPos.x, foodPos.y);
    MacUILib_printf("Score: %d", thisGMRef->getScore());
    // MacUILib_printf("Player head position: (%d, %d)", playerBody->getElement(currentSegment, 0)->x, playerBody->getHeadElement()->y);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if(thisGMRef->getLoseFlagStatus())
    {
        MacUILib_printf("Game Ended. You Scored: %d", thisGMRef->getScore());
    }
  
    MacUILib_uninit();

}
