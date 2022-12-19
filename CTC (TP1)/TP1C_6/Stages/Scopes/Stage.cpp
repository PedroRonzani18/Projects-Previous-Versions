#include "../Header/Stage.h"

Stage::Stage()
{}

Stage::Stage(const int& cdStage, const int& background)
{
    this->setCdStage(cdStage);
    this->setBackground(background);
}