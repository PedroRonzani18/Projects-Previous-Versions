#include "../Header/Enemy.h"
#include <stdio.h>

Enemy::Enemy(int type) : MovableEntity()
{
    this->type = type;
    this->onScreen = GL_TRUE;
    
    switch (this->type)
    {
        case 0: //torre
            this->dropPercentage = 50;   
            this->killValue = 10;
            this->angle = 0;
            this->angularSpeed = 0;
            this->currentProjectile = Projectile(3);
            this->typeTiroManager = 0;
            this->numberOfShots = 3;
            this->hp = 5;
            this->onscreenTestable = GL_FALSE;
            this->typeMove = 0;
            this->setDisplayListModel(textures[11]);
            this->setMax(20,20);
            this->setMin(-20,-20);
            this->setVelocity(0.5, 1);
            this->setResize(0.5);
            break;

        case 1: // nave
            this->dropPercentage = 50;   
            this->killValue = 10;
            this->angle = 0;
            this->angularSpeed = 0;
            this->currentProjectile = Projectile(3);
            this->typeTiroManager = 0;
            this->numberOfShots = 3;
            this->hp = 5;
            this->onscreenTestable = GL_FALSE;  
            this->typeMove = 0;
            this->setDisplayListModel(textures[11]);
            this->setMax(20,20);
            this->setMin(-20,-20);
            this->setVelocity(0.5, 1);
            this->setResize(0.5);
            break;
    }
    this->setHitbox();
    this->setMidPoint();
}

Projectile Enemy::createProject(Projectile* auxP, double angle)
{
    auxP->setMidPoint(this->max.getX() * cos(this->angle +  angle) + this->midPoint.getX(),
                      this->max.getY() * sin(this->angle +  angle) + this->midPoint.getY());
    return *auxP;
}

void Enemy::move()
{
    switch (this->typeMove)
    {
        case 0: // anda para esquerda
            this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());
            break;

        case 1: // anda para baixo
            this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
            break;

        case 2: // anda para esquerda
            this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());
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
    Projectile projectile1 = this->currentProjectile;

    projectile1.setOwner(2);

    std::vector<Projectile> vec;

    switch (this->typeTiroManager)
    {
        case 0: 
            // projectile1.setMidPoint(this->midPoint.getX(), this->midPoint.getY() - this->min.getY());
            // vec.push_back(projectile1);

            vec.push_back(createProject(&projectile1, 3*M_PI/2));
            break;
        
        case 1: 

            // projectile1.setMidPoint(12 * cos(this->angle +  M_PI/4) - this->midPoint.getX(),
            //                         12 * sin(this->angle +  M_PI/4) - this->midPoint.getY());
            // vec.push_back(projectile1);

            vec.push_back(createProject(&projectile1, -M_PI/4));

            // projectile1.setMidPoint(12 * cos(this->angle + M_PI/2 + M_PI/4) - this->midPoint.getX(),
            //                         12 * sin(this->angle + M_PI/2 + M_PI/4) - this->midPoint.getY());
            // vec.push_back(projectile1);

            vec.push_back(createProject(&projectile1, -3*M_PI/4));
            break;
        
        case 2: 
            // projectile1.setMidPoint(this->midPoint.getX(),this->midPoint.getY() - this->min.getY());
            // vec.push_back(projectile1);
            vec.push_back(createProject(&projectile1, 3*M_PI/2));

            // projectile1.setMidPoint(12 * cos(this->angle) - this->midPoint.getX(),
            //                         12 * sin(this->angle) - this->midPoint.getY());
            // vec.push_back(projectile1);

            vec.push_back(createProject(&projectile1, -M_PI/4));

            // projectile1.setMidPoint(12 * cos(this->angle + M_PI) - this->midPoint.getX(),
            //                         12 * sin(this->angle + M_PI) - this->midPoint.getY());
            // vec.push_back(projectile1);
            
            vec.push_back(createProject(&projectile1, -3*M_PI/4));
            break;
    }

    this->fireRatePeriod = this->currentProjectile.getDefaultFireRate()*3;

    return vec;
}