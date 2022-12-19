#include "../Header/Moon.h"
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"

Moon::Moon(double angle, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed)
{
    this->angle = angle;
    this->texture = texturesId[10];
    this->coreRadius = coreRadius;
    this->rotationRadius = rotationRadius;
    this->translationAngularSpeed = translationAngularSpeed;
    this->rotationAngularSpeed = rotationAngularSpeed;
    this->lighting = new Lighting();
    this->hasLight = 0;
}

Moon::Moon(const char* planetName, double coreRadius, double angle)
{
    Parser aux = Parser::parseMoon(planetName);

    this->angle = angle;
    this->texture = texturesId[10];
    this->coreRadius = aux.coreRadius;
    this->rotationRadius = aux.coreRadius + 1.1 * coreRadius;
    this->translationAngularSpeed = aux.translationPeriod;
    this->rotationAngularSpeed = aux.rotationPeriod;
    this->lighting = new Lighting();
    this->hasLight = 0;
}