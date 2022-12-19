#include "../Header/Boss.h"

Boss::Boss(){}

Boss::Boss(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
const double& alteredFireRate, const Projectile& currentProjectile, const int&  numberOfShots, const double& killValue)
:Enemy(displayListModel,  max, min, resize, velocity, 
angle, angularSpeed, hp, moveType, angularMoveType, 
alteredFireRate, currentProjectile, numberOfShots, killValue)
{
    setHpBoss();
    enemies.resize(0);
}


void Boss::setHpBoss(){
    double hp = 0;
    for(Enemy e : enemies){
        hp += e.getHp();
    }
    this->setHp(hp);
}