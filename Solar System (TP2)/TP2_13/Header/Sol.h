#ifndef _SOL_H
#define _SOL_H

#include "CelestialBody.h"
#include <GL/freeglut.h>

class Sol : public CelestialBody
{
    public:
        double d,m,e;

        Sol(){}
        Sol(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod, GLenum glLightConst,
                int alteravel, double d, double m, double e);
};

#endif