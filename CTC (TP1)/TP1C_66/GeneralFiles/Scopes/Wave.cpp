#include "../Header/Wave.h"

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

    case 3:
        return wave3();
        break;

    case 4:
        return wave4();
        break;

    case 5:
        return wave5();
        break;

    case 6:
        return wave6();
        break;
    }
    std::vector<Enemy> e; // retorna vazio para função não reclamar >_<
    return e;
}

Enemy createEnemyTemplate(int type, int typeMove, int numberOfShots,int typeTiroManager, double vx, double vy)
{
    Enemy auxEn(type);
    auxEn.setTypeMove(typeMove);
    auxEn.setNumberOfShots(numberOfShots);
    auxEn.setTypeTiroManager(typeTiroManager);
    auxEn.setVelocity(vx,vy);
    return auxEn;
}

std::vector<Enemy> wave1() // direita esquerda
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(1, 0, 3, 0, 0.5, 1);

    e1.setMidPoint(right + 50, 0);
    aux.push_back(e1);

    e1.setMidPoint(right + 50, 50);
    aux.push_back(e1);

    e1.setMidPoint(right + 50, -50);
    aux.push_back(e1);
    
    return aux;
}

std::vector<Enemy> wave2() // kamikaze
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

std::vector<Enemy> wave3()
{
    std::vector<Enemy>aux;
    Enemy e1 = createEnemyTemplate(2, 4, 1, 2, 0.75, 0.75);

    e1.setMidPoint(0, 320);
    aux.push_back(e1);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 260);
    aux.push_back(e1);

    e1.setMidPoint(0, 240);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 200);
    aux.push_back(e1);

    e1.setMidPoint(0, 180);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    e1.setMidPoint(0, 140);
    aux.push_back(e1);

    e1.setMidPoint(0, 120);
    aux.push_back(e1);

    e1.setTypeMove(5);

    e1.setMidPoint(0, 320);
    aux.push_back(e1);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 260);
    aux.push_back(e1);

    e1.setMidPoint(0, 240);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 200);
    aux.push_back(e1);

    e1.setMidPoint(0, 180);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    e1.setMidPoint(0, 140);
    aux.push_back(e1);

    e1.setMidPoint(0, 120);
    aux.push_back(e1);

    e1.setTypeMove(6);

    e1.setMidPoint(0, 320);
    aux.push_back(e1);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 260);
    aux.push_back(e1);

    e1.setMidPoint(0, 240);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 200);
    aux.push_back(e1);

    e1.setMidPoint(0, 180);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    e1.setMidPoint(0, 140);
    aux.push_back(e1);

    e1.setMidPoint(0, 120);
    aux.push_back(e1);

    return aux;
    
}

std::vector<Enemy> wave4()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(3,4,2,0,0.75,0.75);

    e1.setTypeMove(7);

    e1.setMidPoint(0, 320);
    aux.push_back(e1);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 260);
    aux.push_back(e1);

    e1.setMidPoint(0, 240);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 200);
    aux.push_back(e1);

    e1.setMidPoint(0, 180);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    e1.setMidPoint(0, 140);
    aux.push_back(e1);

    e1.setMidPoint(0, 120);
    aux.push_back(e1);


    e1.setTypeMove(8);

    e1.setMidPoint(0, 320);
    aux.push_back(e1);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    e1.setMidPoint(0, 280);
    aux.push_back(e1);

    e1.setMidPoint(0, 260);
    aux.push_back(e1);

    e1.setMidPoint(0, 240);
    aux.push_back(e1);

    e1.setMidPoint(0, 220);
    aux.push_back(e1);

    e1.setMidPoint(0, 200);
    aux.push_back(e1);

    e1.setMidPoint(0, 180);
    aux.push_back(e1);

    e1.setMidPoint(0, 160);
    aux.push_back(e1);

    e1.setMidPoint(0, 140);
    aux.push_back(e1);

    e1.setMidPoint(0, 120);
    aux.push_back(e1);

    return aux;
}

std::vector<Enemy> wave5()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(4, 9, 5, 1, -0.75, -0.75);

    e1.setMidPoint(0, 0);
    aux.push_back(e1);

    e1.setMidPoint(0, -20);
    aux.push_back(e1);

    e1.setMidPoint(0, -40);
    aux.push_back(e1);

    e1.setMidPoint(0, -60);
    aux.push_back(e1);

    e1.setMidPoint(0, -80);
    aux.push_back(e1);

    e1.setMidPoint(0, -100);
    aux.push_back(e1);

    e1.setMidPoint(0, -120);
    aux.push_back(e1);

    e1.setMidPoint(0, -140);
    aux.push_back(e1);

    e1.setMidPoint(0, -160);
    aux.push_back(e1);

    e1.setMidPoint(0, -180);
    aux.push_back(e1);

    e1.setMidPoint(0, -200);
    aux.push_back(e1);

    return aux;
}

std::vector<Enemy> wave6()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(5, 10, 1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         , 0, 0, 0.2); // torreta que gira
    Enemy e2 = createEnemyTemplate(6, 1, 0, 0, 0, 0.2); // asteroide

    e1.setMidPoint(-50,150);
    e2.setMidPoint(-50,150);
    aux.push_back(e2);
    aux.push_back(e1);

    e1.setAngle(180);
    e1.setMidPoint(50,150);
    e2.setMidPoint(50,150);
    aux.push_back(e2);
    aux.push_back(e1);

    return aux;
}