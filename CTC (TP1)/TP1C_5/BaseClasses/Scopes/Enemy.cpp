#include "../Header/Enemy.h"
#include <stdio.h>

Enemy::Enemy(){}

Enemy::Enemy(
    const int& displayListModel, const OrderedPair& max, const OrderedPair& min,const double& resize, const OrderedPair& velocity, const double& angle, 
const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, const double& alteredFireRate, 
const Projectile& currentProjectile, const int& numberOfShots, const double& killValue) 
: 
MovableEntity(displayListModel, max, min, resize, velocity, angle, angularSpeed, hp, 
moveType, angularMoveType), 

Ballistic(alteredFireRate, currentProjectile, numberOfShots)
{
    this->killValue = killValue;
}

double Enemy::getKillValue()
{
    return this->killValue;
}
void Enemy::setKillValue(const double& killValue)
{
    this->killValue = killValue;
}

Projectile& Enemy::fire()
{
    Projectile* aux = new Projectile();
    aux->setOwner(2);

    printf("Fire do Enemy\n");

    return *aux;
}