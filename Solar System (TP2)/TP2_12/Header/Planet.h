#ifndef _PLANET_H
#define _PLANET_H

#include <vector>
#include "CelestialBody.h"
#include "Moon.h"
#include <memory>
#include <GL/freeglut.h>


class Planet : public CelestialBody
{
    private:
        std::vector<std::shared_ptr<Moon>> moons;

    public:
        Planet(){}
        Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod);
        Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod, GLenum glLightConst,
                int alteravel, double d, double m, double e);
        Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod, 
               GLenum glLightConst, double r, double g, double b);

        std::vector<std::shared_ptr<Moon>> getMoons(){return this->moons;}
        void addMooon(std::shared_ptr<Moon> moon){this->moons.push_back(moon);}
};

#endif