#include "desenhos.h"
#include "inicializa.h"
#include "parametros.h"

using namespace std;

void listaStructsEntidades()
{
    Entity* player = new Entity();

    player->setX_Max( 20); player->setY_Max( 25);
    player->setX_Min(-20); player->setY_Min(-30);
    player->setX_Move(1); player->setY_Move(1);
    player->setAngularSpeed(2); player->setVetorialSpeed(1);
    player->setAngulo(0);
    player->setOnScreen(GL_TRUE);
    player->setDrawHitbox(GL_TRUE);
    player->setModel(aviaoDisplayList);
    player->setContinuar(0);

    printf("Continuar 1: %d\n",player->continuar);

/*
    entidade player ={
        .x_max = 20, .x_min = -20,
        .y_max = 25, .y_min = -30,
        .x_move = 1, .y_move = 1,
        .angularSpeed = 2,
        .vetorialSpeed = 1,
        .angulo = 0,
        .onScreen = GL_TRUE, 
        .model = aviaoDisplayList,
        .drawHitbox = GL_TRUE
    };*/

    entityList.push_back(*player);
    entityList.push_back(*player);

    entityList[1].setLadoHorizontal(1);
    entityList[1].setLadoHorizontal(1);
    entityList[1].setX_Move(1);
    entityList[1].setY_Move(0);

    Entity* aviao1 = new Entity();

    aviao1->setX_Max( 35); aviao1->setY_Max(17.5);
    aviao1->setX_Min(-30); aviao1->setY_Min(-11.5);
    aviao1->setX_Move(1); aviao1->setY_Move(0);
    aviao1->setLadoHorizontal(-1); aviao1->setLadoVertical(0);
    aviao1->setOnScreen(GL_TRUE);
    aviao1->setDrawHitbox(GL_TRUE);
    aviao1->setModel(aviaoDisplayList1);
    aviao1->setContinuar(0);

/*
    entidade aviao1Struct = {
        .x_max = 35, .x_min = -30,
        .y_max = 17.5, .y_min = -11.5,
        .x_move = 1, .y_move = 0,
        .ladoHorizontal = -1, .ladoVertical = 0,
        .onScreen = GL_TRUE, 
        .model = aviaoDisplayList1,
        .drawHitbox = GL_TRUE
    };
*/

    entityList.push_back(*aviao1);
    entityList.push_back(*aviao1);

    Entity* aviao2 = new Entity();

    aviao2->setX_Max( 22); aviao2->setY_Max(22.5);
    aviao2->setX_Min(-20); aviao2->setY_Min(-10);
    aviao2->setX_Move(0); aviao2->setY_Move(1);
    aviao2->setLadoHorizontal(0); aviao2->setLadoVertical(1);
    aviao2->setOnScreen(GL_TRUE);
    aviao2->setDrawHitbox(GL_TRUE);
    aviao2->setModel(aviaoDisplayList2);
    aviao2->setContinuar(0);

/*
    entidade aviao2Struct = {
        .x_max = 22, .x_min = -20,
        .y_max = 22.5, .y_min = -10,
        .x_move = 0, .y_move = 1,
        .ladoHorizontal = 0,
        .ladoVertical = 1, 
        .onScreen = GL_TRUE, 
        .model = aviaoDisplayList2,
        .drawHitbox = GL_TRUE
    };
*/

    entityList.push_back(*aviao2);
    entityList.push_back(*aviao2);
}

void listaStructsShots()
{
    Entity* defaultShot = new Entity();

    defaultShot->setX_Max( 3.5); defaultShot->setY_Max( 3.5);
    defaultShot->setX_Min(-3.5); defaultShot->setY_Min(-3.5);
    defaultShot->setX_Move(1); defaultShot->setY_Move(1);
    defaultShot->setAngularSpeed(1); defaultShot->setVetorialSpeed(1);
    defaultShot->setAngulo(0); defaultShot->setBulletSpeed(2);
    defaultShot->setOnScreen(GL_TRUE);
    defaultShot->setDrawHitbox(GL_TRUE);
    defaultShot->setModel(shotDisplayList);
    defaultShot->setContinuar(0);

/*
    entidade defaultShot ={
        .x_max = 3.5, .x_min = -3.5,
        .y_max = 3.5, .y_min = -3.5,
        .x_move = 1, .y_move = 1,
        .angularSpeed = 1,
        .vetorialSpeed = 1,
        .angulo = 0,
        .onScreen = GL_TRUE, 
        .model = shotDisplayList,
        .bulletSpeed = 2,
        .continuar = 0,
        .drawHitbox = GL_TRUE
    };*/

    shotsList.push_back(*defaultShot);
    shotsList.push_back(*defaultShot);

}

