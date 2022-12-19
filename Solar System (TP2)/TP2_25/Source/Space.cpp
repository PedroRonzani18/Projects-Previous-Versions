#include "../Header/Space.h"
#include "../Header/MusicManager.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include "../Header/lighting.h"
#include <memory>
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

#define FONTE GLUT_BITMAP_8_BY_13

Space::Space()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    camera = std::make_shared<Camera>();
    musicManager = std::make_shared<MusicManager>();
}

// Desenha todos os planetas, Sol, Lua e estredlas
void Space::drawAndMove()
{
    glPushMatrix();
        glRotated(-90,1,0,0); // Rotação no eixo X para melhor visualização dos planetas
        drawCorpse(estrelas,tempo); 
    glPopMatrix();

    glPushMatrix();
        glRotated(-90,1,0,0); // Rotação no eixo X para melhor visualização dos planetas

        glPushMatrix();
            drawCorpse(sol,tempo);
        glPopMatrix();

        for(std::shared_ptr<Planet> planet : planets) 
        {
            glPushMatrix();
                // Determmina o atual angulo do planeta baseado em sua velocidade angular e no tempo.
                planet->setAngle(tempo * planet->getTranslationAngularSpeed());

                // Os planetas realizam uma rotação ao redor do ponto (0,0,0) em tono do eixo x,z.
                // Para isso são usadas coordenadas cilíndricas, em que y sempre será 0.
                planet->setMidPoint(-planet->getRotationRadius() * cos(planet->getAngle()),
                                    0,
                                     planet->getRotationRadius() * sin(planet->getAngle()));
                drawCorpse(planet,tempo);
            glPopMatrix();

            for(std::shared_ptr<Moon> moon: planet->getMoons())
            {
                glPushMatrix();
                    glRotatef(radGr(planet->getAngle()),0,0,1); // rotaciona ao redor do planeta
                    glTranslated(-planet->getRotationRadius(),0, 0); // determina o raio da rotação (e indiretamente o centro de rotação)
                    drawCorpse(moon,tempo);
                glPopMatrix();
            }
        }
    glPopMatrix();
}

// configura o valor da música de acordo com a distância entre Marte e a Câmera
void Space::marsMusic(Coord c)
{
    musicManager->marsMusic(distanceBetweenPlanets(c,planets[1]->getMidPoint()));
}

// Calcula distância entre dois pontos
double Space::distanceBetweenPlanets(Coord a, Coord b)
{
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2) + pow(a.z - b.z,2));
}

void Space::atualizaPropriedadesLuz()
{
    sol->getLighting()->atualizaPropriedadesLuz();

    for(long unsigned int i=0; i<planets.size(); i++)
        planets[i]->getLighting()->atualizaPropriedadesLuz();
}

// Callback de desenho
void Space::display()
{
    // Limpa a cena e o buffer de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Carrega a matriz identidade
    glLoadIdentity();

    sol->getLighting()->lightingInfo();

    // Configura a posição da camera de acordo com seus atributos de posição e vetor direção
    camera->setupCamera();

    // Atualiza as propriedades da luz de todos os planetas
    atualizaPropriedadesLuz();

    // Desenha e movimenta todos os planetas, e as estrelas
    drawAndMove();

    // Desenha o painel da câmera
    drawCamera(camera);

    // Swap Buffers
    glutSwapBuffers();
}

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

           estrelas = std::make_shared<Planet>("scripts/estrelas.txt",0);                      
                   sol = std::make_shared<Sol>("scripts/sol.txt");
    planets.push_back(std::make_shared<Planet>("scripts/terra.txt",1));
    planets.push_back(std::make_shared<Planet>("scripts/marte.txt",1));
    planets.push_back(std::make_shared<Planet>("scripts/saturno.txt",1));
    planets.push_back(std::make_shared<Planet>("scripts/jupiter.txt",0));
    planets.push_back(std::make_shared<Planet>("scripts/mercurio.txt",0));
    planets.push_back(std::make_shared<Planet>("scripts/venus.txt",0));
    planets.push_back(std::make_shared<Planet>("scripts/urano.txt",0));                
    planets.push_back(std::make_shared<Planet>("scripts/netuno.txt",0));

    camera->setBorder(loadTexture("imagens/border.png"));
}

// Função que determidna se a luz do sol está ativada ou desativada
void Space::onOffSun()
{
    if(buttons[0] && keys->l) // Caso a tecla "L" tenha sido pressionada...
    {
        buttons[0] = 0;

        // Altera o valor da flag que detemina se é desenhada a textura do sol
        if(sol->getLighting()->lightLigada) sol->getLighting()->lightLigada = 0;
        else                                sol->getLighting()->lightLigada = 1;

        
        // Liga ou desliga a fonte de luz interior ao Sol
        if(sol->getLighting()->lightLigada) glEnable(GL_LIGHT0);
        else                                glDisable(GL_LIGHT0);
        
    }
}

// Função de inicialização geral
void Space::initialize()
{
    musicManager->configureMusic();
    initializePlanets();
}