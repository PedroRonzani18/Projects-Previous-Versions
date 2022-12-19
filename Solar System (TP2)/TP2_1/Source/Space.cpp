#include "../Header/Space.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>
#include <cmath>

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
                    glRotatef(planet->getAngle(),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(moon,time);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

double Space::distanceBetweenPlanets(Coord a, Coord b)
{
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2) + pow(a.z - b.z,2));
}

void Space::initializePlanets() // fazer engine que calcule essas velocidades em unidades glut a partir do raio, periodo e distância do planeta, e estatem influenciados por um alpha
{

    estrelas = std::make_shared<Planet>(texturesId[8],0,0,4500,0,15000,0);
    sol = std::make_shared<Planet>(texturesId[9],0,0,600,0,0,0);

    /*
    planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0, 0.4, 2.5, 88, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0, 0.4, 4.5, 225, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1, 0.4, 6.5, 365, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2, 0.4, 8.5, 686, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3, 0.4, 10.5, 4328, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3, 0.4, 12.5, 10752, 30));
    planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3, 0.4, 14.5, 30663, 30));    
    planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3, 0.4, 16.5, 601480000, 30));
    */

/*    
    planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0,  24,  2.5,        88,   4));
    planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0,  60,  4.5,       225,   6));
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1,  64,  6.5,       365, 0.99));
    planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2,  34,  8.5,       686, 1.03));
    planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3, 175, 10.5,      4328, 0.41));
    planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3, 120, 12.5,     10752, 0.45));
    planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3,  85, 14.5,     30663, 0.72));    
    planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3,  77, 16.5, 601480000, 0.67));
*/

    planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0,  24,   4.0, 0,   4));
    planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0,  60,   5.0, 0,   6));
    planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1,  64,   6.5, 0, 0.99));
    planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2,  34,   8.0, 0, 1.03));
    planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3, 175,  10.0, 0, 0.41));
    planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3, 120, 12.25, 0, 0.45));
    planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3,  85, 14.0,  0, 0.72));    
    planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3,  77, 16.0,  0, 0.67));

}