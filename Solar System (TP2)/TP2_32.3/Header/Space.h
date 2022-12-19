#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include "Sol.h"
#include "lighting.h"
#include "MusicManager.h"
#include "Camera.h"
#include "Coord.h"
#include <vector>
#include <memory>

class Space
{
    private:
        std::shared_ptr<Sol> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<std::shared_ptr<Planet>> planets;
        std::shared_ptr<MusicManager> musicManager;
        std::shared_ptr<Camera> camera;

    public:
        Space();    

        void drawPlanets();
        void initializePlanets();

        std::shared_ptr<Sol> getSol(){return this->sol;}

        std::shared_ptr<Planet> getEstrelas(){return this->estrelas;}

        std::shared_ptr<Planet> getPlanet(int i){return planets[i];}
        std::shared_ptr<MusicManager> getMusicManager(){return this->musicManager;}

        std::shared_ptr<Camera> getCamera(){return this->camera;}
        void atualizaPropriedadesLuz();

        void marsMusic(Coord c);
        void display();
        static double distanceBetweenPlanets(Coord a, Coord b);
        void onOffSun();
        void drawSaturnRing();
        void cameraColision();
        void cameraMoving();
};

#endif