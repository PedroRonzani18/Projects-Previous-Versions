#include <GL/freeglut.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

using namespace std;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

/*
    Vetor que idntifica se estão ligadas:
     'w'    's'      'd'       'a'
    cima | baixo | direita | esquerda
          '-'           '+'
*/
GLboolean on_off[6] = {0,0,0,0,0,0};

// ID das displaylists de desenho
GLuint aviaoDisplayList, aviaoDisplayList1, aviaoDisplayList2, shotDisplayList;

// Variavel da razão aspecto da tela.
GLfloat aspectRatio;

// EG = 1: game over.
GLuint endGame = 0;

// Variável que ativa ou desativa o desenho da 'hitbox' de cada entidade.
GLboolean hitBox = true;

typedef struct VERTICE{
    double x,y;
}vertice;

// Struct que contém os dados das entidades.
typedef struct ENTIDADE
{
    double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
    double y_max, y_min; // baseados nas coordenadas extremas do desenho.
    double x_move, y_move; // Unidade de movimento nos eixos x e y ("velocidade" da entidade).
    int ladoHorizontal, ladoVertical; // LH = 1: anda na horizontal. 
                                      // LV = 1: anda na vertical.
    vertice centro;  // Coordenadas do ponto central.
    vertice hitbox[4]; // Modelo de hitbox do objeto
    vertice alteredHitbox[4]; // Modelo alterado por rotação e translação do objeto
    vertice resize; // Escalas de redimensionamento das coordenadas.
    double angularSpeed; // Velocidade angular do objeto
    double vetorialSpeed; // Velocidade vetorial do objeto
    double angulo;
    GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não.
    GLuint model; // ID da displayList de desenho.
}
entidade;

// Vector que armazena as Structs das entidades

vector<entidade> entityList;
vector<entidade> shotsList;

// Determina os parâmetros iniciais de cada entidade e os armazena dentro do array entityList[]
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
        .model = aviaoDisplayList
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
        .model = aviaoDisplayList1
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
        .model = aviaoDisplayList2
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
        .angularSpeed = 2,
        .vetorialSpeed = 1,
        .angulo = 0,
        .onScreen = GL_TRUE, 
        .model = shotDisplayList
    };

    shotsList.push_back(defaultShot);
}

// Desenha o aviao do jogador
void desenhaPlayer()
{
    glColor3f(0.5, 0.5, 0.5); //cinza
    
    glBegin(GL_TRIANGLE_FAN); //ponta e tronco
        glVertex2f(0,0);
        glVertex2f(0,25);
        glVertex2f(5,15);
        glVertex2f(5,-20);
        glVertex2f(-5,-20);
        glVertex2f(-5,15);
        glVertex2f(0,25);
    glEnd();

    glBegin(GL_TRIANGLES);
        // calda esquerda
        glVertex3f( -5, -20, 0);
        glVertex3f(-15, -30, 0);
        glVertex3f( -5, -15, 0);
        // calda direita
        glVertex3f(  5,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  5,-15, 0);
        // asa direita
        glVertex3f(  5,  5, 0);
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        // asa esquerda
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5,  5, 0);

    glColor3f(1, 0.25, 0.25); // vermelho

        //asa direita
        glVertex3f(  5,  0, 0);
        glVertex3f( 20,-10, 0);
        glVertex3f(  5, -5, 0);
        //asa esquerda
        glVertex3f( -5,  0, 0);
        glVertex3f(-20,-10, 0);
        glVertex3f( -5, -5, 0);

    glColor3f(0, 0, 1); // azul

        //calda direita
        glVertex3f(  0,-20, 0);
        glVertex3f( 15,-30, 0);
        glVertex3f(  0,-15, 0);
        //calda esquerda
        glVertex3f(  0,-20, 0);
        glVertex3f(-15,-30, 0);
        glVertex3f(  0,-15, 0);
    glEnd();

    glColor3f(1,0,0); // desenha Hitbox
}

