#include "../Header/Colectible.h"

Colectible::Colectible(double midX, double midY) : MovableEntity()
{
    this->upgradeType = 0;
    this->angle = 0;
    this->angularSpeed = 0;
    this->setDisplayListModel(textures[0]);
    this->setMax(10,10);
    this->setMin(-10,-10);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint(midX,midY);
    this->setType(1 + rand()%5); // gera um tipo entre 1 e 5
    this->setOnScreen(GL_TRUE);
    this->setVelocity(1,1);
    this->hp = 1;
}

void Colectible::move()
{
    this->generalHitBoxMovement();

}
void Colectible::scaleMove(const double& scale){}