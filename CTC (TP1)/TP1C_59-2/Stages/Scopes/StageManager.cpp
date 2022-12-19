#include "../Header/StageManager.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

StageManager::StageManager(){}

void StageManager::initLevel(int num)
{
    std::vector<int> auxWaves;
    Level *level = new Level();
    switch(num)
    {
        case 1:
            level->initBackgrounds(0);
            auxWaves = {1, 2, 3, 4, 5};
            level->addWaves(auxWaves);
            stagesList.push_back(level);
            currentStage = level;
            break;
            
        case 2:
            level->initBackgrounds(0);
            auxWaves = {1, 2, 3, 4, 5};
            level->addWaves(auxWaves);
            stagesList.push_back(level);
            currentStage = level;
            break;
    }
}

void StageManager::initializeStages()
{
    Menu *menu = new Menu();
    stagesList.push_back(menu);

    Ajuda *ajuda = new Ajuda();    
    stagesList.push_back(ajuda);

    initLevel(1);
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
            case -1:  // morreu dentro do level1
                this->setCurrentStage(stagesList[1]); // volta para o menu
                stagesList.pop_back(); initLevel(1); // recria level1
                break;
            case -2: // acabou o level1
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