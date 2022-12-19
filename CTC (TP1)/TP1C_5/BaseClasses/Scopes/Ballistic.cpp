#include "../Header/Ballistic.h"
#include <stdio.h>

Ballistic::Ballistic()
{}

Ballistic::Ballistic(const double& alteredFireRate, const Projectile& currentProjectile, const int& numberOfShots)
{
    this->setAlteredFireRate(alteredFireRate);
    this->setCurrentProjectile(currentProjectile);
    this->setNumberOfShots(numberOfShots);
}

double Ballistic::getAlteredFireRate()
{
    return this->alteredFireRate;
}
void Ballistic::setAlteredFireRate(const double& alteredFireRate)
{
    this->alteredFireRate = alteredFireRate;
}

Projectile& Ballistic::getCurrentProjectile()
{
    return this->currentProjectile;
}
void Ballistic::setCurrentProjectile(const Projectile& currentProjectile)
{
    this->currentProjectile = currentProjectile;
}

int Ballistic::getNumberOfShots(){
    return this->numberOfShots;
}
void Ballistic::setNumberOfShots(const int& numberOfShots){
    this->numberOfShots = numberOfShots;
}

