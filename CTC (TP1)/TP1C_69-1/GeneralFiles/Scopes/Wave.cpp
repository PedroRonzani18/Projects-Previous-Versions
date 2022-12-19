#include "../Header/Wave.h"

std::vector<Enemy> waveCaller(int waveType)
{
    switch (waveType)
    {
    case 1:
        return waveBasicShipParabolaBaixa1();
        break;

    case 2:
        return waveBasicShipParabolaBaixaReversa2();
        break;

    case 3:
        return waveBasicShipZigZag3();
        break;

    case 4:
        return waveBasicShip3Parabola4();
        break;

    case 5:
        return waveBasicShipParabolaAlta5();
        break;

    case 6:
        return waveBasicShipParabolaAltaReversa6();
        break;

    case 7:
        break;

    case 8:
        return waveBasicShipTerceiroGrauComTankEliptico8();
        break;
    }
    std::vector<Enemy> e; // retorna vazio para função não reclamar >_<
    return e;
}

Enemy createEnemyTemplate(int type, int typeMove, int numberOfShots, int typeTiroManager, double vx, double vy)
{
    Enemy auxEn(type);
    auxEn.setTypeMove(typeMove);
    auxEn.setNumberOfShots(numberOfShots);
    auxEn.setTypeTiroManager(typeTiroManager);
    auxEn.setVelocity(vx, vy);
    return auxEn;
}

std::vector<Enemy> waveBasicShipParabolaBaixa1()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 1, 2, 0, 1, 1);

    for (int i = 0; i < 20; i++)
    {
        e1.setMidPoint(-150 - i * 60, 0);
        aux.push_back(e1);
    }
    return aux;
}

std::vector<Enemy> waveBasicShipParabolaBaixaReversa2()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(3, 1, 2, 0, -1, -1);

    for (int i = 0; i < 20; i++)
    {
        e1.setMidPoint(150 + i * 60, 0);
        aux.push_back(e1);
    }

    return aux;
}

std::vector<Enemy> waveBasicShipZigZag3()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 2, 2, 0, 1.2, -0.3);

    double auxRate = abs(e1.getVelocity().getX() / e1.getVelocity().getY());

    for (int i = 0; i < 15; i++)
    {
        e1.setMidPoint(-150 - i * 20 * auxRate, 150 + i * 20);
        aux.push_back(e1);
    }

    e1.setVelocity(-1.2, -0.3);

    auxRate = abs(e1.getVelocity().getX() / e1.getVelocity().getY());

    for (int i = 0; i < 15; i++)
    {
        e1.setMidPoint(150 + i * 20 * auxRate, 150 + i * 20);
        aux.push_back(e1);
    }

    return aux;
}

std::vector<Enemy> waveBasicShip3Parabola4()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(3, 3, 2, 0, -0.75, -0.75);

    for (int i = 0; i < 13; i++)
    {
        e1.setMidPoint(0, 430 - 30 * i);
        aux.push_back(e1);
    }

    e1.setTypeMove(4);

    for (int i = 0; i < 13; i++)
    {
        e1.setMidPoint(0, 430 - 30 * i);
        aux.push_back(e1);
    }

    e1.setTypeMove(5);

    for (int i = 0; i < 13; i++)
    {
        e1.setMidPoint(0, 430 - 30 * i);
        aux.push_back(e1);
    }
    return aux;
}

std::vector<Enemy> waveBasicShipParabolaAlta5()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 6, 2, 0, 1, 1);

    for (int i = 0; i < 25; i++)
    {
        e1.setMidPoint(-150 - i * 25, 0);
        aux.push_back(e1);
    }
    return aux;
}

std::vector<Enemy> waveBasicShipParabolaAltaReversa6()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 6, 2, 0, -1, -1);

    for (int i = 0; i < 25; i++)
    {
        e1.setMidPoint(150 + i * 25, 0);
        aux.push_back(e1);
    }
    return aux;
}

/*
std::vector<Enemy> espiral7()
{

}
*/


