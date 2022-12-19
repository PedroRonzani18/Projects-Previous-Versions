#include "../Header/Stage.h"
#include "../Header/Menu.h"
#include <stdio.h>

Stage::Stage()
{
}

void Stage::setAmmountOfButtons()
{
    this->ammountOfButtons = this->getButtons().size();
}