void inicializaDisplayLists()
{
    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);
    shotDisplayList = glGenLists(4);

    listaStructsEntidades();
    listaStructsShots();

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

void posicaoInicialJogador()
{
    entityList[0].setCentroX((entityList[0].getX_Max() + entityList[0].getX_Min())/2);
    entityList[0].setCentroY((entityList[0].getY_Max() + entityList[0].getY_Min())/2);
    //entityList[0].setAngulo(90);

    entityList[0].setCentroX(entityList[0].getCentroX() + ( 0));
    entityList[0].setCentroY(entityList[0].getCentroY() + (-70));

/*
    entityList[0].centro.x = (entityList[0].x_max + entityList[0].x_min)/2;
    entityList[0].centro.y = (entityList[0].y_max + entityList[0].y_min)/2;
    entityList[0].angulo = 0;

    entityList[0].angulo = 90;

    entityList[0].centro.x +=  0;
    entityList[0].centro.y += -70;*/
}

void posicaoInicialInimigos()
{
    for(int i=1; i<entityList.size(); i++)
    {
        entityList[i].setCentroX((entityList[i].getX_Max() + entityList[i].getX_Min())/2);
        entityList[i].setCentroY((entityList[i].getY_Max() + entityList[i].getY_Min())/2);
        entityList[i].setAngulo(0);

        /*
        entityList[i].centro.x = (entityList[i].x_max + entityList[i].x_min)/2;
        entityList[i].centro.y = (entityList[i].y_max + entityList[i].y_min)/2;
        entityList[i].angulo = 0;*/
    }

    entityList[1].setCentroX(entityList[1].getCentroX() + (-70));
    entityList[1].setCentroY(entityList[1].getCentroY() + ( 70));
    
    entityList[2].setCentroX(entityList[2].getCentroX() + (  0));
    entityList[2].setCentroY(entityList[2].getCentroY() + ( 70));

    entityList[3].setCentroX(entityList[3].getCentroX() + ( 70));
    entityList[3].setCentroY(entityList[3].getCentroY() + ( 70));

    entityList[4].setCentroX(entityList[4].getCentroX() + (-70));
    entityList[4].setCentroY(entityList[4].getCentroY() + (  0));

    entityList[5].setCentroX(entityList[5].getCentroX() + ( 70));
    entityList[5].setCentroY(entityList[5].getCentroY() + (  0));

    /*
    //aviao principal NPC
    entityList[1].centro.x +=  -70;
    entityList[1].centro.y += 70;

    //aviao1_1
    entityList[2].centro.x += 0;
    entityList[2].centro.y += 70;

    //aviao1_2
    entityList[3].centro.x += 70;
    entityList[3].centro.y += 70; 

    //aviao2_1
    entityList[4].centro.x += -70;
    entityList[4].centro.y += 0;

    //aviao2_2
    entityList[5].centro.x += 70;
    entityList[5].centro.y += 0;*/
}

void posicaoInicialShots()
{
    for(int i=0; i<shotsList.size(); i++){

        shotsList[i].setCentroX((entityList[i].getX_Max() + shotsList[i].getX_Min())/2);
        shotsList[i].setCentroY((entityList[i].getY_Max() + shotsList[i].getY_Min())/2);
        shotsList[i].setAngulo(0);
        shotsList[i].setContinuar(0);

/*
        shotsList[i].centro.x = entityList[0].centro.x;
        shotsList[i].centro.y = entityList[0].centro.y;
        shotsList[i].angulo = 0;   
        shotsList[i].continuar = 0;*/
    }

    entityList[0].setCentroX(entityList[0].getCentroX() + ( 10));
    entityList[0].setCentroY(entityList[0].getCentroY() + ( 20));

    entityList[1].setCentroX(entityList[1].getCentroX() + (-10));
    entityList[1].setCentroY(entityList[1].getCentroY() + ( 20));

/*
    shotsList[0].centro.x += 10;
    shotsList[0].centro.y += 20;

    shotsList[1].centro.x += -10;
    shotsList[1].centro.y += 20;*/
}

void inicializaOnScreen()
{
    for(int i=0; i < entityList.size(); i++)
        entityList[i].setOnScreen(GL_TRUE);
        //entityList[i].onScreen = GL_TRUE;

    for(int i=0; i< shotsList.size(); i++)
        shotsList[i].setOnScreen(GL_TRUE);
        //shotsList[i].onScreen = GL_TRUE;

}

void inicializaPosicoes()
{
    posicaoInicialJogador();
    posicaoInicialInimigos();
    posicaoInicialShots();
}

