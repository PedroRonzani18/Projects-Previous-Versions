#ifndef _MOON_H
#define _MOON_H

#include "CelestialBody.h"

class Moon : public CelestialBody
{
    public:
        Moon(){}
        Moon(double angle, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed);
        Moon(const char* planetName, double coreRadius, double angle);
};

#endif