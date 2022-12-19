#include "../Header/Stage.h"

Stage::Stage()
{
    entities.resize(0);
}

Stage::Stage(const int& background)
{
    entities.resize(0);
    this->setBackground(background);
}