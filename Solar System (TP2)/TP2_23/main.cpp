// Bibliotecas criadas
#include "Header/drawings.h"
#include "Header/globalParameters.h"
#include "Header/Planet.h"
#include "Header/Space.h"
#include "Header/lighting.h"
#include "Header/Camera.h"
#include "Header/MusicManager.h"
#include "Header/Keyboard.h"
#include "Header/lighting.h"
#include "Header/Parser.h"

// Objeto do espaço
Space* space;

void initialize()
{
    // Permite a anexação devida da textura
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Ativa as cores dos materiais
    glEnable(GL_COLOR_MATERIAL);

    // ??
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    space = new Space();
    keys = new Keyboard();

    createTextures();
    space->initialize();
}

// Callback para desenho na tela
void display()
{
    space->display();
}

// Callback de redimensionamento da tela
void reshape(int width, int height)   
{
    // Variável global de razão aspecto
    razaoAspecto = (double) glutGet(GLUT_WINDOW_WIDTH) / (double) glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-razaoAspecto, razaoAspecto, -1, 1, 2, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Callback de pressionamento de teclas
void keyboard(unsigned char key, int x, int y)
{
    char formattedKey = (char) toupper(key);

        switch (formattedKey)
        {
            case 27 :     
                exit(0);
                break;

            case 'W':
                if(keys->w) keys->w = 0;
                else       keys->w = 1;
                break;

            case 'A':
                if(keys->a) keys->a = 0;
                else       keys->a = 1;
                break;

            case 'S':
                if(keys->s) keys->s = 0;
                else       keys->s = 1;
                break;

            case 'D':
                if(keys->d) keys->d = 0;
                else       keys->d = 1;
                break;

            case ' ':
                if(keys->space) keys->space = 0;
                else        keys->space = 1;
                break;

            case 'F':
                if(keys->f) keys->f = 0;
                else       keys->f = 1;
                break;

            case 'Z':
                if(keys->z) keys->z = 0;
                else       keys->z = 1;
                break;

            case 'X':
                if(keys->x) keys->x = 0;
                else       keys->x = 1;
                break;

            case 'C':
                if(keys->c) keys->c = 0;
                else       keys->c = 1;
                break;

            case 'V':
                if(keys->v) keys->v = 0;
                else       keys->v = 1;
                break;

            case 'B':
                if(keys->b) keys->b= 0;
                else       keys->b = 1;
                break;
                
            case 'N':
                if(keys->n) keys->n = 0;
                else       keys->n = 1;
                break;

            case 'L':
                if(keys->l) keys->l = 0;
                else       keys->l = 1;
                buttons[0] = 1;
                break;
        }
}

// Callback da função timer
void timer(int t)
{
    // Armazena o valor do tempo passado desde o início do programa em segundos
    tempo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    space->getCamera()->move();
    space->marsMusic(space->getCamera()->getMidPoint());
    space->onOffSun();

    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

// Callback de captura da posição do mouse
void posicionaCamera(int x, int y)
{
    // Determina o valor da posição do mouse
    space->getCamera()->setMouseCoords(x,y);
}

void glutInitialize(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1384,752);
    glutInitWindowPosition(325,125);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Lista 3");

    glutIgnoreKeyRepeat(1); 

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard);
    glutPassiveMotionFunc(posicionaCamera);
    glutTimerFunc(2, timer, 2);
}

int main(int argc, char **argv)
{
    glutInitialize(argc, argv);
    initialize();
    glutMainLoop();

    return 0;
}