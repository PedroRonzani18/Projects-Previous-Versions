#include "../Header/Player.h"
#include "../../GenaralFiles/Header/globalParameters.h"
#include <stdio.h>
#include "../../GenaralFiles/Header/drawings.h"

Player::Player() : MovableEntity(), Ballistic()
{
    this->setMax(20,25);
    this->setMin(-20,-30);
    this->setVelocity(1,1);
    this->setAngularSpeed(0);
    this->setAngle(37);
    this->setOnScreen(GL_TRUE);
    this->setDisplayListModel(desenhaPlayer);
}

void Player::move()
{   
    this->setMidPoint(this->getMidPoint().getX() + (keys[2] - keys[3]) * (this->getVelocity().getX()),
                      this->getMidPoint().getY() + (keys[0] - keys[1]) * (this->getVelocity().getY()));
}
