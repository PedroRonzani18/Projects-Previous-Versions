#include "../Header/Ajuda.h"

Ajuda::Ajuda(){}

int Ajuda::stageKeyboard()
{
    if(keys[4] && flag) // volta para o menu
    {
        flag = 0;
        return 0;
    }else{
        return 1;
    }
}

void Ajuda::drawAndMove(){}