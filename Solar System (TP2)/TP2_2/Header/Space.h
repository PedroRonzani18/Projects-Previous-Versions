#ifndef _SPACE_H
#define _SPACE_H

#include "Planet.h"
#include <vector>
#include <memory>

class Space{
    private:
        //Planet sol;
        std::shared_ptr<Planet> sol;
        std::shared_ptr<Planet> estrelas;
        std::vector<std::shared_ptr<Planet>> planets;

        //Planet estrelas;

    public:
        void drawAndMove(double time);
        void initializePlanets();

        std::shared_ptr<Planet> getPlanet(int i){return planets[i];}

        static double distanceBetweenPlanets(Coord a, Coord b);

};

#endif