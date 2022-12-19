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
    std::pair<const char*,std::vector<float>> aux = Parser::parseSun(planetName);

    this->d = aux.second[7];
    this->m = aux.second[9];
    this->e = aux.second[8];

    const char* arquivo = aux.first;

    this->texture = loadTexture(arquivo);
    this->dependsOnLight = aux.second[0];
    this->coreRadius = aux.second[2]/113.0;
    this->rotationRadius = 1.7 * aux.second[3];
    this->translationPeriod = aux.second[4];
    this->rotationPeriod = aux.second[5];
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

    this->lighting = new Lighting(aux.second[6], d, m, e, GL_LIGHT0);  
    this->hasLight = 1;
}
