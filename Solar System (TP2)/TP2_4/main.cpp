#include <GL/freeglut.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL_mixer.h>

#include "Header/drawings.h"
#include "Header/globalParameters.h"
#include "Header/Planet.h"
#include "Header/Space.h"
#include "Header/lighting.h"
#include "Header/Camera.h"
#include "Header/MusicManager.h"
#include "Header/Keyboard.h"
#include "Header/lighting.h"

Space* space;
Camera camera;
//MusicManager* musicManager;

void enables()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0); 
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
}

void initialize()
{
    space = new Space();
    //musicManager = new MusicManager();
    keys = new Keyboard();

    glClearColor(0,0,0,0);

    enables();
    //space->configuraMateriais();
    space->getLight()->configuraMateriais();

    space->getMusicManager()->configureMusic();
    //musicManager->configureMusic();
    glShadeModel(GL_PHONG_HINT_WIN);
    createTextures();
    space->initializePlanets();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    camera.setupCamera();
    space->getLight()->atualizaPropriedadesLuz();
    //space->atualizaPropriedadesLuz();
    space->drawAndMove(tempo);

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    float razaoAspecto = (float) glutGet(GLUT_WINDOW_WIDTH) / (float) glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-razaoAspecto, razaoAspecto, -1, 1, 2, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

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

void timer(int t)
{
    tempo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    camera.setupCamera();
    camera.move();
    //musicManager->marsMusic(Space::distanceBetweenPlanets(camera.getMidPoint(),space->getPlanet(3)->getMidPoint()));
    space->marsMusic(camera.getMidPoint());

    glutPostRedisplay();
    glutTimerFunc(t, timer, t);
}

void posicionaCamera(int x, int y)
{
    xMouse = x;
    yMouse = y;
    camera.setCheckMouse(true);
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