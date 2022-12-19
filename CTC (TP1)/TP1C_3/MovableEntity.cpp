#include "MovableEntity.h"

OrderedPair MovableEntity::getVelocity()
{
    return this->velocity;
}
void MovableEntity::setVelocity(OrderedPair velocity)
{
    this->velocity = velocity;
}

double MovableEntity::getAngle()
{
    return this->angle;
}
void MovableEntity::setAngle(double angle)
{
    this->angle = angle;
}

double MovableEntity::getAngularSpeed()
{
    return this->angularSpeed;
}
void MovableEntity::setAngularSpeed(double angularSpeed)
{
    this->angularSpeed = angularSpeed;
}

int MovableEntity::getMoveType()
{
    return this->moveType;
}
void MovableEntity::setMoveType(int moveType)
{
    this->moveType = moveType;
}

int MovableEntity::getAngularMoveType()
{
    return this->angularMoveType;
}
void MovableEntity::setAngularMoveType(int angularMoveType)
{
    this->angularMoveType = angularMoveType;
}

double MovableEntity::getHp()
{
    return this->hp;
}
void MovableEntity::setHp(double hp)
{
    this->hp = hp;
}

void MovableEntity::move(){}
void MovableEntity::angularMove(){}
void MovableEntity::scaleMove(double scale){}