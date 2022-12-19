#include "../Header/StageManager.h"
#include "../../GeneralFiles/Header/drawings.h"
#include <stdio.h>

StageManager::StageManager(){}

void StageManager::draw()
{
    currentStage->drawEntities();    
}

void StageManager::initializeStages()
{
    Menu *menu = new Menu();
    Ajuda *ajuda = new Ajuda();
    Level *level1 = new Level();

    level1->addWave(1);
    level1->addWave(1);
    level1->addWave(1);

    stagesList.push_back(menu);
    stagesList.push_back(ajuda);
    stagesList.push_back(level1);

    this->setCurrentStage(menu);
}

void StageManager::removeVerify()
{
    currentStage->remover();
}

int StageManager::gameOverVerify()
{
    return 0;
}

void StageManager::movements()
{
    currentStage->movements();
}

void StageManager::colision()
{
    currentStage->colider();
}

void StageManager::gameInit()
{
    glClearColor(0, 0, 0, 1); 

    initializeTextures();    //carrega texturas a usar

    initializeStages();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void StageManager::callWave()
{
    currentStage->callWaves();
}

void StageManager::keyboardOfStage()
{
    this->setCurrentStage(stagesList[(*currentStage).stageKeyboard()]);
}