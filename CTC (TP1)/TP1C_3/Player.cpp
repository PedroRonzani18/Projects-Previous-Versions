#include "Player.h"
#include <stdio.h>

Player::Player()
{
    this->setDisplayListModel(0);
    this->setOnScreen(GL_FALSE);
    
    //this->displayListModel = 0;
    //this->onScreen = GL_FALSE;
    
    this->setMax(20,25);
    this->setMin(-20,-30);

    this->setMidPoint((this->getMin().getX() + this->getMax().getX())/2,
                      (this->getMin().getY() + this->getMax().getY())/2);

    //this->setVelocity(1,1);
    
}

GLboolean Player::getShield()
{
    return this->shield;
}
void Player::setShield(GLboolean shied)
{
    this->shield = shied;
}

/*Projectile* Player::fire()
{
    /*Projectile aux;
    aux.setOwner(1);

    printf("Fire do player\n");

    return &aux;
    
}*/