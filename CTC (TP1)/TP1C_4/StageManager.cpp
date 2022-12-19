#include "StageManager.h"

int StageManager::colision()
{
    for(int i=0; i< this->currentStage.getEntities()->size(); i++)
    {
        for(int j = this->currentStage.getEntities()->size(); j>i; j--)
        {
            if(colided(this->currentStage.getEntity(i), this->currentStage.getEntity(i)))
                return 1;
        }
    }
    return 0;
}


int StageManager::getState(){

return this->state;

};

void StageManager::setState(int state){

this->state = state;

};

int StageManager::gameOverVerify(){return 0;}

void StageManager::gameInit()
{
    Player p;
    this->currentStage.addEntity(&p);
}