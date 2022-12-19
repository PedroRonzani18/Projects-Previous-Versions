#include "../Header/OrderedPair.h"

#include <stdio.h>

OrderedPair::OrderedPair(){
    
}

OrderedPair::OrderedPair(const double& x, const double& y){
    this->setX(x);
    this->setY(y);
}