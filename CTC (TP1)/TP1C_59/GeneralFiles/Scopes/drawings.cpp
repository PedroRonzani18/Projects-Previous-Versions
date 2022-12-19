#include <GL/freeglut.h>
#include <stdio.h>
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include <functional>

#define LARGURA_DO_MUNDO 90
#define ALTURA_DO_MUNDO  100

std::vector<GLuint> textures;

void textureModule(void templateSquare(double, double, GLuint),double x, double y, GLuint z)
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        templateSquare(x,y,z);
    glEndList();
    textures.push_back(aux);
}

void textureModule(void templateSquare(double  , double  , GLuint  , double   , double   , double   , double ),
                                       double x, double y, GLuint z, double wo, double uo, double dw, double du)
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        templateSquare(x, y, z, wo, uo, dw, du);
    glEndList();
    textures.push_back(aux);
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

void templateSquare(double x, double y, GLuint id, double wo, double uo, double dw, double du)
{
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, id);
        glColor3f(1,1,1);
        glBegin(GL_TRIANGLE_FAN);

        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(wo,uo); 
            glVertex2f (-x,-y);

            glTexCoord2f(wo + dw,uo);
            glVertex2f (x,-y);

            glTexCoord2f(wo + dw,uo + du);
            glVertex2f (x,y);

            glTexCoord2f(wo,uo + du);
            glVertex2f(-x,y);
        glEnd();
    glDisable(GL_TEXTURE_2D);
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
    // Cria um quadrado com dimensoes x y, carrega a textura em questão e armazena os IDs gerados no vector "textures"

     /*[0]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/ajudaBotao.png"));
     /*[1]*/textureModule(templateSquare, 5,  5,loadTexture("PNG_deposit/blueBall.png"));
     /*[2]*/textureModule(templateSquare, 7,  2,loadTexture("PNG_deposit/blueLaser.png"));
     /*[3]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/fireBall.png"));
     /*[4]*/textureModule(templateSquare, 2,  5,loadTexture("PNG_deposit/greenLaser.png"));
     /*[5]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/iniciarBotao.png"));
     /*[6]*/textureModule(templateSquare, 5,  5,loadTexture("PNG_deposit/orangeBall.png"));
     /*[7]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/redLaser.png"));
     /*[8]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/setaMenu.png"));
     /*[9]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/space1.png"));
    /*[10]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/space2.png"));
    /*[11]*/textureModule(templateSquare,25, 25,loadTexture("PNG_deposit/spaceship1.png"));
    /*[12]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/spaceship2.png"));
    /*[13]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/spaceship3.png"));
    /*[14]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship4.png"));
    /*[15]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/backGroundAjuda.png"));
    /*[16]*/textureModule(templateSquare, 1, 3, loadTexture("PNG_deposit/letrinhasDemasiadamenteMuitoCria.png"), 0, 0, 53.0/1242, 1);
    /*[17 - 25]*/
    float soma=60.0/1242, propX = 131.0/1242;
    for(int i=0; i<9; i++)
    {
        textureModule(templateSquare, 3, 3, loadTexture("PNG_deposit/letrinhasDemasiadamenteMuitoCria.png"), soma, 0, propX, 1);
        soma += propX;
    }
    /*[26]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/heart.png"));
    /*[27]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship5.png"));
    /*[28]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship6.png"));
    /*[28]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship7.png"));

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
    glColor3f(0, 1, 0);
    glLineWidth(2);


    for (int i = 0, j = 1; i < 4; i++, j = (i + 1) % 4)
    {
        glBegin(GL_LINES);
            glVertex2f(m->getAlteredHitbox()[i].getX(), m->getAlteredHitbox()[i].getY());
            glVertex2f(m->getAlteredHitbox()[j].getX(), m->getAlteredHitbox()[j].getY());
        glEnd();
    }
    
}