#include "../Header/Wave.h"
#include "../../GeneralFiles/Header/globalParameters.h"

std::vector<Enemy> waveCaller(int waveType)
{
    switch (waveType)
    {
    case 1:
        return wave1();
        break;
    }
    std::vector<Enemy> e;
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
