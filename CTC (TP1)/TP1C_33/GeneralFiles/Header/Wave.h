#ifndef _WAVE_H
#define _WAVE_H

#include <vector>
#include "../../BaseClasses/Header/Enemy.h"

/*
    metodos que settam
        1. tipos de inimigos que serão chamados na wave
        2. posição inicial
        3. quantidade de inimigos

    chamado em uma timer auxiliar
    para serem jogados na tela, tem que ser adicionados no vetor de inimigos do level
*/
    std::vector<Enemy> wave1();
        
    std::vector<Enemy> waveCaller(int waveType);

#endif