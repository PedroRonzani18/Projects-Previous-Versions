#include "../Header/Wave.h"
#include "../../GeneralFiles/Header/globalParameters.h"

std::vector<Enemy> waveCaller(int waveType)
{
    switch (waveType)
    {
    case 1:
        return wave1();
        break;
    
    case 2:
        return wave2();
        break;
    }
    std::vector<Enemy> e; // retorna vazio para função não reclamar >_<
    return e;
}

std::vector<Enemy> wave1()
{
    std::vector<Enemy> aux;
    Enemy e1(1);

    e1.setMidPoint(right + 50, 0);
    aux.push_back(e1);

    e1.setMidPoint(right + 50, 50);
    aux.push_back(e1);

    e1.setMidPoint(right + 50, -50);
    aux.push_back(e1);
    
    return aux;
}

std::vector<Enemy> wave2()
{
    std::vector<Enemy> aux;
    Enemy e1(0);
    e1.setTypeMove(3);

    e1.setMidPoint(0, top + 50);
    aux.push_back(e1);

    e1.setMidPoint(50, top + 50);
    aux.push_back(e1);

    e1.setMidPoint(-50, top + 50);
    aux.push_back(e1);
    
    return aux;
}

