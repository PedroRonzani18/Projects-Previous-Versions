#ifndef _FOCUS_H
#define _FOCUS_H

#include "Entity.h"
#include "Button.h"

class Focus: public Entity
{
    private:
        Button focusButton;

    public:

        Focus();
        
        Focus(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize);

        Button& getFocusButton(){return focusButton;}
        void setFocusButton(const Button& focusButton){this->focusButton = focusButton;}
};

#endif