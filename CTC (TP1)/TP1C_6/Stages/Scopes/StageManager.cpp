#include "../Header/StageManager.h"
#include <stdio.h>

StageManager::StageManager()
{
    this->state = 0;
}

Stage& StageManager::getCurrentStage()
{
    return currentStage;
}
void StageManager::setCurrentStage(Stage& currentStage)
{
    this->currentStage = currentStage;
}

int StageManager::getState()
{
return this->state;
}
void StageManager::setState(int state)
{
this->state = state;
}





int StageManager::gameOverVerify()
{
    return 0;
}

int StageManager::colision()
{
    for(int i=0; i< this->currentStage.getEntities().size(); i++)
    {
        for(int j = this->currentStage.getEntities().size(); j>i; j--)
        {
            if(colided(&this->currentStage.getEntity(i), &this->currentStage.getEntity(i)))
                return 1;

            //if(colisaoGeral(&entityList[0],&entityList[i]))
        }
    }
    return 0;
}

void inicializaDisplayLists()
{
    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);
    shotDisplayList = glGenLists(4);

    //listaStructsEntidades();
    //listaStructsShots();

    glNewList(aviaoDisplayList, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList"
        desenhaPlayer();
    glEndList();

    glNewList(aviaoDisplayList1, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList1"
        drawPlane1();
    glEndList();

    glNewList(aviaoDisplayList2, GL_COMPILE); // declaro o que está dentro da lista e chamo ela de "aviaoDisplayList2"
        drawPlane2();
    glEndList();

    glNewList(shotDisplayList, GL_COMPILE);
        drawShot();
    glEndList();
}

void StageManager::initializePlayer()
{
    // coloca player no vector
    Player* player = new Player();
    
    this->currentStage.addEntity(*player);

    // define sua posição inicial
    this->currentStage.getEntity(0).setMidPoint(currentStage.getEntity(0).getMidPoint().getX() + (  0),
                                                 currentStage.getEntity(0).getMidPoint().getY() + (-70));
}

void StageManager::gameInit()
{
    //cria um player com os valores default definidos previamente no constructor
    inicializaDisplayLists();    
    initializePlayer();

    // Define a cor do fundo como 'ciano'
    glClearColor(0.60, 0.847, 0.93, 6); 
}