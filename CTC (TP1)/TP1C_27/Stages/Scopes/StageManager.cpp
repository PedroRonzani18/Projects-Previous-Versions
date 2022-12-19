#include "../Header/StageManager.h"
#include <stdio.h>

StageManager::StageManager(){}

void StageManager::draw(){
    currentStage->drawEntities();    
}

void StageManager::initializeStages()
{
    Menu *menu = new Menu();
    Ajuda *ajuda = new Ajuda();
    Level *level1 = new Level();
    level1->addWave(1);

    stagesList.push_back(menu);
    stagesList.push_back(ajuda);
    stagesList.push_back(level1);

    this->setCurrentStage(menu);
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
    initializeStages();

    glClearColor(0, 0, 0, 0); 
}

void StageManager::callWave()
{
    currentStage->callWaves();
}

void StageManager::keyboardOfStage()
{
    this->setCurrentStage(stagesList[(*currentStage).stageKeyboard()]);
}