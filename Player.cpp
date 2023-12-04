#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    mainGameFoodRef = foodRef;

    // more actions to be included
    objPos initialPos;
    initialPos.setObjPos(5, 11, '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(initialPos);

    // playerPosList->insertHead(initialPos);
    // playerPosList->insertHead(initialPos);
    // playerPosList->insertHead(initialPos);

    
}


Player::~Player()
{
    delete playerPosList;
    
}

objPosArrayList* Player::getPlayerPos()
{
    
    // return the reference to the playerPos arrray list
    return playerPosList;
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
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
    
    // PPA3 Finite State Machine logic
    switch(myDir) {
        case UP:
            currentHead.y--;
            if(currentHead.y <= 0) {
                currentHead.y = boardY-2;
            }
            break;
        
        case LEFT:
            currentHead.x--;
            if(currentHead.x <= 0) {
                currentHead.x = boardX-2;
            }
            break;

        case DOWN:
            currentHead.y++;
            if(currentHead.y >= boardY-1) {
                currentHead.y = 1;
            }
            break;

        case RIGHT:
            currentHead.x++;
            if(currentHead.x >= boardX-1) {
                currentHead.x = 1;
            }
            break;

        default:
            break;

    }

    if(checkSelfCollision())
    {
        mainGameMechsRef->setExitTrue();
        mainGameMechsRef->setLoseFlag();
    }
    
    objPos blockOff;
    blockOff.setObjPos(currentHead);

    if(checkFoodConsumption()) {
        increasePlayerLength();
        mainGameFoodRef->generateFood(currentHead, playerPosList);
    } else {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }

    
}

bool Player::checkFoodConsumption() {
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
    objPos currentFoodPos;
    mainGameFoodRef->getFoodPos(currentFoodPos);

    if((currentHead.x == currentFoodPos.x) && (currentHead.y == currentFoodPos.y)) {
        return true;
    } else {
        return false;
    }

}

void Player::increasePlayerLength() {
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    playerPosList->insertHead(currentHead);
    mainGameMechsRef->incrementScore();
    
}

bool Player::checkSelfCollision()
{
    objPos currentSegment;
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);


    for(int k = 3; k < playerPosList->getSize(); k++) {

        playerPosList->getElement(currentSegment,k);
        if (currentHead.x == currentSegment.x && currentHead.y == currentSegment.y) {
            return true;
        }    
    }

}