// Desenha o aviao1
void drawPlane1()
{
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLE_FAN); //corpo e asa superior
        glVertex2f(0, 8);
        glVertex2f(-10,12.5);
        glVertex2f(-5, 15);
        glVertex2f(12, 11.5);
        glVertex2f(25,15);
        glVertex2f(35, 10);
        glVertex2f(-30,-5);
        glVertex2f(-20,0);
        glVertex2f(-15,5);
        glVertex2f(5,10);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); // calda
        glVertex2f(-15,5);
        glVertex2f(-20,0);
        glVertex2f(-30,15);
        glVertex2f(-25,17.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f( 0, 5);
        glVertex2f(-10,-9);
        glVertex2f( -5,-11.5);
        glVertex2f(15, 7.5);
    glEnd();

    glColor3f(0, 0, 1);

    glBegin(GL_TRIANGLES);    //janela
        glVertex2f( 25, 15);
        glVertex2f( 30,12.5);
        glVertex2f( 18, 13.2);
    glEnd();

    glColor3f(0,0,0); //desenhar linhas pretas

    glBegin(GL_LINE_STRIP);         //asa baixo 
        glVertex2f( 0, 5);
        glVertex2f(-10,-9);
        glVertex2f( -5,-11.5);
        glVertex2f(15, 7.5);
    glEnd();

    glBegin(GL_LINE_STRIP);         //asa cima
        glVertex2f( 25, 15);
        glVertex2f( 30,12.5);
        glVertex2f( 18, 13.2);
    glEnd();

    glColor3f(1,0,0);
}

// Desenha o aviao2
void drawPlane2()
{
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLE_FAN); // Tronco, asas e ponta.
        glVertex2f(0,10);
        glVertex2f(-5,5);
        glVertex2f(-14.3,12.5);
        glVertex2f(-10, 17);
        glVertex2f(0,15);
        glVertex2f(5,20);
        glVertex2f(7.5, 22.5);
        glVertex2f(15,20);
        glVertex2f(10,15);
        glVertex2f(20,13);
        glVertex2f(17.5,10);
        glVertex2f(2.5,7.5);
        glVertex2f(-10,-5);
        glVertex2f(-20,-10);
        glVertex2f(-15,0);
        glVertex2f(-5,10);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); // Calda direita.
        glVertex2f(15,20);
        glVertex2f(22.5,20);
        glVertex2f(20,17.5);
        glVertex2f(12.5,17.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); // Calda esquerda.
        glVertex2f(5,20);
        glVertex2f(0,25);
        glVertex2f(2.5,27.5);
        glVertex2f(7.5,22.5);
    glEnd();

    glColor3f(0,1,0);

    glBegin(GL_TRIANGLE_FAN); // Cabine azul
        glVertex2f( 0, 12.5);
        glVertex2f(-5,14);
        glVertex2f(-9,7.5);
        glVertex2f(-10, 0);
    glEnd();

    glColor3f(1,0,0);
}

// Desenha o shot
void drawShot()
{
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0   ,0);
        glVertex2f(3.5 ,-3.5);
        glVertex2f(0   ,3.5);
        glVertex2f(-3.5,-3.5);
    glEnd();
}

// Cria displayLists de desenho de cada objeto
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

// Define os valores das coordenadas centrais default de cada entidade
void inicializaPosicoes()
{
    for(int i=0; i<6; i++){
        entityList[i].centro.x = (entityList[i].x_max + entityList[i].x_min)/2;
        entityList[i].centro.y = (entityList[i].y_max + entityList[i].y_min)/2;
        entityList[i].angulo = 0;
    }

    for(int i=0; i<shotsList.size(); i++){
        shotsList[i].centro.x = (shotsList[i].x_max + shotsList[i].x_min)/2;
        shotsList[i].centro.y = (shotsList[i].y_max + shotsList[i].y_min)/2;
        shotsList[i].angulo = 0;   
    }

    entityList[0].angulo = 90;

    //aviao principal NPC
    entityList[1].centro.x +=  0;
    entityList[1].centro.y += -60;

    //aviao1_1
    entityList[2].centro.x += 60;
    entityList[2].centro.y += 80;

    //aviao1_2
    entityList[3].centro.x += -60;
    entityList[3].centro.y += -80; 

    //aviao2_1
    entityList[4].centro.x += -70;
    entityList[4].centro.y += 65;

    //aviao2_2
    entityList[5].centro.x += 70;
    entityList[5].centro.y += -65;

    shotsList[0].centro.x += 40;
}

// Define a escala de todas as coordenadas de cada entidade
void inicializaEscala()
{
    for(int i=0; i<entityList.size(); i++)
    {
        entityList[i].resize.x = 0.6;
        entityList[i].resize.y = 0.6;

        entityList[i].x_max *= entityList[i].resize.x;
        entityList[i].x_min *= entityList[i].resize.x;

        entityList[i].y_max *= entityList[i].resize.y;
        entityList[i].y_min *= entityList[i].resize.y;
    }

    for(int i=0; i<shotsList.size(); i++)
    {
        shotsList[i].resize.x = 2;
        shotsList[i].resize.y = 2;

        shotsList[i].x_max *= shotsList[i].resize.x;
        shotsList[i].x_min *= shotsList[i].resize.x;

        shotsList[i].y_max *= shotsList[i].resize.y;
        shotsList[i].y_min *= shotsList[i].resize.y;
    }
}

