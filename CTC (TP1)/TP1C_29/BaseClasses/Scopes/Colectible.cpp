#include "../Header/Colectible.h"

Colectible::Colectible() : MovableEntity()
{
    this->upgradeType = 0;
    this->angle = 0;
    this->angularSpeed = 0;
    this->setDisplayListModel(drawEmphassisMenuButton);
    this->setMax(10,10);
    this->setMin(-10,-10);
    this->setResize(4);
    this->setHitbox();
    this->setMidPoint();
    this->setType(0); // gera um tipo entre 1 e 5
    this->setOnScreen(GL_TRUE);
    this->setVelocity(1,1);
    this->setUpgradeType(1 + rand()%5);
    this->hp = 1;;
}

Colectible::Colectible(double midX, double midY) : MovableEntity()
{
    this->upgradeType = 0;
    this->angle = 0;
    this->angularSpeed = 0;
    this->setDisplayListModel(drawEmphassisMenuButton);
    this->setMax(10,10);
    this->setMin(-10,-10);
    this->setResize(1);
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