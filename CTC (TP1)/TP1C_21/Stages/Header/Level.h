#ifndef _LEVEL_H
#define _LEVEL_H

#include "../../BaseClasses/Header/Player.h"
#include "../../BaseClasses/Header/Enemy.h"
#include "../../BaseClasses/Header/Colectible.h"
#include "../../BaseClasses/Header/Boss.h"

#include "Stage.h"
#include <stdbool.h>

class Level: public Stage
{
    private:
        double score;
        Boss boss;
        Player player;
        std::vector<Enemy> enemies;
        std::vector<Projectile> projectiles;
        std::vector<Colectible> colectibles;

    public:
        Level();
        
        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}

        Boss getBoss(){return this->boss;}
        void setBoss(const Boss& boss){this->boss = boss;}

        Player getPlayer(){return this->player;}
        void setPlayer(const Player& player){this->player = player;}

        std::vector<Enemy> getEnemies(){return this->enemies;}
        Enemy getEnemy(const int& i){return this->enemies[i];}
        void addEnemy(const Enemy& e){enemies.push_back(e);}

        std::vector<Projectile> getProjectiles(){return this->projectiles;}
        Projectile getProjectile(const int& i){return this->projectiles[i];}
        void addProjectile(const Projectile& e){projectiles.push_back(e);}

        std::vector<Colectible> getColectibles(){return this->colectibles;}
        Colectible getColectible(const int& i){return this->colectibles[i];}
        void addColectible(const Colectible& e){colectibles.push_back(e);}
        
        int stageKeyboard() override;
        void backgroundMove();
};


#endif