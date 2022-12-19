#include <GL/freeglut.h>
#include <stdio.h>
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"

#define LARGURA_DO_MUNDO 90
#define ALTURA_DO_MUNDO  100

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

/*
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
*/


GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    
    if (idTextura == 0) 
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());

    return idTextura;
}

void abobora()
{
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);

        glTexCoord2f(0,0); 
        glVertex3f (-20,-20,0);

        glTexCoord2f(1,0);
        glVertex3f (20,-20,0);

        glTexCoord2f(1,1);
        glVertex3f (20,20,0);

        glTexCoord2f(0,1);
        glVertex3f(-20,20,0);

    glEnd();
}

void drawBackground()
{
    glColor3f(0, 0, 1);
    
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
        glVertex2f(LARGURA_DO_MUNDO, -ALTURA_DO_MUNDO);
        glVertex2f(-LARGURA_DO_MUNDO, -ALTURA_DO_MUNDO);
        glVertex2f(-LARGURA_DO_MUNDO, ALTURA_DO_MUNDO);
    glEnd();
}

void drawMenuButton()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f( 40, 20);
        glVertex2f(-40, 20);
        glVertex2f(-40,-20);
        glVertex2f( 40,-20);
    glEnd();
}

void drawEmphassisMenuButton()
{
    glColor3f(0, 1, 0);
    glLineWidth(12);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 40, 20);
        glVertex2f(-40, 20);
        glVertex2f(-40,-20);
        glVertex2f( 40,-20);
    glEnd();
}

void drawDeaultShot()
{
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0   ,0);
        glVertex2f(4 ,-4);
        glVertex2f(0   ,4);
        glVertex2f(-4,-4);
    glEnd();
}

void drawModel(MovableEntity *m)
{
    glPushMatrix();
        glTranslatef(m->getMidPoint().getX(),
                    m->getMidPoint().getY(),
                    0);
        glRotatef(m->getAngle(), 0, 0, 1);
        glScalef(m->getResize(), m->getResize(), 1);
        glCallList(m->getDisplayListModel());
    glPopMatrix();
}

void drawHitbox(MovableEntity* m)
{
    glColor3ub(255,20,22);
    glLineWidth(2);
    for (int i = 0, j = 1; i < 4; i++, j = (i + 1) % 4)
    {
        glBegin(GL_LINES);
            glVertex2f(m->getAlteredHitbox()[i].getX(), m->getAlteredHitbox()[i].getY());
            glVertex2f(m->getAlteredHitbox()[j].getX(), m->getAlteredHitbox()[j].getY());
        glEnd();
    }
}