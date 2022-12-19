#include "../Header/Colectible.h"

Colectible::Colectible(){}

Colectible::Colectible(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
        const int& type) : MovableEntity(displayListModel, max, min, resize, velocity, angle, angularSpeed, hp, moveType, angularMoveType)
{
    this->setType(type);
}

void upgradeManager(Colectible c)
{
    
}