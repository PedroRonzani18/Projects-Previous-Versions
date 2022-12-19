#include "desenhos.h"
#include "inicializa.h"
#include "parametros.h"

using namespace std;

void listaStructsEntidades()
{
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
    };

    entityList.push_back(player);
    entityList.push_back(player);

    entityList[1].ladoHorizontal = 1;
    entityList[1].ladoVertical = 1;
    entityList[1].x_move = 1;
    entityList[1].y_move = 0;

    entidade aviao1Struct = {
        .x_max = 35, .x_min = -30,
        .y_max = 17.5, .y_min = -11.5,
        .x_move = 1, .y_move = 0,
        .ladoHorizontal = -1, .ladoVertical = 0,
        .onScreen = GL_TRUE, 
        .model = aviaoDisplayList1,
        .drawHitbox = GL_TRUE
    };

    entityList.push_back(aviao1Struct);
    entityList.push_back(aviao1Struct);

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

    entityList.push_back(aviao2Struct);
    entityList.push_back(aviao2Struct);
}

void listaStructsShots()
{
    entidade defaultShot ={
        .x_max = 3.5, .x_min = -3.5,
        .y_max = 3.5, .y_min = -3.5,
        .x_move = 1, .y_move = 1,
        .resize = 0.9,
        .angularSpeed = 1,
        .vetorialSpeed = 1,
        .angulo = 0,
        .onScreen = GL_TRUE, 
        .model = shotDisplayList,
        .bulletSpeed = 2,
        .continuar = 1,
        .drawHitbox = GL_TRUE
    };


    //arruma a escala ddo shot
    defaultShot.x_max *= defaultShot.resize.x;
    defaultShot.x_min *= defaultShot.resize.x;

    defaultShot.y_max *= defaultShot.resize.y;
    defaultShot.y_min *= defaultShot.resize.y;

    //arruma a hitbox do shot
    defaultShot.hitbox[0].x = defaultShot.x_max;
    defaultShot.hitbox[0].y = defaultShot.y_max;
    defaultShot.hitbox[1].x = defaultShot.x_min;
    defaultShot.hitbox[1].y = defaultShot.y_max;
    defaultShot.hitbox[2].x = defaultShot.x_min;
    defaultShot.hitbox[2].y = defaultShot.y_min;
    defaultShot.hitbox[3].x = defaultShot.x_max;
    defaultShot.hitbox[3].y = defaultShot.y_min;
    

    shotsList.push_back(defaultShot);
    //shotsList.push_back(defaultShot);
    //quando arrumar erro de entrar 2 vezes, eu coloco como 2
}

void inicializaDisplayLists()
{
    aviaoDisplayList = glGenLists(1);
    aviaoDisplayList1 = glGenLists(2);
    aviaoDisplayList2 = glGenLists(3);
    shotDisplayList = glGenLists(4);

    listaStructsEntidades();
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

void posicaoInicialJogador()
{
    entityList[0].centro.x = (entityList[0].x_max + entityList[0].x_min)/2;
    entityList[0].centro.y = (entityList[0].y_max + entityList[0].y_min)/2;
    entityList[0].angulo = 0;

    entityList[0].angulo = 90;

    entityList[0].centro.x +=  0;
    entityList[0].centro.y += -70;
}

void posicaoInicialInimigos()
{
    for(int i=1; i<6; i++)
    {
        entityList[i].centro.x = (entityList[i].x_max + entityList[i].x_min)/2;
        entityList[i].centro.y = (entityList[i].y_max + entityList[i].y_min)/2;
        entityList[i].angulo = 0;
    }

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
    entityList[5].centro.y += 0;
}

/*
void posicaoInicialShots()
{
    for(int i=0; i<shotsList.size(); i++){
        shotsList[i].centro.x = entityList[0].centro.x;
        shotsList[i].centro.y = entityList[0].centro.y;
        shotsList[i].angulo = 0;   
        shotsList[i].continuar = 1;
    }

    shotsList[0].centro.x += 10;
    shotsList[0].centro.y += 20;

    shotsList[1].centro.x += -10;
    shotsList[1].centro.y += 20;
}
*/
void inicializaOnScreen()
{
    for(int i=0; i < entityList.size(); i++)
        entityList[i].onScreen = GL_TRUE;

    for(int i=0; i< shotsList.size(); i++)
        shotsList[i].onScreen = GL_TRUE;

}

void inicializaPosicoes()
{
    posicaoInicialJogador();
    posicaoInicialInimigos();
    //posicaoInicialShots();
}

void inicializaEscala()
{
    for(int i=0; i<entityList.size(); i++)
    {
        entityList[i].resize.x = 0.5;
        entityList[i].resize.y = 0.5;

        entityList[i].x_max *= entityList[i].resize.x;
        entityList[i].x_min *= entityList[i].resize.x;

        entityList[i].y_max *= entityList[i].resize.y;
        entityList[i].y_min *= entityList[i].resize.y;
    }

/*
    for(int i=0; i<shotsList.size(); i++)
    {
        shotsList[i].resize.x = 0.9;
        shotsList[i].resize.y = 0.9;

        shotsList[i].x_max *= shotsList[i].resize.x;
        shotsList[i].x_min *= shotsList[i].resize.x;

        shotsList[i].y_max *= shotsList[i].resize.y;
        shotsList[i].y_min *= shotsList[i].resize.y;
    }*/
}

void inicializaHitbox()
{
    for(int i=0; i<entityList.size(); i++){
        entityList[i].hitbox[0].x = entityList[i].x_max;
        entityList[i].hitbox[0].y = entityList[i].y_max;
        entityList[i].hitbox[1].x = entityList[i].x_min;
        entityList[i].hitbox[1].y = entityList[i].y_max;
        entityList[i].hitbox[2].x = entityList[i].x_min;
        entityList[i].hitbox[2].y = entityList[i].y_min;
        entityList[i].hitbox[3].x = entityList[i].x_max;
        entityList[i].hitbox[3].y = entityList[i].y_min;
    }

    for(int i=0; i<shotsList.size(); i++){
        shotsList[i].hitbox[0].x = shotsList[i].x_max;
        shotsList[i].hitbox[0].y = shotsList[i].y_max;
        shotsList[i].hitbox[1].x = shotsList[i].x_min;
        shotsList[i].hitbox[1].y = shotsList[i].y_max;
        shotsList[i].hitbox[2].x = shotsList[i].x_min;
        shotsList[i].hitbox[2].y = shotsList[i].y_min;
        shotsList[i].hitbox[3].x = shotsList[i].x_max;
        shotsList[i].hitbox[3].y = shotsList[i].y_min;
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