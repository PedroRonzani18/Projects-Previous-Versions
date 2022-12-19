#include "../Header/Player.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"


Player::Player() : MovableEntity(), Ballistic()
{
    this->setAlteredFireRate(1);
    this->setAngle(0);
    this->setAngularSpeed(0);
    this->setCurrentProjectile(Projectile());
    this->setDisplayListModel(desenhaPlayer);
    this->setMax(20,25);
    this->setMin(-20,-30);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint();
    this->setType(0);
    this->setNumberOfShots(1);
    this->setOnScreen(GL_TRUE);
    this->setShield(0);
    this->setVelocity(1,1);
    this->setHp(3);
}

void Player::move()
{   
    this->setMidPoint(this->getMidPoint().getX() + (keys[2] - keys[3]) * (this->getVelocity().getX()),
                      this->getMidPoint().getY() + (keys[0] - keys[1]) * (this->getVelocity().getY()));
    generalHitBoxMovement();
}
void Player::scaleMove(const double& scale){}

std::vector<Projectile> Player::fire()
{
    std::vector<Projectile> vec;
    if(getNumberOfShots() == 1)
    {
        Projectile projectile;
        projectile.setMidPoint(this->getMidPoint().getX() , this->getMidPoint().getY() + this->getMax().getY());
        vec.push_back(projectile);
    }
    return vec;
}

