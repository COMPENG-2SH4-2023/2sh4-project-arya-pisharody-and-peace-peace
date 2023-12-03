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
    
    thisGMRef = new GameMechs(15, 30);
    food = new Food(*thisGMRef);
    player = new Player(thisGMRef);


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

    // x = rows, y = columns
    int x, y;

    objPos currentPos;
    int boardX = thisGMRef->getBoardSizeX();
    int boardY = thisGMRef->getBoardSizeY();

    for(x = 0; x < boardX; x++) {
        for(y = 0; y < boardY; y++) {

            player->getPlayerPos(currentPos);
            food->getFoodPos(currentPos);

            if((x == currentPos.x) && (y == currentPos.y)){
                MacUILib_printf("%c", currentPos.symbol);
            } else {

                if((x == 0) || (x == (boardX-1))) {
                    MacUILib_printf("#");

                } else if ((x != 0) || (x != (boardX-1))) {

                    if((y == 0) || (y == (boardY-1))) {
                        MacUILib_printf("#");
                    } else {
                        MacUILib_printf(" ");
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

}
