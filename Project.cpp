#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "Food.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

// declare pointer variables
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
        if(thisGMRef->getExitFlagStatus())
        {
            break;
        }
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    
    // initialize variable on the heap
    thisGMRef = new GameMechs(30, 15);
    food = new Food(thisGMRef);
    player = new Player(thisGMRef, food);


}

void GetInput(void)
{
   

}

void RunLogic(void)
{

    player->updatePlayerDir();
    player->movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // declare variables for drawing
    int x, y;
    bool flag;

    int boardX = thisGMRef->getBoardSizeX();
    int boardY = thisGMRef->getBoardSizeY();

    objPosArrayList* playerBody = player->getPlayerPos();
    objPos currentSegment;
    objPos foodPos;
    
    food->getFoodPos(foodPos);

    // draw the board with the specified vertical and horizontal lengths (x and y)
    for(y = 0; y < boardY; y++) {
        for(x = 0; x < boardX; x++) {

            flag = false;

            // iterate through every element in the player body (list)
            for(int k = 0; k < playerBody->getSize(); k++) {
                playerBody->getElement(currentSegment,k);

                // compare the coordinates, and print the body of the player/snake accordingly
                if((currentSegment.x == x) && (currentSegment.y == y)) {
                    MacUILib_printf("%c", currentSegment.symbol);
                    flag = true;
                    break;
                }
            }

            if(flag){
                continue;
            }

            // draw the food at it's randomly generated location
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
    
    MacUILib_printf("Score: %d", thisGMRef->getScore());
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

    delete player;
    delete thisGMRef;
    delete food;
  
    MacUILib_uninit();

}
