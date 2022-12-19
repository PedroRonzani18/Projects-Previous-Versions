#ifndef _STAGE_H
#define _STAGE_H

#include "../../BaseClasses/Header/Button.h"
#include "../../BaseClasses/Header/Boss.h"
#include "../../BaseClasses/Header/Projectile.h"
#include "../../BaseClasses/Header/Colectible.h"
#include "../../BaseClasses/Header/Enemy.h"
#include "../../BaseClasses/Header/Player.h"

#include <vector>

class Stage 
{
    protected:
        int ammountOfButtons;
        int background;
        std::vector<int> waves;
        Button focusButton;
        //Boss boss;
        Player player;
        std::vector<Button> buttons;
        std::vector<Enemy> enemies;
        std::vector<Projectile> projectiles;
        std::vector<Colectible> colectibles;

    public:
        Stage();

        virtual int stageKeyboard() = 0;
        virtual void drawAndMove() = 0;
        virtual void colider() = 0;
        virtual void callWaves() = 0;
        virtual void remover() = 0;


        std::vector<int> getWaves(){return this->waves;}
        void addWave(const int& waveId){this->waves.push_back(waveId);}
        int getWave(const int& pos){return waves[pos];}

        int getAmmountOfButtons(){return ammountOfButtons;}
        void setAmmountOfButtons();

        int getBackgound(){return background;}
        void setBackground(const int& background){this->background = background;}

        std::vector<Button> getButtons(){return buttons;}
        void addButton(const Button& b){this->buttons.push_back(b);}
        Entity getButton(const int& pos){return buttons[pos];}

        Button& getFocusButton(){return this->focusButton;}
        void setFocusButton(const Button& focusButton){this->focusButton = focusButton;}

        // Boss& getBoss(){return this->boss;}
        // void setBoss(const Boss& boss){this->boss = boss;}

        Player& getPlayer(){return this->player;}
        void setPlayer(const Player& player){this->player = player;}

        std::vector<Enemy> getEnemies(){return this->enemies;}
        Enemy getEnemy(const int& i){return this->enemies[i];}
        void addEnemy(const Enemy& e){enemies.push_back(e);}

        std::vector<Projectile> getProjectiles(){return this->projectiles;}

        Projectile& getProjectile(const int& i){return  this->projectiles[i];}
        
        void addProjectile(const Projectile& e){projectiles.push_back(e);}
        void removeProjectile(const int& i){this->projectiles.erase(this->projectiles.begin() + i);}

        std::vector<Colectible> getColectibles(){return this->colectibles;}
        Colectible getColectible(const int& i){return this->colectibles[i];}
        void addColectible(const Colectible& e){colectibles.push_back(e);}
};

#endif