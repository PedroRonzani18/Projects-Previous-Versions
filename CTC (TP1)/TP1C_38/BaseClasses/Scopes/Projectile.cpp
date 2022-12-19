#include "../Header/Projectile.h"

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
        this->displayListModel = textures[3];
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
        this->displayListModel = textures[3];
        this->onScreen = GL_TRUE;
        this->angle = 0;
        this->angularSpeed = 0;
        this->hp = 1;
        this->damage = 1;
        this->defaultFireRate = 100;
        this->owner = 0; 
        this->setMax(4, 4);
        this->setMin(-4, -4);
        this->setResize(0.5);
        this->setHitbox();
        this->setMidPoint();
        this->setVelocity(3,3);
        break;
    
    case 2:
        this->displayListModel = textures[3];
        this->onScreen = GL_TRUE;
        this->angle = 0;
        this->angularSpeed = 0;
        this->hp = 1;
        this->damage = 1;
        this->defaultFireRate = 120;
        this->owner = 0; 
        this->setMax(4, 4);
        this->setMin(-4, -4);
        this->setResize(0.5);
        this->setHitbox();
        this->setMidPoint();
        this->setVelocity(3,3);
        break;
    }
}

void Projectile::straightMove()
{
    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
}

void Projectile::bouncyMove(){
    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
    this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());
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
    
        break;
    }
    this->generalHitBoxMovement();
}
void Projectile::scaleMove(const double& scale){}
