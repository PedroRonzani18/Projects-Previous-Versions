#include "../Header/Boss.h"

Boss::Boss() : Enemy()
{}

void Boss::setHpBoss(){
    double hp = 0;
    for(Enemy e : enemies){
        hp += e.getHp();
    }
    this->setHp(hp);
}