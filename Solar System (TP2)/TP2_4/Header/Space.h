#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include "lighting.h"
#include "MusicManager.h"
#include "Coord.h"
#include <vector>
#include <memory>

class Space{
    private:
        //Planet sol;
        std::shared_ptr<Planet> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<std::shared_ptr<Planet>> planets;
        std::shared_ptr<Lighting> light;
        std::shared_ptr<MusicManager> musicManager;

        //Planet estrelas;

    public:
        Space();

        void drawAndMove(double time);
        void initializePlanets();

        std::shared_ptr<Planet> getPlanet(int i){return planets[i];}
        std::shared_ptr<Lighting> getLight(){return this->light;}
        std::shared_ptr<MusicManager> getMusicManager(){return this->musicManager;}

        void marsMusic(Coord c);
        void configuraMateriais();
        void atualizaPropriedadesLuz();
        static double distanceBetweenPlanets(Coord a, Coord b);

};

#endif