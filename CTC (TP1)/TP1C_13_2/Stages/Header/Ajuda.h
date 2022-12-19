#ifndef _AJUDA_H
#define _AJUDA_H

#include "Stage.h"
#include "../../GenaralFiles/Header/globalParameters.h"


class Ajuda: public Stage
{
    public:
        Ajuda();
        
        int stageKeyboard() override;
};

#endif