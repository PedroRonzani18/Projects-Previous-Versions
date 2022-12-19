#ifndef _BOSS_H
#define _BOSS_H

#include "Enemy.h"
#include <vector>

class Boss: public Enemy{
    private:
        std::vector<Enemy> enemies;
        Entity healthBar;

    public:
        Boss() = default; // construtor default
        //Enemy* getOneOfEnemies(); // retorna um dos inimigos dentro do boss
                                    // ainda não sei ao certo como implementar

        void addEnemie(Enemy* enemy); // adiciona inimigo ao vector de inimigos
};

#endif