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
    
    Button auxFocusButton = reinterpret_cast<Menu*> (&this->currentStage)->getFocusButton();
    
    if(flag)
    {
        if(keys[0])
        {
            flag=0;
            printf("cima\n");

            if(auxFocusButton.getFunctionality() > 1)
                auxFocusButton.setFunctionality(auxFocusButton.getFunctionality() - 1);
            else
                auxFocusButton.setFunctionality(this->currentStage.getAmmountOfButtons());
        }

        if(keys[1])
        {
            flag=0;
            printf("baixo\n");

            if(auxFocusButton.getFunctionality() < this->currentStage.getAmmountOfButtons())
                auxFocusButton.setFunctionality(auxFocusButton.getFunctionality() + 1);
            else
                auxFocusButton.setFunctionality(1);
        }

        if(keys[4])
        {
            flag=0;
            printf("space\n");
            switch (auxFocusButton.getFunctionality())
            {
                case 1: // LEVEL
                    printf("Entrei no level");
                    this->setCurrentStage(stagesList[2]);
                    
                    break;
                
                case 2: // AJUDA
                    printf("Entrei na ajuda");
                    this->setCurrentStage(stagesList[1]);
                    break;
            }
        }
    }   

    




/*
    int auxFocus = this->currentStage.getFocus();

    if(flag)
    {
        if(keys[0])
        {
            flag=0;
            printf("cima\n");
            if(auxFocus > 1)
                this->currentStage.setFocus(auxFocus - 1);
            else
                this->currentStage.setFocus(this->currentStage.getAmmountOfButtons());
            
        }

        if(keys[1])
        {
            flag=0;
            printf("baixo\n");
            if(auxFocus < this->currentStage.getAmmountOfButtons())
                this->currentStage.setFocus(auxFocus + 1);
            else
                this->currentStage.setFocus(1);
        }

        if(keys[4])
        {
            flag=0;
            printf("space\n");
            switch (auxFocus)
            {
                case 1: // LEVEL
                    printf("Entrei no level");
                    this->setCurrentStage(stagesList[2]);
                    
                    break;
                
                case 2: // AJUDA
                    printf("Entrei na ajuda");
                    this->setCurrentStage(stagesList[1]);
                    break;
            }
        }
    }
*/

    
    /*
    if(keys[0]) // cima
    {
        printf("cima\n");
        if(auxFocus > 1)
            this->currentStage.setFocus(auxFocus - 1);
        else
            this->currentStage.setFocus(this->currentStage.getAmmountOfButtons());
    }

    if(keys[1]) // baixo
    {
        printf("baixo\n");
        if(auxFocus < this->currentStage.getAmmountOfButtons())
            this->currentStage.setFocus(auxFocus+ 1);
        else
            this->currentStage.setFocus(1);
    }
    */
   /*
    if(keys[4]) // space
    {
        printf("space\n");
        //implementar o que acontece quando clica no botao com "functionality" igual a "this->getFocus()"
        switch (auxFocus)
        {
            case 1: // LEVEL
                printf("Entrei no level");
                this->setCurrentStage(stagesList[2]);
                break;
            
            case 2: // AJUDA
                printf("Entrei na ajuda");
                this->setCurrentStage(stagesList[1]);
                break;
        }
    }
    */
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
    printf("entre na stageKeyboardGERAL\n");
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