// Cria uma Hitbox para todas as entidades
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

// Configura o valor inicial de algumas variáveis de estado
void inicializar()
{
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

// Eescreve texto "Game Over" na tela
void escreveTexto(void * font, char *s, float x, float y)
{
    glPushMatrix();
        glLoadIdentity();
        glRasterPos2d(x - 20, y);

        for (int i = 0; i < strlen(s); i++) 
            glutBitmapCharacter(font, s[i]);
    glPopMatrix();
}

// Detecta colisões
int colisaoGeral(entidade* e1, entidade* e2)
{
    vertice iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;

    iniDiag.x = e1->centro.x;
    iniDiag.y = e1->centro.y;
    
    for(int i=0; i<4; i++)
    {
        deltaVet.x = 0;
        deltaVet.y = 0;

        fimDiag.x = e1->alteredHitbox[i].x;
        fimDiag.y = e1->alteredHitbox[i].y;

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2->alteredHitbox[j];
            fimLado = e2->alteredHitbox[s];

            l = (fimLado.x - iniLado.x) * (iniDiag.y - fimDiag.y) - (iniDiag.x - fimDiag.x) * (fimLado.y - iniLado.y);

            d1 = ((iniLado.y - fimLado.y) * (iniDiag.x - iniLado.x) + (fimLado.x - iniLado.x) * (iniDiag.y - iniLado.y)) / l;

            d2 = ((iniDiag.y - fimDiag.y) * (iniDiag.x - iniLado.x) + (fimDiag.x - iniDiag.x) * (iniDiag.y - iniLado.y)) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.x += (1.0 - d1) * (fimDiag.x - iniDiag.x);
                deltaVet.y += (1.0 - d1) * (fimDiag.y - iniDiag.y);
                overlap = 1;
            }

            //ACHO Q É ESSE O PROBLEMA
            e1->centro.x += deltaVet.x * -1;
            e1->centro.y += deltaVet.y * -1;
        }
    }
    return overlap;
}

// Callback da displayFunction
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Endgame = 1 significa que ocorreu colisão
    if(endGame)
    {
        char s[20] = {"Game Over"};
        glColor3f(0,0,0);
        escreveTexto(GLUT_BITMAP_HELVETICA_18, s, 0, 0);
    }

    // Se não tiver acabado o programa, executa normalmente
    else
    {
        // Desenha todas as imagens
        for(int i=0; i<entityList.size(); i++){
            if(entityList[i].onScreen)
            {   
                glPushMatrix();
                    glTranslatef(entityList[i].centro.x, entityList[i].centro.y, 0);
                    if(i==0)
                        glRotatef(entityList[0].angulo-90,0,0,1);
                    glScalef(entityList[i].resize.x,entityList[i].resize.y,1);
                    glCallList(entityList[i].model);
                glPopMatrix();
            }
        }

        for(int i=0; i<shotsList.size(); i++){
            if(shotsList[i].onScreen)
            {   
                glPushMatrix();
                    glTranslatef(shotsList[i].centro.x, shotsList[i].centro.y, 0);
                    /*if(i==0)
                        glRotatef(shotsList[0].angulo,0,0,1);*/
                    glScalef(shotsList[i].resize.x,shotsList[i].resize.y,1);
                    glCallList(shotsList[i].model);
                glPopMatrix();
            }
        }

        glColor3ub(255,20,22);

        // hitBox = true: desenha hitboxes
        if(hitBox)
        {
            glBegin(GL_LINES);
                for(int e=0; e < entityList.size(); e++){
                    for(int i=0, j=1; i<4; i++,j=(i+1)%4){
                        glVertex2f(entityList[e].alteredHitbox[i].x, entityList[e].alteredHitbox[i].y);
                        glVertex2f(entityList[e].alteredHitbox[j].x, entityList[e].alteredHitbox[j].y);
                    }
                } 
            glEnd();

            glBegin(GL_LINES);
                for(int e=0; e < shotsList.size(); e++){
                    for(int i=0, j=1; i<4; i++,j=(i+1)%4){
                        glVertex2f(shotsList[e].alteredHitbox[i].x, shotsList[e].alteredHitbox[i].y);
                        glVertex2f(shotsList[e].alteredHitbox[j].x, shotsList[e].alteredHitbox[j].y);
                    }
                } 
            glEnd();
        }
    }

    //coloca esses desenhos na tela
    glutSwapBuffers();
}

// Callback da reshapeFunction
void reshape(int w, int h)
{
    aspectRatio = (float)w / (float)h;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * aspectRatio, 100* aspectRatio, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}                               

