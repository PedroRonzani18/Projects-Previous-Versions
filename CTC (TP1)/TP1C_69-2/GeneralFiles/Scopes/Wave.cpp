#include "../Header/Wave.h"
#include <time.h>

std::vector<Enemy> waveCaller(int waveType)
{
    srand(time(0));
    
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
        return waveBasicShipEspiral7();
        break;

    case 8:
        return waveBasicShipTerceiroGrauComTankEliptico8();
        break;

    case 9:
        return waveSegueParabolaBaixa9();
        break;

    case 10:
        return waveSegueParabolaBaixaReversa10();
        break;

    case 11:
        return waveSegueZigZag11();
        break;

    case 12:
        return waveSegue3Parabola12();
        break;

    case 13:
        return waveSegueParabolaAlta13();
        break;

    case 14:
        return waveSegueParabolaAltaReversa14();
        break;

    case 15:
        return waveSegueTerceiroGrauComTankEliptico15();
        break;

    case 16:
        return waveTankBateVolta16();
        break;

    case 17:
        return wave2TanksElipses17();
        break;

    case 18: 
        return waveKamikaseAcelerado18();
        break;

    case 19:
        return waveKamikaseSegue19();
        break;

    case 20:
        return waveSniperSolo20();
        break;

    case 21: 
        return waveSniperSoloComTank21();
        break;

    case 22:
        return waveTorretaReta22(); // carreata do mito??
        break;

    case 23:
        return waveTorretaEliptica23();
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

std::vector<Enemy> waveBasicShipEspiral7() // nao aguento mais fazer essa merda 
{
    std::vector<Enemy> aux;
        Enemy e1 = createEnemyTemplate(3, 7, 2, 0, 1, 1);

        e1.setMidPoint(150, 0);
        aux.push_back(e1);

    return aux;  
}

std::vector<Enemy> waveBasicShipTerceiroGrauComTankEliptico8()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(3, 8, 2, 0, 1, 1);

    Enemy e2 = createEnemyTemplate(4, 9, 5, 1, 0.5, 0.5);

    e2.setMidPoint(150, 0);
    aux.push_back(e2);

    for (int i = 0; i < 90; i++)
    {
        e1.setMidPoint(0, -15*i);
        aux.push_back(e1);
    }
    return aux; 
}

std::vector<Enemy> waveSegueParabolaBaixa9()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(2, 1, 1, 0, 1, 1);

    for (int i = 0; i < 20; i++)
    {
        e1.setMidPoint(-150 - i * 60, 0);
        aux.push_back(e1);
    }
    return aux;
}

std::vector<Enemy> waveSegueParabolaBaixaReversa10()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(2, 1, 1, 0, -1, -1);

    for (int i = 0; i < 20; i++)
    {
        e1.setMidPoint(150 + i * 60, 0);
        aux.push_back(e1);
    }

    return aux;
}

std::vector<Enemy> waveSegueZigZag11()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(2, 2, 1, 0, 1.2, -0.3);

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

std::vector<Enemy> waveSegue3Parabola12()
{
    std::vector<Enemy> aux;
    Enemy e1 = createEnemyTemplate(2, 3, 1, 0, -0.75, -0.75);

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

std::vector<Enemy> waveSegueParabolaAlta13()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(2, 6, 1, 0, 1, 1);

    for (int i = 0; i < 25; i++)
    {
        e1.setMidPoint(-150 - i * 25, 0);
        aux.push_back(e1);
    }
    return aux;
}

std::vector<Enemy> waveSegueParabolaAltaReversa14()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(2, 6, 1, 0, -1, -1);

    for (int i = 0; i < 25; i++)
    {
        e1.setMidPoint(150 + i * 25, 0);
        aux.push_back(e1);
    }
    return aux;
}


std::vector<Enemy> waveSegueTerceiroGrauComTankEliptico15()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(2, 8, 1, 0, 1, 1);

    Enemy e2 = createEnemyTemplate(4, 9, 5, 1, 0.5, 0.5);

    e2.setMidPoint(150, 0);
    aux.push_back(e2);

    for (int i = 0; i < 90; i++)
    {
        e1.setMidPoint(0, -15*i);
        aux.push_back(e1);
    }
    return aux;  
}


std::vector<Enemy> waveTankBateVolta16()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(4, 10, 5, 1, 0.5, -0.5);

    e1.setMidPoint(-50, 150);
    aux.push_back(e1);

    e1.setVelocity(-0.5, -0.5);

    e1.setMidPoint(50, 150);
    aux.push_back(e1);

    return aux;
}

std::vector<Enemy> wave2TanksElipses17()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(4, 11, 5, 1, 0.5, 0.5);
    Enemy e2 = createEnemyTemplate(4, 11, 5, 1, 0.5, 0.5);

    e1.setMidPoint(150, 45);
    aux.push_back(e1);

    e1.setMidPoint(310, 45);
    aux.push_back(e1);

    return aux;  
}

std::vector<Enemy> waveKamikaseAcelerado18()
{
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(0, 12, 0, 0, -2, -2);

    int r;
    for(int i = 0; i < 40; i++){
        r = rand()%17 - 8;
        e1.setMidPoint(10*r, 150 + i*40);
        aux.push_back(e1);
    }
    return aux;  
}

std::vector<Enemy> waveKamikaseSegue19(){
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(0, 13, 0, 0, 1, 1);
    e1.setHp(3);

    e1.setMidPoint(0, 150);
    aux.push_back(e1);

    e1.setMidPoint(80, 150);
    aux.push_back(e1);

    e1.setMidPoint(-80, 150);
    aux.push_back(e1);

    return aux;  
}

std::vector<Enemy> waveSniperSolo20(){
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(1, 14, 1, 3, 1, 1);

    e1.setMidPoint(0, 150);
    aux.push_back(e1);

    return aux; 
}

std::vector<Enemy> waveSniperSoloComTank21(){
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(1, 14, 1, 3, 1, 1);

    Enemy e2 = createEnemyTemplate(4, 15, 5, 1, 0.5, -0.5);

    e2.setMidPoint(0, 150);
    aux.push_back(e2);

    e1.setMidPoint(0, 300);
    aux.push_back(e1);

    return aux; 
}

std::vector<Enemy> waveTorretaReta22(){
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(6, 17, 0, 0, -0.3, -0.3); //asteroide
    Enemy e2 = createEnemyTemplate(5, 16, 1, 0, -0.3, -0.3); //torreta

    e1.setMidPoint(70, 150);
    aux.push_back(e1);

    e2.setMidPoint(70, 150);
    aux.push_back(e2);



    e1.setMidPoint(-70, 150);
    aux.push_back(e1);

    e2.setMidPoint(-70, 150);
    aux.push_back(e2);

    return aux; 
}

std::vector<Enemy> waveTorretaEliptica23(){
    std::vector<Enemy> aux;

    Enemy e1 = createEnemyTemplate(6, 11, 0, 0, -1, -1); //asteroide
    Enemy e2 = createEnemyTemplate(5, 18, 1, 0, -1, -1); //torreta

    e1.setMidPoint(40, 0);
    aux.push_back(e1);

    e2.setMidPoint(40, 0);
    aux.push_back(e2);

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