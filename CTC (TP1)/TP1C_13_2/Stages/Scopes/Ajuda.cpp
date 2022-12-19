#include "../Header/Ajuda.h"

Ajuda::Ajuda()
{
}

int Ajuda::stageKeyboard()
{
    if(keys[4]) // volta para o menu
    {
        return 0;
    }else{
        return 1;
    }
}