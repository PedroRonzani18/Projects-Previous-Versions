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

OrderedPair& MovableEntity::getVelocity(){
    return this->velocity;
}
void MovableEntity::setVelocity(const OrderedPair& velocity){
    this->velocity = velocity;
}
void MovableEntity::setVelocity(double x, double y){
    this->velocity.setX(x);
    this->velocity.setY(y);
}

double MovableEntity::getAngle(){
    return this->angle;
}
void MovableEntity::setAngle(const double& angle){
    this->angle = angle;
}

double MovableEntity::getAngularSpeed(){
    return this->angularSpeed;
}
void MovableEntity::setAngularSpeed(const double& angularSpeed){
    this->angularSpeed = angularSpeed;
}

int MovableEntity::getMoveType(){
    return this->moveType;
}
void MovableEntity::setMoveType(const int& moveType){
    this->moveType = moveType;
}

int MovableEntity::getAngularMoveType(){
    return this->angularMoveType;
}
void MovableEntity::setAngularMoveType(const int& angularMoveType){
    this->angularMoveType = angularMoveType;
}

double MovableEntity::getHp(){
    return this->hp;
}
void MovableEntity::setHp(const double& hp){
    this->hp = hp;
}

void MovableEntity::move(){}
void MovableEntity::angularMove(){}
void MovableEntity::scaleMove(const double& scale){}