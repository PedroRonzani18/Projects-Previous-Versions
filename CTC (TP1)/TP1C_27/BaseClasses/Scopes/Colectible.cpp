#include "../Header/Colectible.h"

Colectible::Colectible() : MovableEntity()
{
    this->upgradeType = 0;
    this->angle = 0;
    this->angularSpeed = 0;
    this->setDisplayListModel(drawEmphassisMenuButton);
    this->setMax(20,25);
    this->setMin(-20,-30);
    this->setResize(0.5);
    this->setHitbox();
    this->setMidPoint();
    this->setType(1 + rand()%5); // gera um tipo entre 1 e 5
    this->setOnScreen(GL_TRUE);
    this->setVelocity(1,1);
    this->hp = 1;;
}

void Colectible::move(){}
void Colectible::scaleMove(const double& scale){}