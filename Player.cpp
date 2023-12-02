#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5, 11, '*');
}


Player::~Player()
{
    // delete any heap members here
    
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    char input = mainGameMechsRef->getInput();

    switch(input) {
        case ' ':  // exit
            mainGameMechsRef->setExitTrue();
            break;
        case 'w':
            if(myDir != DOWN) {
                myDir = UP;
            }
            break;
        
        case 'a':
            if(myDir != RIGHT) {
                myDir = LEFT;
            }
            
            break;

        case 's':
        if(myDir != UP) {
            myDir = DOWN;
        }
            break;
        
        case 'd':
            if(myDir != LEFT) {
                myDir = RIGHT;
            }
            break;
        default:
        // MacUILib_printf("STOP");
            break;
    }
}

void Player::movePlayer()
{
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();
    
    // PPA3 Finite State Machine logic
    switch(myDir) {
        case UP:
            if(playerPos.x == 0) {
                playerPos.x = boardX;
            }
            playerPos.x--;
            break;
        
        case LEFT:
            if(playerPos.y == 0) {
                playerPos.y = boardY;
            }
            playerPos.y--;
            break;

        case DOWN:
            if(playerPos.x == boardX) {
                playerPos.x = 0;
            }
            playerPos.x++;
            break;

        case RIGHT:
            if(playerPos.y == boardY) {
                playerPos.y = 0;
            }
            playerPos.y++;
            break;

        default:
            break;

    }
}

