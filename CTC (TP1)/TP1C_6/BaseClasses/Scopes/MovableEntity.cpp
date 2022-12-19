#include "../Header/MovableEntity.h"

MovableEntity::MovableEntity() : Entity()
{
}

MovableEntity::MovableEntity(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity,
const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType):
Entity(displayListModel,  max, min, resize){
    this->setVelocity(velocity);
    this->setAngle(angle);
    this->setAngularSpeed(angularSpeed);
    this->setHp(hp);
    this->setMoveType(moveType);
    this->setAngularMoveType(angularMoveType);
}

void MovableEntity::move(){}
void MovableEntity::angularMove(){}
void MovableEntity::scaleMove(const double& scale){}