#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{
    
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    

}

char GameMechs::getInput()
{
    if(MacUILib_hasChar()) {

        return MacUILib_getChar();

    }
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{

}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}


