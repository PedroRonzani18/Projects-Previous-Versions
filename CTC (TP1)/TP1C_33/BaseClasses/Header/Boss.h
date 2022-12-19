#ifndef _BOSS_H
#define _BOSS_H

#include "Enemy.h"
#include <vector>

class Boss: public Enemy{
    private:
        std::vector<Enemy> enemies;
        Entity healthBar;

    public:
        Boss();
        
        Enemy getEnemy(const int& i){return enemies[i];}
        std::vector<Enemy> getEnemies(){return this->enemies;}
        void addEnemie(const Enemy& enemy) {enemies.push_back(enemy);}

        void setHealthBar(const Entity& entity){this->healthBar = entity;}
        Entity getHealthBar(){return this->healthBar;}

        void setHpBoss();
};

#endif