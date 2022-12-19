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
        Boss(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity, 
        const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, 
        const double& alteredFireRate, const Projectile& currentProjectile, const int&  numberOfShots, const double& killValue);
        //Enemy* getOneOfEnemies(); // retorna um dos inimigos dentro do boss
                                    // ainda não sei ao certo como implementar

        
        Enemy& getEnemy(const int& i);
        std::vector<Enemy>& getEnemies();
        void addEnemie(const Enemy& enemy); // adiciona inimigo ao vector de inimigos

        void setHealthBar(const Entity& entity);
        Entity& getHealthBar();

        void setHpBoss();
};


void inicializaBoss()
{
    Boss b;

}

#endif