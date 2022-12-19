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

    // CRIAR TIRO DEFAULT
}

Player::Player(
    const int& displayListModel, const OrderedPair& max, const OrderedPair& min,const double& resize, const OrderedPair& velocity, const double& angle, 
const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, const double& alteredFireRate, 
const Projectile& currentProjectile, const int& numberOfShots, const GLboolean& shield) 
: 

MovableEntity(displayListModel, max, min, resize, velocity, angle, angularSpeed, hp, 
moveType, angularMoveType), 

Ballistic(alteredFireRate, currentProjectile, numberOfShots)
{
    
    this->setShield(shield);
}