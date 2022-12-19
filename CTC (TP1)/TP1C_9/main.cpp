#include "BaseClasses/Header/OrderedPair.h"
#include "BaseClasses/Header/Entity.h"
#include "BaseClasses/Header/MovableEntity.h"
#include "BaseClasses/Header/Enemy.h"
#include "BaseClasses/Header/Player.h"

#include "GenaralFiles/Header/globalParameters.h"
#include "GenaralFiles/Header/drawings.h"

#include "Stages/Header/StageManager.h"

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

StageManager stageManager;
/*int sposition = -30;
int flag =1;
int tempo=0;*/

/*
void displayMenu()
{
    //glClearColor(0, 0, 0, 0);
    glClearColor(0, 1, 0, 0); 
        glClear(GL_COLOR_BUFFER_BIT);


        glPushMatrix();
            glLoadIdentity();
            glColor3f(1, 1, 0);
            glRasterPos2d(-50,50);
            const unsigned char menu_txt[30] = {"BEM VINDO AO MENU"};
            glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,menu_txt); 

            //glutStrokeString()
            
        glPopMatrix();


        glPushMatrix();
            glLoadIdentity();
            glColor3f(1, 1, 0);
            glRasterPos2d(-20, -32);
            const unsigned char init[30] = {"INICAR"};
            glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, init); 
        glPopMatrix();
        
        glPushMatrix();
            glLoadIdentity();
            glColor3f(1, 1, 0);
            glRasterPos2d(-20, -42); 
            const unsigned char ajuda[30] = {"AJUDA"};
            glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, ajuda); 
        glPopMatrix();

        
        glPushMatrix();
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
            glTranslatef(0,sposition,0);
            selec();
        glPopMatrix();
        glutSwapBuffers();
}

void diaplayLevel1()
{
    Stage auxStage = stageManager.getCurrentStage();
    
    //translada, rotaciona e desenha
    for(int i=0; i< stageManager.getCurrentStage().getEntities().size(); i++)
    {
        if(auxStage.getEntity(i).getOnScreen())
        {   
            auto auxEnt = auxStage.getEntity(i);

            glPushMatrix();
                glTranslatef(auxStage.getEntity(i).getMidPoint().getX(),
                             auxStage.getEntity(i).getMidPoint().getY(),
                             0);
       
                //if(auxStage.getEntity(i) instanceof MovableEntity)
                //if(dynamic_cast<MovableEntity*>(&auxEnt) != nullptr)

//Mae: Entity
//Filha: MovableEntity
//
*/
/*
                if(instanceof<MovableEntity>(&auxEnt))
                {
                    //MovableEntity* auxAux = new MovableEntity();
                    //auxAux = reinterpret_cast<MovableEntity*> (&auxEnt);

                    glRotatef(auxAux->getAngle(),0,0,1);

                    printf("Angulo: %f\n",auxAux->getAngle());
                    //aux reinterpret_cast<MovableEntity*>(&auxEnt);
                }
*/      
/*                   
                
                glScalef(auxStage.getEntity(i).getResize(),
                         auxStage.getEntity(i).getResize(),
                         1);

                glCallList(auxStage.getEntity(i).getDisplayListModel());

            glPopMatrix();
        }
    }

    glColor3ub(255,20,22);
}
*/

#define LARGURA_DO_MUNDO 90
#define ALTURA_DO_MUNDO  100

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    
    Stage aux = stageManager.getCurrentStage();

    for(int i=0; i<aux.getEntities().size(); i++)
    {
        glPushMatrix();
            glTranslatef(aux.getEntity(i).getMidPoint().getX(),
                         aux.getEntity(i).getMidPoint().getY(),
                         0);
            glCallList(aux.getEntity(i).getDisplayListModel());
        glPopMatrix();
    }    
    glutSwapBuffers();

    /*
    switch (stageManager.getState())
    {
    case 0:
        displayMenu();
        break;
    
    case 2:
        diaplayLevel1();
        break;
    }
    */
}

void redimensionada(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-LARGURA_DO_MUNDO, LARGURA_DO_MUNDO, -ALTURA_DO_MUNDO, ALTURA_DO_MUNDO, -1, 1);

    float razaoAspectoJanela = ((float)width)/height;
    float razaoAspectoMundo = ((float) LARGURA_DO_MUNDO)/ ALTURA_DO_MUNDO;
    // se a janela está menos larga do que o mundo (16:9)...
    if (razaoAspectoJanela < razaoAspectoMundo) {
        // vamos colocar barras verticais (acima e abaixo)
        float hViewport = width / razaoAspectoMundo;
        float yViewport = (height - hViewport)/2;
        glViewport(0, yViewport, width, hViewport);
    }
    // se a janela está mais larga (achatada) do que o mundo (16:9)...
    else if (razaoAspectoJanela > razaoAspectoMundo) {
        // vamos colocar barras horizontais (esquerda e direita)
        float wViewport = ((float)height) * razaoAspectoMundo;
        float xViewport = (width - wViewport)/2;
        glViewport(xViewport, 0, wViewport, height);
    } else {
        glViewport(0, 0, width, height);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

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
        case 27: //ESC
            exit(0); 
            break;
            
        case 'w': //Anda para frente
        case 'W':
            if(keys[0] == 1)
                keys[0] = 0;
            else keys[0] = 1;
            break;

        case 's': //Anda para trás
        case 'S':
            if(keys[1] == 1)
                keys[1] = 0;
            else keys[1] = 1;
            break;

        case 'd': // Anda para direita
        case 'D':
            if(keys[2] == 1)
                keys[2] = 0;
            else keys[2] = 1;
            break;

        case 'a': // Anda para esquerda
        case 'A':
            if(keys[3] == 1)
                keys[3] = 0;
            else keys[3] = 1;
            break;

        case ' ': // Atira 
            if(keys[4] == 0)
                keys[4] = 1;
            else keys[4] = 0;
            break;

        case '-': // Rotaciona sentido anti-hotário
        case '_':
            if(keys[5] == 1)
                keys[5] = 0;
            else keys[5] = 1;
            break;
        
        case '+': // Rotaciona sentido horário
        case '=':
            if(keys[6] == 1)
                keys[6] = 0;
            else keys[6] = 1;
            break;
    }
}

void setas(int key, int x, int y)
{
    switch (key){
        case 27: 
            exit(0); 
            break;
            
        case GLUT_KEY_UP: 
            if(keys[0] == 1)
                keys[0] = 0;
            else keys[0] = 1;
            break;

        case GLUT_KEY_DOWN: 
            if(keys[1] == 1)
                keys[1] = 0;
            else keys[1] = 1;
            break;

        case GLUT_KEY_RIGHT:
            if(keys[2] == 1)
                keys[2] = 0;
            else keys[2] = 1;
            break;

        case  GLUT_KEY_LEFT:
            if(keys[3] == 1)
                keys[3] = 0;
            else keys[3] = 1;
            break;
    }
}

void timer(int t)
{
    stageManager.menuKeyboardManager();

    tempo+=16;
    if(tempo>350){
        flag=1;
        tempo=0;
    }
    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 1000);
    glutInitWindowPosition(540,0);
    glutCreateWindow("Lista 2");

    stageManager.gameInit();
    glutIgnoreKeyRepeat(1); 

    // Registra callbacks para alguns eventos
    glutDisplayFunc(display);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);    
    glutSpecialFunc(setas);
    glutSpecialUpFunc(setas);
    glutTimerFunc(16, timer, 16);

    glutMainLoop();
    return 0;
}