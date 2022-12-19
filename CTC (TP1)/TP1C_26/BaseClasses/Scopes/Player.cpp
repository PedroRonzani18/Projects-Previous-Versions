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
    this->setNumberOfShots(3);
    this->setOnScreen(GL_TRUE);
    this->setShield(0);
    this->setVelocity(1,1);
    this->setHp(3);
}

void Player::move()
{   
    this->setMidPoint(this->midPoint.getX() + (keys[2] - keys[3]) * (this->velocity.getX()),
                      this->midPoint.getY() + (keys[0] - keys[1]) * (this->velocity.getY()));
    generalHitBoxMovement();
}

void Player::scaleMove(const double& scale){}

std::vector<Projectile> Player::fire()
{
    std::vector<Projectile> vec;

    Projectile projectile1;

    switch(numberOfShots)
    {
        case 1:
            projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
            vec.push_back(projectile1);
            break;
        case 2:
            projectile1.setMidPoint(12 * cos(this->angle +  M_PI/4) + this->midPoint.getX(),
                                    12 * sin(this->angle +  M_PI/4) + this->midPoint.getY());
            vec.push_back(projectile1);
            projectile1.setMidPoint(12 * cos(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getX(),
                                    12 * sin(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getY());
            vec.push_back(projectile1);
            break;
        case 3:
            projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() + this->max.getY());
            vec.push_back(projectile1);
            projectile1.setMidPoint(12 * cos(this->angle +  M_PI/4) + this->midPoint.getX(),
                                    12 * sin(this->angle +  M_PI/4) + this->midPoint.getY());
            vec.push_back(projectile1);
            projectile1.setMidPoint(12 * cos(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getX(),
                                    12 * sin(this->angle + M_PI/2 + M_PI/4) + this->midPoint.getY());
            
            vec.push_back(projectile1);
            break;
    }

    return vec;
}

