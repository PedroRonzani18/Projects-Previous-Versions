#include "../Header/OrderedPair.h"

#include <stdio.h>

OrderedPair::OrderedPair(){
    
}

OrderedPair::OrderedPair(const double& x, const double& y){
    this->setX(x);
    this->setY(y);
}

double OrderedPair::getX(){
    return this->x;
}
void OrderedPair::setX(const double& x){
    this->x = x;
}

double OrderedPair::getY(){
    return this->y;
}
void OrderedPair::setY(const double& y){
    this->y = y;
}