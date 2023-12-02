#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

Player* player;
GameMechs* thisGMRef;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
    
    thisGMRef = new GameMechs();
    player = new Player(thisGMRef);
}

void GetInput(void)
{
    MacUILib_printf("heloo");
//    if (thisGMRef->getInput() == ' ')
//    {
//     thisGMRef->setExitTrue();
//    }
   

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

    for(x = 0; x < 10; x++) {
        for(y = 0; y < 20; y++) {

            player->getPlayerPos(currentPos);

            if((x == currentPos.x) && (y == currentPos.y)){
                MacUILib_printf("%c", currentPos.symbol);
            } else {

                if((x == 0) || (x == 9)) {
                    MacUILib_printf("#");

                } else if ((x != 0) || (x != 9)) {

                    if((y == 0) || (y == 19)) {
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
