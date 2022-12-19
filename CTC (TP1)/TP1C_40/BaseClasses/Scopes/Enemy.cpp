#include "../Header/Enemy.h"
#include <stdio.h>

Enemy::Enemy(int type) : MovableEntity()
{
    this->type = type;
    this->onScreen = GL_TRUE;
    
    if(type == 1)
    {
        this->dropPercentage = 50;   
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile();
        this->numberOfShots = 3;
        this->hp = 2;
        this->onscreenTestable = GL_FALSE;  
        this->typeMove = 0;
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
    switch (this->typeMove)
    {
    case 0:
        move1();
        break;
    }
    
    verifyVisibility(*this);
        if(this->onScreen)
            this-> onscreenTestable = 1;

    generalHitBoxMovement();
}

void Enemy::scaleMove(const double& scale){}

std::vector<Projectile> Enemy::fire()
{
    std::vector<Projectile> p;
    return p;
}