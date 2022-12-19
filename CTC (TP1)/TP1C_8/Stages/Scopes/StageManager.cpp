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

    this->setCurrentStage(this->stagesList[0]);
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
/*
void inicializaDisplayLists()
{
    //aviaoDisplayList = glGenLists(1);
    //printf("Display 1: %d\n",aviaoDisplayList);
    
    // aviaoDisplayList1 = glGenLists(2);
    // printf("Display 2: %d\n",aviaoDisplayList1);

    // aviaoDisplayList2 = glGenLists(3);
    // printf("Display 3: %d\n",aviaoDisplayList2);

    // shotDisplayList = glGenLists(4);
    // printf("Display 4: %d\n",shotDisplayList);

    buttonDisplayList = glGenLists(5);
    printf("Display 5: %d\n",buttonDisplayList);


    //listaStructsEntidades();
    //listaStructsShots();

    //glNewList(aviaoDisplayList, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList"
    //    desenhaPlayer();
    //glEndList();

    // glNewList(aviaoDisplayList1, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList1"
    //     drawPlane1();
    // glEndList();

    // glNewList(aviaoDisplayList2, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList2"
    //     drawPlane2();
    // glEndList();

    // glNewList(shotDisplayList, GL_COMPILE);
    //     drawShot();
    // glEndList();

    glNewList(buttonDisplayList, GL_COMPILE);
        drawMenuButton();
    glEndList();
}
*/
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
    int auxFocus = this->currentStage.getFocus();
    /*
    if(keys[0]==1 && flag==1){
        flag=0;
        if (sposition == -30){
                sposition = -40;
            }
            else{
                sposition = -30;
            }
    }

    if(keys[1]==1 && flag==1){
        flag=0;
        if (sposition == -40){
            sposition = -30;
        }
        else{
            sposition = -40;
        }
    }
    */
    if(keys[0]) // cima
    {
        if(auxFocus > 1)
            this->currentStage.setFocus(auxFocus - 1);
        else
            this->currentStage.setFocus(this->currentStage.getAmmountOfButtons());
    }

    if(keys[1]) // baixo
    {
        if(auxFocus < this->currentStage.getAmmountOfButtons())
            this->currentStage.setFocus(auxFocus+ 1);
        else
            this->currentStage.setFocus(1);
    }
    if(keys[4]) // space
    {
        //implementar o que acontece quando clica no botao com "functionality" igual a "this->getFocus()"
        switch (auxFocus)
        {
            case 1: // LEVEL
                this->setCurrentStage(stagesList[2]);
                break;
            
            case 2: // AJUDA
                this->setCurrentStage(stagesList[1]);
                break;
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
    Player *auxP = reinterpret_cast<Player*>(&currentStage.getEntity(0));

    if(keys[0]){ //cima
        auxP->getMidPoint().setX(auxP->getMidPoint().getX() + auxP->getVelocity().getX());
    }
    if(keys[1]){ //baixo
        auxP->getMidPoint().setX(auxP->getMidPoint().getX() - auxP->getVelocity().getX());
    }
    if(keys[2]){ //direita
        auxP->getMidPoint().setY(auxP->getMidPoint().getY() + auxP->getVelocity().getY());
    }
    if(keys[3]){ //esquerda
        auxP->getMidPoint().setY(auxP->getMidPoint().getY() - auxP->getVelocity().getY());
    }
    if(keys[4]){ //space
        this->currentStage.addEntity(auxP->fire()); // adiciona tiro a lista de entity
    }
}

void StageManager::stageKeyboard()
{
    if(instanceof<Menu>(&currentStage))
    {
        menuKeyboardManager();
        //função keyboard para movimentar nos botoes
        // em algum dado momento vai colocar currentstage.set(Ajuda) ou currentstage.(Level)
    }

    if(instanceof<Ajuda>(&currentStage))
    {
        ajudaKeyboardManager();
    }

    if(instanceof<Level>(&currentStage))
    {
        levelKeyboardManager();
    }
}