// Callback do evento de pressionamento de tecla (sem ser setas)
void keyboard(unsigned char key, int x, int y)
{
    /*Dependendo da tecla pressionada, um vetor sinaliza
    0 mostrando que uma tecla foi desligada, ou
    1 mostrando que uma tecla foi ligada*/
    switch (key)
    {
        case 27: 
            exit(0); 
            break;
            
        case 'w': 
        case 'W':
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case 's': 
        case 'S':
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case 'd':
        case 'D':
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case 'a':
        case 'A':
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;

        case '-':
        case '_':
            if(on_off[4] == 1)
                on_off[4] = 0;
            else on_off[4] = 1;
            break;
        
        case '+':
        case '=':
            if(on_off[5] == 1)
                on_off[5] = 0;
            else on_off[5] = 1;
            break;
    }
}

// Callback do evento de pressionamento de tecla (setas)
void setas(int key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case GLUT_KEY_UP: 
            if(on_off[0] == 1)
                on_off[0] = 0;
            else on_off[0] = 1;
            break;

        case GLUT_KEY_DOWN: 
            if(on_off[1] == 1)
                on_off[1] = 0;
            else on_off[1] = 1;
            break;

        case GLUT_KEY_RIGHT:
            if(on_off[2] == 1)
                on_off[2] = 0;
            else on_off[2] = 1;
            break;

        case  GLUT_KEY_LEFT:
            if(on_off[3] == 1)
                on_off[3] = 0;
            else on_off[3] = 1;
            break;
    }
}

// Altera o valor do ponto central do aviao do jogador
void movimentacaoJogador()
{
    double aux_angle = grausParaRadianos(entityList[0].angulo);

    // Aumenta a angulação da entidade com '+' e diminui com '-'
    entityList[0].angulo += (on_off[4] - on_off[5]) * entityList[0].angularSpeed;

    // Movimenta para cima e para baixo com 'w' e 's' ou 'cima' e 'baixo'
    entityList[0].centro.x += (on_off[0] - on_off[1]) * cos(aux_angle) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[0] - on_off[1]) * sin(aux_angle) * entityList[0].vetorialSpeed;

    // Movimenta para direita e esquerda com 'd' e 'a' ou '->' e '<-'
    entityList[0].centro.x += (on_off[2] - on_off[3]) * cos(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;
    entityList[0].centro.y += (on_off[2] - on_off[3]) * sin(aux_angle - M_PI/2) * entityList[0].vetorialSpeed;

    // Variáveis auxiliares
    double x,y;

    for(int i=0; i<4; i++)
    {
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        x = entityList[0].hitbox[i].x;
        y = entityList[0].hitbox[i].y;

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações
        entityList[0].alteredHitbox[i].x = x * cos(aux_angle + M_PI/2) - y * sin(aux_angle + M_PI/2);
        entityList[0].alteredHitbox[i].y = x * sin(aux_angle + M_PI/2) + y * cos(aux_angle + M_PI/2);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        entityList[0].alteredHitbox[i].x += entityList[0].centro.x;
        entityList[0].alteredHitbox[i].y += entityList[0].centro.y;
    }
}

// Altera o valor do ponto central dos NPCS
void movimentaNPC(int e)
{
    // Se o NPC andar na horizontal, executa os comandos
    if(entityList[e].ladoHorizontal != 0) 
    {
        // Se a entidade estiver programada para andar para a esquerda, diminui o valor X do ponto central
        if(entityList[e].ladoHorizontal == -1)
            entityList[e].centro.x -= entityList[e].x_move;

        // Se a entidade estiver programada para andar para a direita, aumenta o valor X do ponto central
        if(entityList[e].ladoHorizontal ==  1)
            entityList[e].centro.x += entityList[e].x_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite esquero da caixa de visualização,
        // programa a entidade para andar para a direita. 
        if(entityList[e].centro.x < -100 * aspectRatio - entityList[e].x_min)
        {
            entityList[e].ladoHorizontal = 1;
            entityList[e].centro.x += entityList[e].x_move;
        }

        // Se o extremo direito da entidade ultrapassar o limite direito da caixa de visualização,
        // programa a entidade para andar para a esquerda. 
        if(entityList[e].centro.x > 100 * aspectRatio - entityList[e].x_max)
        {
            entityList[e].ladoHorizontal = -1;
            entityList[e].centro.x -= entityList[e].x_move;
        }
    }

    // Se o NPC andar na vetical, executa os comandos
    if(entityList[e].ladoVertical != 0)
    {
        // Se a entidade estiver programada para andar para baixo, diminui o valor Y do ponto central.
        if(entityList[e].ladoVertical == -1)
            entityList[e].centro.y -= entityList[e].y_move;

        // Se a entidade estiver programada para andar para cima, aumenta o valor Y do ponto central.
        if(entityList[e].ladoVertical ==  1)
            entityList[e].centro.y += entityList[e].y_move;

        // Se o extremo esquerdo da entidade ultrapassar o limite inferior da caixa de visualização,
        // programa a entidade para andar para cima. 
        if(entityList[e].centro.y + entityList[e].y_min < -100 )
        {
            entityList[e].ladoVertical = 1;
            entityList[e].centro.y += entityList[e].y_move;
        }

        // Se o extremo esquerdo da entidade ultrapassar o limite superior da caixa de visualização,
        // programa a entidade para andar para baixo. 
        if(entityList[e].centro.y + entityList[e].y_max > 100 )
        {
            entityList[e].ladoVertical = -1;
            entityList[e].centro.y -= entityList[e].y_move;
        }
    }

}

