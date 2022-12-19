#include "../Header/Projectile.h"

Projectile::Projectile() : MovableEntity()
{
    this->setDisplayListModel(drawDeaultShot);
    this->setOnScreen(GL_TRUE);
    this->setMax(4, 4);
    this->setMin(-4, -4);
    this->setMidPoint();
    this->setResize(1);
    this->setHitbox();
    this->setVelocity(1, 1);
    this->setAngle(0);
    this->setAngularSpeed(0);
    this->setType(0);
    this->setHp(1);
    this->setDamage(1);
    this->setDefaultFireRate(1);
    this->setOwner(0); 
}

void Projectile::move(){}
void Projectile::scaleMove(const double& scale){}