std::vector<Enemy> waveBasicShipTerceiroGrauComTankEliptico8()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 8, 2, 0, 1, 1);

    Enemy e2 = createEnemyTemplate(4, 9, 3, 1, 0.5, 0.5);

    e2.setMidPoint(150, 0);
    aux.push_back(e2);

    for (int i = 0; i < 90; i++)
    {
        e1.setMidPoint(0, -15*i);
        aux.push_back(e1);
    }
    return aux;  
}

/*
std::vector<Enemy> wave1() // sniper solo
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(1, 11, 1, 3, 0.8, 0.5);

    e1.setMidPoint(0, 150);
    aux.push_back(e1);

    return aux;
}
*/

/*
std::vector<Enemy> wave2() // kamikaze que segue
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(0,3,0,0,1,1);

    e1.setMidPoint(0, top + 50);
    aux.push_back(e1);

    e1.setMidPoint(50, top + 50);
    aux.push_back(e1);

    e1.setMidPoint(-50, top + 50);
    aux.push_back(e1);

    return aux;
}
*/

/*
std::vector<Enemy> wave3() // tiro que segue em parabolas
{
    std::vector<Enemy>aux;
    Enemy e1 = createEnemyTemplate(2, 4, 1, 2, 0.75, 0.75);

    for(int i=0; i<11; i++)
    {
        e1.setMidPoint(0, 430-30*i);
        aux.push_back(e1);
    }

    e1.setTypeMove(5);

    for(int i=0; i<11; i++)
    {
        e1.setMidPoint(0, 430-30*i);
        aux.push_back(e1);
    }

    e1.setTypeMove(6);

    for(int i=0; i<11; i++)
    {
        e1.setMidPoint(0, 430-30*i);
        aux.push_back(e1);
    }
    return aux;
}

*/
/*
std::vector<Enemy> wave4() // inimigo simples laser senoide
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(3, 4, 2, 0, 0.75, 0.75);

    e1.setTypeMove(7);

    for(int i=0; i<11; i++)
    {
        e1.setMidPoint(0, 760-60*i);
        aux.push_back(e1);
    }
*/
/*
    e1.setMidPoint(0, 760);
    aux.push_back(e1);

    e1.setMidPoint(0, 700);
    aux.push_back(e1);

    e1.setMidPoint(0, 640);
    aux.push_back(e1);

    e1.setMidPoint(0, 580);
    aux.push_back(e1);

    e1.setMidPoint(0, 520);
    aux.push_back(e1);

    e1.setMidPoint(0, 460);
    aux.push_back(e1);

    e1.setMidPoint(0, 400);
    aux.push_back(e1);

    e1.setMidPoint(0, 340);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);
*/
/*
    e1.setTypeMove(8);

    e1.setMidPoint(0, 760);
    aux.push_back(e1);

    e1.setMidPoint(0, 700);
    aux.push_back(e1);

    e1.setMidPoint(0, 640);
    aux.push_back(e1);

    e1.setMidPoint(0, 580);
    aux.push_back(e1);

    e1.setMidPoint(0, 520);
    aux.push_back(e1);

    e1.setMidPoint(0, 460);
    aux.push_back(e1);

    e1.setMidPoint(0, 400);
    aux.push_back(e1);

    e1.setMidPoint(0, 340);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    return aux;
}

*/
/*
std::vector<Enemy> wave5() // inimigo simples laser funcao ao "cubo"
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(3, 9, 2, 0, -0.5, -0.5);

    Enemy e2 = createEnemyTemplate(4, 2, 3, 1, 0.5, 0.5);

    e2.setMidPoint(150, 0);
    aux.push_back(e2);

    for(int i = 1; i < 50; i++){
        e1.setMidPoint(0, -15*i);
        aux.push_back(e1);
    }


    return aux;
}

*/
/*
std::vector<Enemy> wave6()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(5, 10, 1, 0, 0, 0.5);
    Enemy e2 = createEnemyTemplate(6, 1, 0, 0, 0, 0.5);

    e1.setMidPoint(-50, 150);
    e2.setMidPoint(-50, 150);
    aux.push_back(e2);
    aux.push_back(e1);

    e1.setMidPoint(50, 150);
    e2.setMidPoint(50, 150);
    aux.push_back(e2);
    aux.push_back(e1);

    return aux;
}
*/