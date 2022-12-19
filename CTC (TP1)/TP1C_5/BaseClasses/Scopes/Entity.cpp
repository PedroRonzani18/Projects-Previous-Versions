#include "../Header/Entity.h"
#include <stdio.h>

Entity::Entity(){
        
}

Entity::Entity(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize){
        
    this->setDisplayListModel(displayListModel);
    this->setMax(max);
    this->setMin(min);
    this->setMidPoint();
    this->setResize(resize);

    this->onScreen = false;

    this->hitbox.resize(4);

    this->hitbox[0].setX(this->max.getX());
    this->hitbox[0].setY(this->max.getY());
    this->hitbox[1].setX(this->min.getX());
    this->hitbox[1].setY(this->max.getY());
    this->hitbox[2].setX(this->min.getX());
    this->hitbox[2].setY(this->min.getY());
    this->hitbox[3].setX(this->max.getX());
    this->hitbox[3].setY(this->min.getY());
}

int Entity::getDisplayListModel(){
        return this->displayListModel;
}
void Entity::setDisplayListModel(const int& displayListModel){
        this->displayListModel = displayListModel;
}

GLboolean Entity::getOnScreen(){
        return this->onScreen;
}
void Entity::setOnScreen(const GLboolean& onScreen){
        this->onScreen = onScreen;
}

double Entity::getResize()
{
        return this->resize;
}
void Entity::setResize(const double& resize)
{
        this->resize = resize;
}

OrderedPair& Entity::getMidPoint(){
        return this->midPoint;
}

void Entity::setMidPoint(double x, double y)
{
    this->midPoint.setX(x);
    this->midPoint.setY(y);
}
void Entity::setMidPoint(const OrderedPair& midPoint){
    this->midPoint = midPoint;
}
void Entity::setMidPoint(){
    this->midPoint.setX((this->max.getX() + this->min.getX())/2);
    this->midPoint.setY((this->max.getY() + this->min.getY())/2);
}







OrderedPair& Entity::getMax(){
        return this->max;
}
void Entity::setMax(const OrderedPair& max){
    this->max = max;
}
void Entity::setMax(double x, double y){
        this->max.setX(x);
        this->max.setY(y);
}

OrderedPair& Entity::getMin(){
        return this->min;
}
void Entity::setMin(const OrderedPair& min){
    this->min = min;
}
void Entity::setMin(double x, double y){
        this->min.setX(x);
        this->min.setY(y);
}

std::vector<OrderedPair>& Entity::getHitbox(){
        return this->hitbox;
}
void Entity::setHitbox(const std::vector<OrderedPair> &hitbox){
        if(this->hitbox.size() == 4)
                this->hitbox = hitbox;
}

void Entity::push_backHitbox(const OrderedPair& pair){
        if(this->hitbox.size() < 4)
                hitbox.push_back(pair);
}
