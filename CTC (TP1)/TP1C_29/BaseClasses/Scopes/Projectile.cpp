#include "../Header/Projectile.h"

Projectile::Projectile() : MovableEntity()
{
    this->setDisplayListModel(drawDeaultShot);
    this->setOnScreen(GL_TRUE);
    this->setMax(4, 4);
    this->setMin(-4, -4);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint();
    this->setVelocity(3,3);
    this->setAngle(0);
    this->setAngularSpeed(0);
    this->setType(0);
    this->setHp(1);
    this->setDamage(1);
    this->setDefaultFireRate(1);
    this->setOwner(0); 
}

void Projectile::straightMove()
{
    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
}

void Projectile::move() //movimentação geral do projectile
{  
    straightMove();
    this->generalHitBoxMovement();
}
void Projectile::scaleMove(const double& scale){}
