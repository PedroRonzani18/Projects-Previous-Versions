#include "../Header/Projectile.h"
#include <stdio.h>

#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)
#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))


Projectile::Projectile(const int& type) : MovableEntity()
{
    this->type = type;
    
/*
    type 0: tiro padrão
    type 1: bate nas paredes
    type 2: tiro que segue inimigos
*/

    switch (this->type)
    {
        case 0:
            this->displayListModel = textures[1];
            this->onScreen = GL_TRUE;
            this->angle = 0;
            this->angularSpeed = 0;
            this->hp = 1;
            this->damage = 1;
            this->defaultFireRate = 80;
            this->owner = 0; 
            this->setMax(4, 4);
            this->setMin(-4, -4);
            this->setResize(0.5);
            this->setHitbox();
            this->setMidPoint();
            this->setVelocity(3,3);
            break;

        case 1:
            this->displayListModel = textures[6];
            this->onScreen = GL_TRUE;
            this->angle = 0;
            this->angularSpeed = 0;
            this->hp = 1;
            this->damage = 1;
            this->defaultFireRate = 200;
            this->owner = 0; 
            this->setMax(4, 4);
            this->setMin(-4, -4);
            this->setResize(0.5);
            this->setHitbox();
            this->setMidPoint();
            this->setVelocity(2,2);
            break;

        case 2:
            this->displayListModel = textures[3];
            this->onScreen = GL_TRUE;
            this->angle = 0;
            this->angularSpeed = 0;
            this->hp = 1;
            this->damage = 1;
            this->defaultFireRate = 200;
            this->owner = 0; 
            this->setMax(4, 4);
            this->setMin(-4, -4);
            this->setResize(0.5);
            this->setHitbox();
            this->setMidPoint();
            this->setVelocity(1,1);
            break;
    }    
}

void Projectile::straightMove()
{
    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
}

void Projectile::bouncyMove()
{
    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
    this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());

    int i = mantainInsideScreen(*this);

    if(i == 1){
        this->velocity.setY(-this->velocity.getY());
        this->hp--;
    }else if(i == 2){
        this->velocity.setX(-this->velocity.getX());
        this->hp--;
    }
}

void Projectile::folllowMove()
{
    followedEnemy->setMidPoint(0,80);

    double auxAngle = atan((this->midPoint.getY() - followedEnemy->getMidPoint().getY())/
                           (this->midPoint.getX() - followedEnemy->getMidPoint().getX())
                          );

    //double auxAngle = M_PI/4;

    this->angle = auxAngle;

    this->midPoint.setX(midPoint.getX() + (cos(auxAngle) * velocity.getX()));
    this->midPoint.setY(midPoint.getY() + (sin(auxAngle) * velocity.getY()));

    printf("Angulo: %.2f Pe (%.2f,%.2f)  Pp (%.2f,%.2f)\n",radianoParaGraus(auxAngle),midPoint.getX(),midPoint.getY(),followedEnemy->getMidPoint().getX(),followedEnemy->getMidPoint().getY());

//    this->midPoint.setY(midPoint.getY() * sin(auxAngle) * velocity.getY());
    
}

void Projectile::move() //movimentação geral do projectile
{
    switch (this->type)
    {
    case 0:
        straightMove();
        break;
    
    case 1:
        bouncyMove();
        break;

    case 2:
        folllowMove();        
        break;
    }
    verifyVisibility(*this);
    this->generalHitBoxMovement();
}
void Projectile::scaleMove(const double& scale){}
