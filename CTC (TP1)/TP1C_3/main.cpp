#include "OrderedPair.h"
#include "Entity.h"
#include "MovableEntity.h"
#include "Enemy.h"
#include "Player.h"
#include "globalParameters.h"
#include "StageManager.h"
#include "colisionManager.h"
#include "drawings.h"

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

StageManager stageManager;
int sposition = -30;
int flag =1;
int tempo=0;

void display()
{
    if (stageManager.getState() == 0) // desenha as coisas do menu
    {
        glClearColor(0, 0, 0, 0);
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
            drawSelec();
        glPopMatrix();
        glutSwapBuffers();
    }
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
        case 27: 
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

        case '-': // Rotaciona sentido anti-hotário
        case '_':
            if(keys[4] == 1)
                keys[4] = 0;
            else keys[4] = 1;
            break;
        
        case '+': // Rotaciona sentido horário
        case '=':
            if(keys[5] == 1)
                keys[5] = 0;
            else keys[5] = 1;
            break;

        case ' ': // Atira 
            if(keys[6] == 0)
                keys[6] = 1;
            else keys[6] = 0;
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
    //colisionManager();
    tempo+=16;

    if(tempo>350)
    {
        flag=1;
        tempo=0;
    }
    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

int main(int argc, char **argv)
{
    
    /*MovableEntity e;
    e.setAngle(1);
    e.setMidPoint(4,5);

    printf("(%.0f,%.0f)\n",e.getMidPoint().getX(),e.getMidPoint().getY());

    printf("\n");

    e.setMidPoint(2,e.getMidPoint().getY());

    printf("(%.0f,%.0f)\n",e.getMidPoint().getX(),e.getMidPoint().getY());

    Player p;
    Enemy en;

    p.fire();
    en.fire();*/

    // Prepara a tela

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista 2");

    // Configura o valor inicial de algumas variáveis de estado
    //inicializar();


    // Registra callbacks para alguns eventos
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutIgnoreKeyRepeat(1); 
    
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);    

    glutSpecialFunc(setas);
    
    glutSpecialUpFunc(setas);
    
    glutTimerFunc(16, timer, 16);

    glutMainLoop();
    return 0;
}