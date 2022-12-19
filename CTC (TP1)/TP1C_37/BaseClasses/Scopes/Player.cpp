#include "../Header/Player.h"
#include "../../GeneralFiles/Header/globalParameters.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/drawings.h"
#include "../../GeneralFiles/Header/colisionManager.h"


Player::Player() : MovableEntity(), Ballistic()
{
    this->type = 0;
    this->alteredFireRate = 1;
    this->angle = 0;
    this->angularSpeed = 0;
    this->currentProjectile = Projectile(0);
    this->displayListModel = textures[0];
    this->numberOfShots = 1;
    this->onScreen =GL_TRUE;
    this->imortality = 0;
    this->hp = 3;
    this->fireRatePeriod = 0;

    this->setMax(20,20);
    this->setMin(-20,-20);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint();
    this->setVelocity(1.7,1.7);
    
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

    Projectile projectile1(0);
    projectile1.setOwner(1);

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



void Player::upgradeManager(int upgradeType)
{
    switch (upgradeType)
    {
    case 1: //type 1: aumenta o tanto de tiro 
        if(this->numberOfShots < 3)
            this->numberOfShots += 1;
        printf("numero de tiros: %d\n", this->numberOfShots);
        break;
    
    case 2: //type 2: aumeta o fireRate
        this->alteredFireRate /= 1.17;
        printf("fireRate: %f\n", this->alteredFireRate);
        break;

    case 3: //type 3: troca de projetil
        this->typeTiroManager ++;
        if(this->typeTiroManager == 3) 
            this->typeTiroManager = 0;
        this->currentProjectile = Projectile(typeTiroManager);
        printf("troca de tiro: %f\n", this->alteredFireRate);
        break;

    case 4: //type 4: aumenta vida
        if(this->hp < 3)
            this->hp ++;
        printf("HP: %f\n", this->hp);
        break;

    case 5:  //type 5: aumenta o dano
        this->currentProjectile.setDamage(this->currentProjectile.getDamage() + 5);
        printf("troca de tiro: %f\n", this->currentProjectile.getDamage());
        break;
    }
}
