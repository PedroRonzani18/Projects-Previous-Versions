#include "../Header/Sol.h"
#include <stdio.h>
#include "../Header/Parser.h"
#include "../Header/drawings.h"

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
}

Sol::Sol(const char* planetName)
{
    Parser aux = Parser::parseSun(planetName);

    this->d = aux.d;
    this->m = aux.m;
    this->e = aux.e;

    const char* arquivo = aux.texture;

    this->texture = loadTexture(arquivo);
    this->dependsOnLight = aux.dependsOnLight;
    this->coreRadius = aux.coreRadius/113.0;
    this->rotationRadius = 1.7 * aux.rotationRadius;
    this->translationPeriod = aux.translationPeriod;
    this->rotationPeriod = aux.rotationPeriod;
    this->midPoint.x = 0;
    this->midPoint.y = 0;
    this->midPoint.z = rotationRadius;

    double translationSpeed, angularSpeed;

    if(translationPeriod != 0) translationSpeed = 306.0 / this->translationPeriod;
    else                       translationSpeed = 0;

    if(rotationPeriod != 0) angularSpeed = 30.0/ this->rotationPeriod;
    else                    angularSpeed = 0;

    this->translationAngularSpeed = translationSpeed;
    this->rotationAngularSpeed = angularSpeed;

    this->lighting = new Lighting(1, d, m, e, GL_LIGHT0);  
    this->hasLight = 1;

    this->material = new Material();

    for(int i=0; i<4; i++)
    {
        this->material->matAmbient[i] = aux.matAmbient[i];
        this->material->matDifuse[i] = aux.matDifuse[i];
        this->material->matEspec[i] = aux.matEspec[i];
    }
    this->material->matShininess = aux.matShininess;
    
}
