#ifndef _AJUDA_H
#define _AJUDA_H

#include "Stage.h"

class Ajuda: public Stage
{
    public:
        Ajuda();

        void stageKeyboard();
        void pressedButton();
};

#endif