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

void Entity::setHitbox(const std::vector<OrderedPair> &hitbox){
        if(this->hitbox.size() == 4)
                this->hitbox = hitbox;
}

void Entity::push_backHitbox(const OrderedPair& pair){
        if(this->hitbox.size() < 4)
                hitbox.push_back(pair);
}
