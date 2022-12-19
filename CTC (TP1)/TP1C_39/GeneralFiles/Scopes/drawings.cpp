#include <GL/freeglut.h>
#include <stdio.h>
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"

#define LARGURA_DO_MUNDO 90
#define ALTURA_DO_MUNDO  100

std::vector<GLuint> textures;
std::vector<GLuint> auxTex;


void textureModule(void model())
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        model();
    glEndList();
    textures.push_back(aux);
}

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

void initializeTextures()
{
    auxTex.push_back(loadTexture("PNG_deposit/mao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceshitp1.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceship2.png"));
    auxTex.push_back(loadTexture("PNG_deposit/setaMenu.png"));
    auxTex.push_back(loadTexture("PNG_deposit/mao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/ajudaBotao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/iniciarBotao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/space1.png"));
    auxTex.push_back(loadTexture("PNG_deposit/space2.png"));


    /*[0]*/ textureModule(abobora);
    /*[1]*/ textureModule(drawPlane1);
    /*[2]*/ textureModule(desenhaPlayer);    
    /*[3]*/ textureModule(drawMenuArrow);
    /*[4]*/ textureModule(drawDeaultShot);
    /*[5]*/ textureModule(drawMenuButton);
            textureModule(drawAjudaButton);
            textureModule(drawBackground2);
            textureModule(drawStartButton);
            textureModule(drawBackground3);

}

void templateSquare(double x, double y, GLuint id)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0); 
        glVertex2f (-x,-y);

        glTexCoord2f(1,0);
        glVertex2f (x,-y);

        glTexCoord2f(1,1);
        glVertex2f (x,y);

        glTexCoord2f(0,1);
        glVertex2f(-x,y);
    glEnd();
    glDisable(GL_TEXTURE_2D);
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

void abobora()
{
    templateSquare(20,20,auxTex[0]);
}

// Desenha o aviao do jogador
void desenhaPlayer()
{
   templateSquare(30,30,auxTex[2]);
}

// Desenha o aviao1
void drawPlane1()
{
   templateSquare(30,30,auxTex[1]);
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


void drawAjudaButton()
{
    templateSquare(50,15,auxTex[5]);
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

void drawStartButton()
{
    templateSquare(50,15,auxTex[6]);
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

void drawBackground2()
{
    templateSquare(90,100,auxTex[7]);
}

void drawBackground3()
{
    templateSquare(90,100,auxTex[8]);    
}

void drawMenuArrow()
{
    templateSquare(7,7,auxTex[3]);
}

void drawDeaultShot()
{
 
}

