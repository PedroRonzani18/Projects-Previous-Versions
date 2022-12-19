#include <GL/freeglut.h>
#include <stdio.h>
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include <functional>

#define LARGURA_DO_MUNDO 90
#define ALTURA_DO_MUNDO  100

std::vector<GLuint> textures;
std::vector<GLuint> auxTex;


void textureModule4(void templateSquare(double, double, GLuint),double x, double y, GLuint z)
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        templateSquare(x,y,z);
    glEndList();
    textures.push_back(aux);
}

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
    /*
    auxTex.push_back(loadTexture("PNG_deposit/ajudaBotao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/blueBall.png"));
    auxTex.push_back(loadTexture("PNG_deposit/blueLaser.png"));
    auxTex.push_back(loadTexture("PNG_deposit/fireBall.png"));
    auxTex.push_back(loadTexture("PNG_deposit/greenLaser.png"));
    auxTex.push_back(loadTexture("PNG_deposit/iniciarBotao.png"));
    auxTex.push_back(loadTexture("PNG_deposit/orangeBall.png"));
    auxTex.push_back(loadTexture("PNG_deposit/redLaser.png"));
    auxTex.push_back(loadTexture("PNG_deposit/setaMenu.png"));
    auxTex.push_back(loadTexture("PNG_deposit/space1.png"));
    auxTex.push_back(loadTexture("PNG_deposit/space2.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceship1.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceship2.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceship3.png"));
    auxTex.push_back(loadTexture("PNG_deposit/spaceship4.png"));
    */

     /*[0]*/textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/ajudaBotao.png"));
     /*[1]*/textureModule4(templateSquare, 5, 5,loadTexture("PNG_deposit/blueBall.png"));
     /*[2]*/textureModule4(templateSquare, 7, 2,loadTexture("PNG_deposit/blueLaser.png"));
     /*[3]*/textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/fireBall.png"));
     /*[4]*/textureModule4(templateSquare, 2, 5,loadTexture("PNG_deposit/greenLaser.png"));
     /*[5]*/textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/iniciarBotao.png"));
     /*[6]*/textureModule4(templateSquare, 5, 5,loadTexture("PNG_deposit/orangeBall.png"));
     /*[7]*/textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/redLaser.png"));
     /*[8]*/textureModule4(templateSquare, 7, 7,loadTexture("PNG_deposit/setaMenu.png"));
     /*[9]*/textureModule4(templateSquare,90,100,loadTexture("PNG_deposit/space1.png"));
    /*[10]*/textureModule4(templateSquare,90,100,loadTexture("PNG_deposit/space2.png"));
    /*[11]*/textureModule4(templateSquare,30,30,loadTexture("PNG_deposit/spaceship1.png"));
    /*[12]*/textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/spaceship2.png"));
    /*[13]*/textureModule4(templateSquare,10,10,loadTexture("PNG_deposit/spaceship3.png"));
    /*[14]*/textureModule4(templateSquare,20,20,loadTexture("PNG_deposit/spaceship4.png"));

/*
    textureModule4(templateSquare,20,20,loadTexture("PNG_deposit/spaceship4.png"));
    textureModule4(templateSquare,30,30,auxTex[12]);
    textureModule4(templateSquare,30,30,auxTex[13]);
    textureModule4(templateSquare, 7, 7,auxTex[ 8]);
    textureModule(drawDeaultShot);
    textureModule(drawDeaultShot);
    textureModule4(templateSquare,50,15,loadTexture("PNG_deposit/ajudaBotao.png"));
    textureModule4(templateSquare,90,100,auxTex[ 9]);
    textureModule4(templateSquare,50,15,auxTex[5]);
    textureModule4(templateSquare,90,100,auxTex[10]);
*/

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

/*
void drawBackground2()
{
    templateSquare(90,100,auxTex[9]);
}

void drawDeaultShot()
{
 
}
*/

