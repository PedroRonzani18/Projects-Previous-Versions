#include "../Header/StageManager.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

StageManager::StageManager(){}

void StageManager::initLevel1()
{
    Level *level1 = new Level();
    level1->initBackgrounds(0);
    std::vector<int> auxWaves = {1, 2, 3, 4, 5};
    level1->addWaves(auxWaves);
    stagesList.push_back(level1);
    currentStage = level1;
}

void StageManager::initializeStages()
{
    Menu *menu = new Menu();
    Ajuda *ajuda = new Ajuda();
    
    
    stagesList.push_back(menu);
    stagesList.push_back(ajuda);

    //stagesList.push_back(level1);

    this->setCurrentStage(menu);
}

int StageManager::gameOverVerify()
{
    return 0;
}

void StageManager::movements()
{
    currentStage->drawAndMove();
}

void StageManager::colision()
{
     currentStage->colider();
}

void StageManager::timer()
{
    currentStage->timeCounter();
}

void StageManager::callWave()
{
    currentStage->callWaves();
}

void StageManager::keyboardOfStage()
{
    int auxStageIndicator = currentStage->stageKeyboard();
    
    printf("AUX: %d\n",auxStageIndicator);

    if(auxStageIndicator >= 0){
        this->setCurrentStage(stagesList[auxStageIndicator]);
    }
    else
    {
        switch(auxStageIndicator)
        {
            case -1:
                initLevel1();
                break;
            case -2:
                break;
        }
    }
}

void StageManager::gameInit()
{
    glClearColor(0, 0, 0, 1); 

    initializeTextures();    //carrega texturas a usar

    initializeStages();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}