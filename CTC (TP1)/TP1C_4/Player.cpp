#include "Player.h"
#include <stdio.h>

Player::Player()
{
    this->displayListModel = 0;
    this->onScreen = GL_FALSE;
    this->setMax(20,25);
    this->setMin(-20,-30);

    this->setMidPoint((this->min.getX() + this->max.getX())/2,
                      (this->min.getY() + this->max.getY())/2);
    
}

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