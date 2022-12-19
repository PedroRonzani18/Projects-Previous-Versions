#include "../Header/Enemy.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/globalParameters.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

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
            this->continueMove = 0;
            this->setDisplayListModel(textures[11]);
            this->setMax(20,20);
            this->setMin(-20,-20);
            this->setVelocity(1, 1);
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
            this->continueMove = 0;
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

void Enemy::move3()
{
    if(continueMove < 200)
    {
        double angle = atan2(this->followPoint.getY() - this->midPoint.getY(),
                            this->followPoint.getX() - this->midPoint.getX());

        this->angle = radianoParaGraus(angle)-90;

        this->midPoint.setX(this->midPoint.getX() + cos(angle) * this->velocity.getX());
        this->midPoint.setY(this->midPoint.getY() + sin(angle) * this->velocity.getY());
        
        this->continueMove ++;
    }
    else
    {
        this->midPoint.setX(this->midPoint.getX() + cos(grausParaRadianos(this->angle) + M_PI/2) * this->velocity.getX() * 2);
        this->midPoint.setY(this->midPoint.getY() + sin(grausParaRadianos(this->angle) + M_PI/2) * this->velocity.getY() * 2);
    }

    printf("%d\n", this->continueMove);
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

        case 3: // Segue mas com deley
            move3();
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
        case 0: //nao atira
            break;
        case 1: 
            vec.push_back(createProject(&projectile1, 3*M_PI/2));
            break;
        
        case 2: 
            vec.push_back(createProject(&projectile1, -M_PI/4));
            vec.push_back(createProject(&projectile1, -3*M_PI/4));
            break;
        
        case 3: 
            vec.push_back(createProject(&projectile1, 3*M_PI/2));
            vec.push_back(createProject(&projectile1, -M_PI/4));
            vec.push_back(createProject(&projectile1, -3*M_PI/4));
            break;
    }

    this->fireRatePeriod = this->currentProjectile.getDefaultFireRate()*3;

    return vec;
}