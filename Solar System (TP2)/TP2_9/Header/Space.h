#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include "lighting.h"
#include "MusicManager.h"
#include "Camera.h"
#include "Coord.h"
#include <vector>
#include <memory>

class Space
{
    private:
        std::shared_ptr<Planet> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<std::shared_ptr<Planet>> planets;
        std::vector<std::shared_ptr<Lighting>> lights;
        std::shared_ptr<MusicManager> musicManager;
        std::shared_ptr<Camera> camera;

    public:
        Space();    

        void drawAndMove();
        void initializePlanets();

        std::shared_ptr<Planet> getPlanet(int i){return planets[i];}
        std::shared_ptr<MusicManager> getMusicManager(){return this->musicManager;}

        std::vector<std::shared_ptr<Lighting>> getLights(){return this->lights;}
        std::shared_ptr<Lighting> getLightIndex(int i){return this->lights[i];}
        std::shared_ptr<Camera> getCamera(){return this->camera;}

        void marsMusic(Coord c);
        void display();
        static double distanceBetweenPlanets(Coord a, Coord b);
};

#endif