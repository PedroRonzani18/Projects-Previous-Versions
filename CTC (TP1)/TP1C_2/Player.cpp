#include "Player.h"
#include <stdio.h>

GLboolean Player::getShield()
{
    return this->shield;
}
void Player::setShield(GLboolean shied)
{
    this->shield = shied;
}

Projectile* Player::fire()
{
    Projectile* aux = new Projectile;
    aux->setOwner(1);

    printf("Fire do player\n");

    return aux;
    
}