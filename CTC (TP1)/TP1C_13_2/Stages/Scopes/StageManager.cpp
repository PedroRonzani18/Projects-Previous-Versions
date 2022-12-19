#include "../Header/StageManager.h"
#include <stdio.h>

StageManager::StageManager()
{
}

void StageManager::initializeStages(){
    Menu menu;
    Ajuda ajuda;
    Level level1;
    Player player;

    //level1.addEntity(player);

    stagesList.push_back(&menu);
    stagesList.push_back(&ajuda);
    stagesList.push_back(&level1);

    this->setCurrentStage(&menu);
}

int StageManager::gameOverVerify()
{
    return 0;
}

int StageManager::colision()
{
    /*
    for(int i=0; i < this->currentStage.getEntities().size(); i++)
    {
        for(int j = this->currentStage.getEntities().size(); j>i; j--)
        {
            if(colided(this->currentStage.getEntity(i), this->currentStage.getEntity(i)))
                return 1;
            //if(colisaoGeral(&entityList[0],&entityList[i]))
        }
    }
    */
    return 0;
}

void StageManager::gameInit()
{
    //cria um player com os valores default definidos previamente no constructor
    //inicializaDisplayLists();    
    initializeStages();

    // Define a cor do fundo como 'ciano'
    glClearColor(0, 0, 0, 0); 
}

void StageManager::levelKeyboardManager()
{
}

void StageManager::stageKeyboard()
{
    //printf("AAAA: %d\n", (*currentStage).stageKeyboard());

    //this->setCurrentStage(stagesList[(*currentStage).stageKeyboard()]);
}