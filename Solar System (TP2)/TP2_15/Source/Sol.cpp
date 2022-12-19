#include "../Header/Sol.h"
#include <stdio.h>

Sol::Sol(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod, GLenum glLightConst,
                int alteravel, double d, double m, double e)
{
    this->d = d;
    this->m = m;
    this->e = e;
    this->texture = texture;
    this->dependsOnLight = dependsOnLight;
    this->coreRadius = coreRadius/113.0;
    this->rotationRadius = 1.7 * rotationRadius;
    this->translationPeriod = translationPeriod;
    this->rotationPeriod = rotationPeriod;
    this->midPoint.x = 0;
    this->midPoint.y = 0;
    this->midPoint.z = rotationRadius;
    this->glLightConst = glLightConst;

    double translationSpeed, angularSpeed;

    if(translationPeriod != 0) translationSpeed = 306.0 / translationPeriod;
    else                       translationSpeed = 0;

    if(rotationPeriod != 0) angularSpeed = 30.0/ rotationPeriod;
    else                    angularSpeed = 0;

    this->translationAngularSpeed = translationSpeed;
    this->rotationAngularSpeed = angularSpeed;

    this->lighting = new Lighting(alteravel, d, m, e, glLightConst);  
    this->hasLight = 1;
    this->hasAtenuation = 0;
}