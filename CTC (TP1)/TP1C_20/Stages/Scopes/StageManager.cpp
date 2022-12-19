#include "../Header/StageManager.h"
#include <stdio.h>

StageManager::StageManager()
{
}

void StageManager::draw(){
    currentStage->drawEntities();
}

void StageManager::initializeStages(){
    Menu *menu = new Menu();
    Ajuda *ajuda = new Ajuda();
    Level *level1 = new Level();
    Player player;

    stagesList.push_back(menu);
    stagesList.push_back(ajuda);
    stagesList.push_back(level1);

    this->setCurrentStage(menu);
}

int StageManager::gameOverVerify()
{
    return 0;
}

int StageManager::colision()
{
    return 0;
}

void StageManager::gameInit()
{
    initializeStages();

    glClearColor(0, 0, 0, 0); 
}

void StageManager::keyboardOfStage()
{
    this->setCurrentStage(stagesList[(*currentStage).stageKeyboard()]);
}