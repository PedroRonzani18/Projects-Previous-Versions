#include "../Header/globalParameters.h"
#include "../Header/Planet.h"
#include "../Header/drawings.h"

#include <stdio.h>
#include <SOIL/SOIL.h>
#include <memory>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

void drawSolidSphere(double radius, int stacks, int columns)
{
    GLUquadric* quadObj = gluNewQuadric(); // cira uma quadrica 
    gluQuadricDrawStyle(quadObj, GLU_FILL); // estilo preenchido
    gluQuadricNormals(quadObj, GLU_SMOOTH);
    gluQuadricTexture(quadObj, GL_TRUE); // chama 01 glTexCoord por vértice
    gluSphere(quadObj, radius, stacks, columns); // cria os vértices de uma esfera
    gluDeleteQuadric(quadObj);
}

void drawCorpse(std::shared_ptr<Planet> planet, double time)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT,   planet->getMaterial()->matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   planet->getMaterial()->matDifuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  planet->getMaterial()->matEspec);
    glMaterialf (GL_FRONT, GL_SHININESS, planet->getMaterial()->matShininess);
    
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, planet->getTexture());

        glRotatef(radGr(planet->getAngle()),0,0,1); // toraciona no proprio eixo
        glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        if(planet->getHasLight())
            glLightfv(planet->getGlLightConst(), GL_POSITION, planet->getLighting()->lightPos); // posiciona a fonte de luz na posição do planeta
        glRotatef(time * planet->getRotationAngularSpeed(),0,0,1); // rotaciona no proprio eixo

        if(!planet->doesDependsOnLight()) glDisable(GL_LIGHTING);
        drawSolidSphere(planet->getCoreRadius(),200,200);
        if(!planet->doesDependsOnLight()) glEnable(GL_LIGHTING);

    glDisable(GL_TEXTURE_2D);
}

void drawCorpse(std::shared_ptr<Sol> sun, double time)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT,   sun->getMaterial()->matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   sun->getMaterial()->matDifuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  sun->getMaterial()->matEspec);
    glMaterialf (GL_FRONT, GL_SHININESS, sun->getMaterial()->matShininess);

    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, sun->getTexture());

        glRotatef(radGr(sun->getAngle()),0,0,1); // rotaciona ao redor do sol
        glTranslated(-sun->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        glRotatef(time * sun->getRotationAngularSpeed(),0,0,1); // rotaciona no proprio eixo

        if(sun->getLighting()->lightLigada) // se a luz do sol estiver ligada, o sol aparece
        {
            glDisable(GL_LIGHTING);
            drawSolidSphere(sun->getCoreRadius(),200,200);
            glEnable(GL_LIGHTING);
        }
        else
            drawSolidSphere(sun->getCoreRadius(),200,200);

    glDisable(GL_TEXTURE_2D);
}

void drawCorpse(std::shared_ptr<Moon>  moon, double time)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT,   moon->getMaterial()->matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   moon->getMaterial()->matDifuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  moon->getMaterial()->matEspec);
    glMaterialf (GL_FRONT, GL_SHININESS, moon->getMaterial()->matShininess);

    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, moon->getTexture());
        glRotated(radGr(time * moon->getTranslationAngularSpeed()) + moon->getAngle(),0,0,1); // rotaciona no proprio eixo 
        glTranslated(-moon->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
        glRotatef(time * moon->getRotationAngularSpeed(),0,0,1); // rotaciona no proprio eixo
        drawSolidSphere(moon->getCoreRadius(),200,200);   
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
        printf("Erro do SOIL: '%s' + %s\n", SOIL_last_result(),arquivo);

    return idTextura;
}

void createTextures()
{
    texturesId.resize(0);
    /*[ 0]*/texturesId.push_back(loadTexture("imagens/2k_mercury.jpg"));
    /*[ 1]*/texturesId.push_back(loadTexture("imagens/2k_venus_surface.jpg"));
    /*[ 2]*/texturesId.push_back(loadTexture("imagens/2k_earth_daymap.jpg"));
    /*[ 3]*/texturesId.push_back(loadTexture("imagens/2k_mars.jpg"));
    /*[ 4]*/texturesId.push_back(loadTexture("imagens/2k_jupiter.jpg"));
    /*[ 5]*/texturesId.push_back(loadTexture("imagens/2k_saturn.jpg"));
    /*[ 6]*/texturesId.push_back(loadTexture("imagens/2k_uranus.jpg"));
    /*[ 7]*/texturesId.push_back(loadTexture("imagens/2k_neptune.jpg"));
    /*[ 8]*/texturesId.push_back(loadTexture("imagens/2k_stars_milky_way.jpg"));
    /*[ 9]*/texturesId.push_back(loadTexture("imagens/2k_sun.jpg"));
    /*[10]*/texturesId.push_back(loadTexture("imagens/2k_moon.jpg"));
}


