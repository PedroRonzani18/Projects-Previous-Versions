#ifndef _BUTTON_H
#define _BUTTON_H

#include "Entity.h"
#include "Focus.h"

class Button: public Entity
{
    private:
        int functionality;

    public:

        Button();
        
        int getFunctionality();
        void setFunctionality(const int& functionality);
};

#endif