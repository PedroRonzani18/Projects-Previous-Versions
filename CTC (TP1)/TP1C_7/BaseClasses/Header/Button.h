#ifndef _BUTTON_H
#define _BUTTON_H

#include "Entity.h"

class Button: public Entity
{
    private:
        int functionality;

    public:

        Button();
        
        int getFunctionality() {return this->functionality;}
        void setFunctionality(const int& functionality) {this->functionality = functionality;}
};

#endif