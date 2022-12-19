#include "../Header/Enemy.h"
#include <stdio.h>

Enemy::Enemy(int type) : MovableEntity()
{
    this->type = type;
    this->onScreen = GL_TRUE;

    
    if(type == 1)
    {
        this->dropPercentage = 10;   
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile();
        this->numberOfShots = 3;
        this->hp = 3;
        this->onscreenTestable = GL_FALSE;  
        this->setDisplayListModel(textures[1]);
        this->setMax(20,20);
        this->setMin(-20,-20);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        this->setHitbox();
        this->setMidPoint();
    }
}

void Enemy::move1()
{
    this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());
}

void Enemy::move()
{
    switch (this->type)
    {
    case 1:
        move1();
        break;
    }
    generalHitBoxMovement();
}
void Enemy::scaleMove(const double& scale){}

std::vector<Projectile> Enemy::fire()
{
    std::vector<Projectile> p;
    return p;
}