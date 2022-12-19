#include "../Header/Space.h"
#include "../Header/MusicManager.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Space::Space()
{
    //light = std::make_shared<Lighting>();
    musicManager = std::make_shared<MusicManager>();

    lights.push_back(std::make_shared<Lighting>(1));
    lights.push_back(std::make_shared<Lighting>(0));
    lights.push_back(std::make_shared<Lighting>(0));

}

void Space::drawAndMove(double time)
{
    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
        drawCorpse(estrelas,time);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glPushMatrix();
            drawCorpse(sol,time);
        glPopMatrix();

        for(std::shared_ptr<Planet> planet : planets)
        {
            glPushMatrix();
                planet->setAngle(time * planet->getTranslationAngularSpeed());
                planet->setMidPoint(-planet->getRotationRadius() * cos(planet->getAngle()),
                                    0,
                                     planet->getRotationRadius() * sin(planet->getAngle()));
                drawCorpse(planet,time);
            glPopMatrix();

            for(std::shared_ptr<Moon> moon: planet->getMoons())
            {
                glPushMatrix();
                    glRotatef(radGr(planet->getAngle()),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(moon,time);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

void Space::marsMusic(Coord c)
{
    musicManager->marsMusic(distanceBetweenPlanets(c,planets[3]->getMidPoint()));
}

double Space::distanceBetweenPlanets(Coord a, Coord b)
{
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2) + pow(a.z - b.z,2));
}

void Space::initializePlanets() 
{
           estrelas = std::make_shared<Planet>(texturesId[8], 0, 0, 6000,   0.0, 0,   10);
                sol = std::make_shared<Planet>(texturesId[9], 0, 0,  600,   0.0, 0,    0);
    planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0,   24,   4.0, 0,    4));
    planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0,   60,   5.0, 0,    6));
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1,   64,   6.5, 0, 0.99));
    planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2,   34,   8.0, 0, 1.03));
    planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3,  175,  10.0, 0, 0.41));
    planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3,  120, 12.25, 0, 0.45));
    planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3,   85,  14.0, 0, 0.72));    
    planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3,   77,  16.0, 0, 0.67));
}