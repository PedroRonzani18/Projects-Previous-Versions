#include "../Header/StageManager.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

StageManager::StageManager()
{

    this->currentLevel = 0;
    
    Ajuda *auxA = new Ajuda();
    this->ajuda = auxA;

    Menu *menuA = new Menu();
    this->menu = menuA;

    Level *levelA = new Level(0);
    this->level = levelA;
    
}

void StageManager::initLevel()
{
    Level level(this->currentLevel);
    this->setCurrentStage(reinterpret_cast<Stage*>(&level));
    currentStage = &level;
    this->currentLevel++;
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
    
    
    switch(auxStageIndicator)
    {
        case 0:
            this->setCurrentStage(reinterpret_cast<Stage*>(menu));
            this->currentLevel = 0;
            break;
        case 1:
            this->setCurrentStage(reinterpret_cast<Stage*>(ajuda));
            break;
        case 2:
            initLevel();
            break;
        
    }
    
}

void StageManager::gameInit()
{
    glClearColor(0, 0, 0, 1); 

    initializeTextures();    //carrega texturas a usar

    this->setCurrentStage(reinterpret_cast<Stage*>(menu));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}