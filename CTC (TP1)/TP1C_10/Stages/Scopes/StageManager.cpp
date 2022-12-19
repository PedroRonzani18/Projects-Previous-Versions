#include "../Header/StageManager.h"
#include <stdio.h>
#include <iostream>

using namespace std;

StageManager::StageManager(){}

void StageManager::initializeStages(){
    Menu menu;
    Ajuda ajuda;
    Level level1;
    Player player;

    //level1.addEntity(player);

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


void StageManager::menuKeyboardManager()
{
    int auxFocus = this->getCurrentStage().getFocusButton().getFunctionality();
  
    if(flag)
    {
        if(keys[0])
        {
            flag=0;
            printf("cima dentro do menu\n");
            if(auxFocus > 1)
                this->getCurrentStage().getFocusButton().setFunctionality(auxFocus - 1);
            else
                this->getCurrentStage().getFocusButton().setFunctionality(this->currentStage.getAmmountOfButtons());

            //printf("AuxFocus: %d\n", this->getCurrentStage().getFocusButton().getFunctionality());
        }

        if(keys[1])
        {
            flag=0;
            printf("baixo dentro do menu\n");
            if(auxFocus < this->currentStage.getAmmountOfButtons())
                this->getCurrentStage().getFocusButton().setFunctionality(auxFocus + 1);
            else
                this->getCurrentStage().getFocusButton().setFunctionality(1);
                
            //printf("AuxFocus: %d\n", this->getCurrentStage().getFocusButton().getFunctionality());
        }



        if(keys[4])
        {
            printf("space dentro do menu\n");
            flag=0;
            
            switch(this->getCurrentStage().getFocusButton().getFunctionality())
            {
                case 1: // LEVEL
                    printf("Entrei no level\n");
                    this->setCurrentStage(stagesList[2]);
                    
                    break;
                
                case 2: // AJUDA
                    printf("Entrei na ajuda\n");
                    this->setCurrentStage(stagesList[1]);
                    break;
            }
        }
    }     
}

void StageManager::ajudaKeyboardManager()
{
    if(keys[4]) // volta para o menu
    {
        this->setCurrentStage(this->stagesList[0]); 
    }
}

void StageManager::levelKeyboardManager()
{
}

void StageManager::stageKeyboard()
{

    
    //printf("entre na stageKeyboardGERAL\n");

    Menu *menu;

    //cout << typeid(&currentStage).name() << endl;

    if(typeid(&currentStage) == typeid(menu)){
        printf("asfgernbvr");
    }

    if(instanceof<Menu>(&currentStage))
    {
        printf("entre na stageKeyboardMenu\n");
        menuKeyboardManager();
        //função keyboard para movimentar nos botoes
        // em algum dado momento vai colocar currentstage.set(Ajuda) ou currentstage.(Level)
    }

    if(instanceof<Ajuda>(&currentStage))
    {
                printf("entre na stageKeyboardAjuda\n");

        ajudaKeyboardManager();
    }

    if(instanceof<Level>(&currentStage))
    {
                printf("entre na stageKeyboardLevel\n");

        levelKeyboardManager();
    }
    
}