void inicializaEscala()
{
    for(int i=0; i<entityList.size(); i++)
    {
        entityList[i].setResizeX(0.5);
        entityList[i].setResizeY(0.5);

        entityList[i].setX_Max(entityList[i].getX_Max() * entityList[i].getResizeX());
        entityList[i].setX_Min(entityList[i].getX_Min() * entityList[i].getResizeX());

        entityList[i].setY_Max(entityList[i].getY_Max() * entityList[i].getResizeY());
        entityList[i].setY_Min(entityList[i].getY_Min() * entityList[i].getResizeY());

/*
        entityList[i].resize.x = 0.5;
        entityList[i].resize.y = 0.5;

        entityList[i].x_max *= entityList[i].resize.x;
        entityList[i].x_min *= entityList[i].resize.x;

        entityList[i].y_max *= entityList[i].resize.y;
        entityList[i].y_min *= entityList[i].resize.y;*/
    }

    for(int i=0; i<shotsList.size(); i++)
    {

        shotsList[i].setResizeX(0.5);
        shotsList[i].setResizeY(0.5);

        shotsList[i].setX_Max(shotsList[i].getX_Max() * shotsList[i].getResizeX());
        shotsList[i].setX_Min(shotsList[i].getX_Min() * shotsList[i].getResizeX());

        shotsList[i].setY_Max(shotsList[i].getY_Max() * shotsList[i].getResizeY());
        shotsList[i].setY_Min(shotsList[i].getY_Min() * shotsList[i].getResizeY());

/*
        shotsList[i].resize.x = 0.9;
        shotsList[i].resize.y = 0.9;

        shotsList[i].x_max *= shotsList[i].resize.x;
        shotsList[i].x_min *= shotsList[i].resize.x;

        shotsList[i].y_max *= shotsList[i].resize.y;
        shotsList[i].y_min *= shotsList[i].resize.y;*/
    }
}

void inicializaHitbox()
{
    for(int i=0; i<entityList.size(); i++){
        
        vertice auxHitbox[4];
        auxHitbox[0].x = entityList[i].getX_Max();
        auxHitbox[0].y = entityList[i].getY_Max();
        auxHitbox[1].x = entityList[i].getX_Min();
        auxHitbox[1].y = entityList[i].getY_Max();
        auxHitbox[2].x = entityList[i].getX_Min();
        auxHitbox[2].y = entityList[i].getY_Min();
        auxHitbox[3].x = entityList[i].getX_Max();
        auxHitbox[3].y = entityList[i].getY_Min();

        entityList[i].setHitbox(auxHitbox);

/*
        entityList[i].hitbox[0].x = entityList[i].x_max;
        entityList[i].hitbox[0].y = entityList[i].y_max;
        entityList[i].hitbox[1].x = entityList[i].x_min;
        entityList[i].hitbox[1].y = entityList[i].y_max;
        entityList[i].hitbox[2].x = entityList[i].x_min;
        entityList[i].hitbox[2].y = entityList[i].y_min;
        entityList[i].hitbox[3].x = entityList[i].x_max;
        entityList[i].hitbox[3].y = entityList[i].y_min;*/
    }

    for(int i=0; i<shotsList.size(); i++){

        vertice auxHitbox[4];

        auxHitbox[0].x = shotsList[i].getX_Max();
        auxHitbox[0].y = shotsList[i].getY_Max();
        auxHitbox[1].x = shotsList[i].getX_Min();
        auxHitbox[1].y = shotsList[i].getY_Max();
        auxHitbox[2].x = shotsList[i].getX_Min();
        auxHitbox[2].y = shotsList[i].getY_Min();
        auxHitbox[3].x = shotsList[i].getX_Max();
        auxHitbox[3].y = shotsList[i].getY_Min();

        shotsList[i].setHitbox(auxHitbox);
        
        /*
        shotsList[i].hitbox[0].x = shotsList[i].x_max;
        shotsList[i].hitbox[0].y = shotsList[i].y_max;
        shotsList[i].hitbox[1].x = shotsList[i].x_min;
        shotsList[i].hitbox[1].y = shotsList[i].y_max;
        shotsList[i].hitbox[2].x = shotsList[i].x_min;
        shotsList[i].hitbox[2].y = shotsList[i].y_min;
        shotsList[i].hitbox[3].x = shotsList[i].x_max;
        shotsList[i].hitbox[3].y = shotsList[i].y_min;*/
    }
}

void inicializar()
{
    inicializaOnScreen();

    // Cria as displaylists de desenho
    inicializaDisplayLists();

    // Coloca os aviões em suas posições iniciais
    inicializaPosicoes();

    // Define a escala de todas as coordenadas de cada entidade
    inicializaEscala();

    inicializaHitbox();

    // Define a cor do fundo como 'ciano'
    glClearColor(0.60, 0.847, 0.93, 6); 
}