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



