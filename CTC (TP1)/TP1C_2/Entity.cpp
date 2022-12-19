#include "Entity.h"

#include <vector>
#include <stdio.h>

int Entity::Entity::getDisplayListModel()
{
    return this->displayListModel;
}
void Entity::setDisplayListModel(int displayListModel)
{
    this->displayListModel = displayListModel;
}

GLboolean Entity::getOnScreen()
{
    return this->onScreen;
}
void Entity::setOnScreen(GLboolean onScreen)
{
    this->onScreen = onScreen;
}

OrderedPair Entity::getMidPoint()
{
    return this->midPoint;
}
void Entity::setMidPoint(double x, double y)
{
    this->midPoint.setX(x);
    this->midPoint.setY(y);
}

OrderedPair Entity::getMax()
{
    return this->max;
}
void Entity::setMax(double x, double y)
{
    this->max.setX(x);
    this->max.setY(y);
}

OrderedPair Entity::getMin()
{
    return this->min;
}
void Entity::setMin(double x, double y)
{
    this->min.setX(x);
    this->min.setY(y);
}

std::vector<OrderedPair> Entity::getHitbox()
{
    return this->hitbox;
}
void Entity::setHitbox(std::vector<OrderedPair> hitbox)
{
    this->hitbox = hitbox;
}