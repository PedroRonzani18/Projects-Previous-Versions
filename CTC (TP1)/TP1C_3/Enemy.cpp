#include "Enemy.h"
#include <stdio.h>

double Enemy::getKillValue()
{
    return this->killValue;
}
void Enemy::setKillValue(double killValue)
{
    this->killValue = killValue;
}

Projectile* Enemy::fire()
{
    Projectile* aux = new Projectile;
    aux->setOwner(2);

    printf("Fire do Enemy\n");


    return aux;
}