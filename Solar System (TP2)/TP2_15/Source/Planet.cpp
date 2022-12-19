#include "../Header/Planet.h"
#include "../Header/drawings.h"
#include <stdio.h>
#include "../Header/Coord.h"

/*Planeta sem luz*/
Planet::Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod)
{
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

    switch(numberOfMoons)
    {
        case 3:
            addMooon(std::make_shared<Moon>(240, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
        case 2:
            addMooon(std::make_shared<Moon>(360/numberOfMoons, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
        case 1:
            addMooon(std::make_shared<Moon>(0, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
            break;
    }  

    this->hasLight = 0;
    this->lighting = new Lighting(); 

}

/*Planeta com luz fixa*/
Planet::Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod, 
               GLenum glLightConst, double r, double g, double b)
{
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

    switch(numberOfMoons)
    {
        case 3:
            addMooon(std::make_shared<Moon>(240, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
        case 2:
            addMooon(std::make_shared<Moon>(360/numberOfMoons, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
        case 1:
            addMooon(std::make_shared<Moon>(0, 0.15, this->coreRadius * 1.1 + 0.15, 0.5, 50));
            break;
    }  

    this->lighting = new Lighting(r, g, b, glLightConst);  
    this->hasLight = 1;
}
