#include "../Header/Space.h"
#include "../Header/MusicManager.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

// Construtor do Space
Space::Space()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    camera = std::make_shared<Camera>();
    musicManager = std::make_shared<MusicManager>();
}

// Função que desenhda todos os planetas
void Space::drawPlanets()
{
    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
        drawPlanet(estrelas,tempo);
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação

        glPushMatrix();
            drawSun(sol,tempo);
        glPopMatrix();

        for(std::shared_ptr<Planet> planet : planets)
        {
            glPushMatrix();
                planet->setAngle(tempo * planet->getTranslationAngularSpeed());
                planet->setMidPoint(-planet->getRotationRadius() * cos(planet->getAngle()),
                                    0,
                                     planet->getRotationRadius() * sin(planet->getAngle()));
                drawPlanet(planet,tempo);
            glPopMatrix();

            for(std::shared_ptr<Moon> moon: planet->getMoons())
            {
                glPushMatrix();
                    glRotatef(radGr(planet->getAngle()),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawMoon(moon,tempo);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

// Função que chama funções relacionadas à câmera
void Space::cameraMoving()
{
    // Movimenta a câmera
    camera->move();

    // Gerencia colisão entre câmera e planeta
    cameraColision();

    // Chama a função que determina o volume da musica
    musicManager->marsMusic(distanceBetweenPlanets(camera->getMidPoint(),planets[1]->getMidPoint()));
}

// Função que calcula a distância entre dois pontos
double Space::distanceBetweenPlanets(Coord a, Coord b)
{
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2) + pow(a.z - b.z,2));
}

// Função que gerencia a colisão entre camera e todos os planetas, incluindo o universo
void Space::cameraColision()
{
    if(distanceBetweenPlanets(sol->getMidPoint(),camera->getMidPoint()) <= 3 + sol->getCoreRadius())
        camera->backPosition();

    if(distanceBetweenPlanets(estrelas->getMidPoint(),camera->getMidPoint()) >= estrelas->getCoreRadius() - 10)
        camera->backPosition();

    for(std::shared_ptr<Planet> planet: planets)
    {
        if(distanceBetweenPlanets(planet->getMidPoint(),camera->getMidPoint()) < 3 + planet->getCoreRadius())
            camera->backPosition();

        for(std::shared_ptr<Moon> moon: planet->getMoons())
        {
            if(distanceBetweenPlanets(moon->getMidPoint(),camera->getMidPoint()) < 2 + moon->getCoreRadius())
                camera->backPosition();
        }
    }
}

// Função que atualiza as propriedades da luz alterando os valores de glLighting de cada fonte de liz
void Space::atualizaPropriedadesLuz()
{
    sol->getLighting()->atualizaPropriedadesLuz();
    for(std::shared_ptr<Planet> planet: planets)
        planet->getLighting()->atualizaPropriedadesLuz();
    
}

// Função que desenha o anel de saturno
void Space::drawSaturnRing()
{
    std::shared_ptr<Planet> saturn = planets[2];
    Coord aux = saturn->getMidPoint();

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, texturesId[12]);
            glRotated(-90,1,0,0); // rotaciona para frente para dar mais visibilidade na rotação
            glTranslatef(aux.x,aux.y,aux.z);
            drawCylinder(1.2 * saturn->getCoreRadius(), 1.2 * saturn->getCoreRadius(), 0.3, 400, 400);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//  Função que gerencia desenhos na tela
void Space::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    sol->getLighting()->lightingInfo();
    camera->setupCamera();
    atualizaPropriedadesLuz();

    drawPlanets();
    drawSaturnRing();
    drawCamera(camera);

    glutSwapBuffers();
}

// Função que adiciona os shared_ptr<Planet> ao vecot de planetas de acodo com os construtores baseados nos scripts
void Space::initializePlanets() 
{
    /*
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
    */


    //                  estrelas = std::make_shared<Planet>(texturesId[8], 0, 0, 6000,   0.0,  0,     10);
    //                          sol = std::make_shared<Sol>(texturesId[9], 0, 0,  600,   0.0,  0,      0, GL_LIGHT0, 1, 1, 0.2, 1);
    // 
    // /*terra*/ planets.push_back(std::make_shared<Planet>(texturesId[2], 1, 1,   64,   6.5,  1200, 0.99, GL_LIGHT1, 1, 1, 1));  // tem que desenhar fontes de luz antes pra funcionar
    // /*marte*/ planets.push_back(std::make_shared<Planet>(texturesId[3], 1, 2,   34,   8.0,  2400, 1.03, GL_LIGHT2, 1, 1, 1));
    // /*satur*/ planets.push_back(std::make_shared<Planet>(texturesId[5], 1, 3,  120, 12.25,  6000, 0.45, GL_LIGHT3, 1, 1, 1));
    // /*jupit*/ planets.push_back(std::make_shared<Planet>(texturesId[4], 1, 3,  175,  10.0,  4000, 0.41));
    // /*mercr*/ planets.push_back(std::make_shared<Planet>(texturesId[0], 1, 0,   24,   4.0,   400,    4));
    // /*venus*/ planets.push_back(std::make_shared<Planet>(texturesId[1], 1, 0,   60,   5.0,   800,    6));
    // /*urano*/ planets.push_back(std::make_shared<Planet>(texturesId[6], 1, 3,   85,  14.0,  8000, 0.72));    
    // /*netun*/ planets.push_back(std::make_shared<Planet>(texturesId[7], 1, 3,   77,  16.0, 10000, 0.67));

           estrelas = std::make_shared<Planet>("scripts/estrelas.txt", 0);                      
                   sol = std::make_shared<Sol>("scripts/sol.txt"); 
    planets.push_back(std::make_shared<Planet>("scripts/terra.txt",    1));
    planets.push_back(std::make_shared<Planet>("scripts/marte.txt",    1));
    planets.push_back(std::make_shared<Planet>("scripts/saturno.txt",  1));
    planets.push_back(std::make_shared<Planet>("scripts/jupiter.txt",  0));
    planets.push_back(std::make_shared<Planet>("scripts/mercurio.txt", 0));
    planets.push_back(std::make_shared<Planet>("scripts/venus.txt",    0));
    planets.push_back(std::make_shared<Planet>("scripts/urano.txt",    0));                
    planets.push_back(std::make_shared<Planet>("scripts/netuno.txt",   0));

    camera->setBorder(loadTexture("imagens/border.png"));
}

// Função que gerencia o (des)ligamento das fontes de luz dfe acordo com pressionamento de teclas
void Space::onOffSun()
{
    // (Des)liga as fontes de luz da Terra, Marte, Saturno
    if(buttons[0] && keys->l)
    {
        buttons[0] = 0;

        if(sol->getLighting()->lighGeralLigada) sol->getLighting()->lighGeralLigada = 0;
        else                                sol->getLighting()->lighGeralLigada = 1;

        
        if(sol->getLighting()->lighGeralLigada) 
        {
            glEnable(GL_LIGHT1);
            glEnable(GL_LIGHT2);
            glEnable(GL_LIGHT3);
        }
        else                                
        {
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            glDisable(GL_LIGHT3);
        }   
  
    }

    // (Des)liga as fontes de luz da Terra, Marte, Saturno
    if(buttons[1] && keys->k)
    {       
        buttons[1] = 0;

        if(sol->getLighting()->lightLigada) sol->getLighting()->lightLigada = 0;
        else                                sol->getLighting()->lightLigada = 1;

        if(sol->getLighting()->lightLigada) glEnable(GL_LIGHT0);
        else                                glDisable(GL_LIGHT0);
    }
}