void shotHitbox(int e)
{
    for(int i=0; i<4; i++)
    {
        shotsList[e].alteredHitbox[i].x = shotsList[e].hitbox[i].x + shotsList[e].centro.x;
        shotsList[e].alteredHitbox[i].y = shotsList[e].hitbox[i].y + shotsList[e].centro.y;
    }
}

// Ativa e altera os valores dos vertices da hitbox dos 
void enemyHitbox(int e)
{
    for(int i=0; i<4; i++)
    {
        entityList[e].alteredHitbox[i].x = entityList[e].hitbox[i].x + entityList[e].centro.x;
        entityList[e].alteredHitbox[i].y = entityList[e].hitbox[i].y + entityList[e].centro.y;
    }
}

// Garante que o player nunca saia da tela.
void dentroTela()
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(entityList[0].centro.y + entityList[0].y_max > 100)
        entityList[0].centro.y = 100 - entityList[0].y_max;

    if(entityList[0].centro.y + entityList[0].y_min < -100 )
        entityList[0].centro.y = -100 - entityList[0].y_min;

    if(entityList[0].centro.x + entityList[0].x_max > 100 * aspectRatio)
        entityList[0].centro.x = 100 * aspectRatio - entityList[0].x_max;
    
    if(entityList[0].centro.x + entityList[0].x_min < -100 * aspectRatio)
        entityList[0].centro.x = -100 * aspectRatio - entityList[0].x_min;
}

// Callback da timerFunction.
void timer(int t)
{
    // Se ocorrer colisao, determina os valores X e Y de todas as entidades para seus valores default,
    // com o intuito de reiniciar a animação.
    if(endGame){
        endGame = 0;
        inicializaPosicoes();
    }
    
    // Movimenta o jogador.
    movimentacaoJogador();

    // Movimenta os NPCs.
    for(int i=1; i < entityList.size(); i++)
    {
        //movimentaNPC(i);
        enemyHitbox(i);

        // Se ocorrer colisao entre o player e um dos 5 NPCs, começa o proceso def reiniciar a animação
        if(colisaoGeral(&entityList[0],&entityList[i]))
        {
            endGame = 1;
            glutTimerFunc(2000, timer, 16); // Se ocorrer a colisão, o período da timer é momentaneamente definido para
                                            // 2 segundos, para a mensagem de "Game Over" aparecer na tela durante 2 segundos.
        }
    }

    for(int i=0; i < shotsList.size(); i++)
    {
        shotHitbox(i);

        if(colisaoGeral(&shotsList[0],&entityList[0])) // entre o tiro e o personagem NESSA ORDEM
        {
            endGame = 1;
            glutTimerFunc(2000, timer, 16); // Se ocorrer a colisão, o período da timer é momentaneamente definido para
                                            // 2 segundos, para a mensagem de "Game Over" aparecer na tela durante 2 segundos.
        }
    }

    // Função que garante que player fique na tela.
    dentroTela();

    // Na proxima iteração da mainloop, a display() deve ser chamada.
    glutPostRedisplay();

    // Se a animação não tiver acabado, a timerfunc tem seu timer preservado.
    if(!endGame)
        glutTimerFunc(t, timer, t);
}

// Função main
int main(int argc, char **argv)
{
    // Prepara a tela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    // Configura o valor inicial de algumas variáveis de estado
    inicializar();

    // Registra callbacks para alguns eventos
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutSpecialFunc(setas);
    glutSpecialUpFunc(setas);
    glutTimerFunc(16, timer, 16);

    glutMainLoop();
    return 0;
}