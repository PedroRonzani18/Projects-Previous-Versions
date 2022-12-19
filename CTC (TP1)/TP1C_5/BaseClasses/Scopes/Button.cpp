#include "../Header/Button.h"

Button::Button(){}


int Button::getFunctionality()
{
    return this->functionality;
}
void Button::setFunctionality(const int& functionality)
{
    this->functionality = functionality;
}