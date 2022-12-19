#include "../Header/Focus.h"

Focus::Focus(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize)
:Entity(displayListModel, max, min, resize)
{
}

Button& Focus::getFocusButton()
{
    return this->focusButton;
}
void Focus::setFocusButton(const Button& button)
{
    this->focusButton = button;
}