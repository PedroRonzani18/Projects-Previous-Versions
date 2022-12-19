#include "../Header/Level.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Level::Level() 
{
    srand(time(0));
    initBackgrounds();
}

void Level::initBackgrounds()
{
    backgrounds.resize(0);

    Background b1;
    b1.setDisplayListModel(textures[9]);
    b1.setMidPoint(0,0);
    backgrounds.push_back(b1);


    Background b2;
    b2.setDisplayListModel(textures[10]);
    b2.setMidPoint(0,200);
    backgrounds.push_back(b2);
}

void Level::callWaves()
{
    if(waves.size() > 0 && enemies.size() == 0)
    {
        for(Enemy e : waveCaller(waves[0]))
            addEnemy(e);
        waves.erase(waves.begin());
    }        
}

Enemy* Level::smallestDistanceEnemyPlayer()
{
    Enemy *auxEnemy;

    double smallesDist = sqrt(pow((player.getMidPoint().getX() - enemies[0].getMidPoint().getX()), 2) + 
                              pow((player.getMidPoint().getY() - enemies[0].getMidPoint().getY()), 2));
    double auxD;

    for(Enemy e : enemies)
    {
        auxD = sqrt(pow((player.getMidPoint().getX() - e.getMidPoint().getX()), 2) + 
                    pow((player.getMidPoint().getY() - e.getMidPoint().getY()), 2));

        printf("auxD: %.2f, Smallest: %.2f\n",auxD,smallesDist);

        if(auxD < smallesDist)
        {
            auxEnemy = &e;
            smallesDist = auxD;
        }
    }

    return auxEnemy;
}

int Level::stageKeyboard()
{
    if(keys[4] && player.getFireRatePeriod() <= 0) //space
    {
        for(int i=0; i<player.fire().size(); i++)
        {
            if(player.fire()[i].getType() == 2)
            {
                player.fire()[i].setFollowedEnemy(smallestDistanceEnemyPlayer());
                printf("SETTED\n");
            }
            this->addProjectile(player.fire()[i]);
        }
/*
        for(Projectile p : getPlayer().fire())
        {
            if(p.getType() == 2){ //Tiro que segue
                p.setFollowedEnemy(&smallestDistanceEnemyPlayer());
            }
            this->addProjectile(p);
        }
*/
    }

    return 2;
}

void Level::drawAndMove()
{
    for(int i=0; i<backgrounds.size(); i++)
    {
        backgrounds[i].move();
        drawModel(&backgrounds[i]);
    }

    //drawBackground2();
    this->player.move(); // movimentação geral do player
    
    drawModel(&this->player);
    drawHitbox(&this->player);

    //this->boss.move(); // movimentação geral do boss
    //drawModel(&this->boss);
    //drawHitbox(&this->boss);

    for(int i = 0; i < enemies.size(); i++){
        enemies[i].move(); // movimentação gerall de cada inimigo
        drawModel(&enemies[i]);
        drawHitbox(&enemies[i]);
    }

    for(int i=0; i < projectiles.size(); i++){
        projectiles[i].move();
        drawModel(&projectiles[i]);
        drawHitbox(&projectiles[i]);
    }
    
    //printf("Tamanho: %ld\n",enemies.size());

    for(int i = 0; i < colectibles.size(); i++){
        colectibles[i].move();
        drawModel(&colectibles[i]);
        drawHitbox(&colectibles[i]);
    }
}

void Level::timeCounter()
{
    if(player.getFireRatePeriod() >= 0)
        player.setFireRatePeriod(player.getFireRatePeriod() - frames);

    if(player.getImortality() >= 0)
        player.setImortality(player.getImortality() - frames);
}

void Level::colider()
{
    for(int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<projectiles.size(); i++)
        {
            if(projectiles[i].getOwner() == 1)
            {
                if(colided(projectiles[i], enemies[j])) //colisao dos tiros do player com o inimido
                {
                    projectiles[i].setHp(projectiles[i].getHp() - 1);
                    enemies[j].setHp(enemies[j].getHp() - projectiles[i].getDamage());
                }
            }else if(projectiles[i].getOwner() == 2){
                if(colided(projectiles[i], player)){ //colisao dos tiros dos inimigos com o player
                    projectiles[i].setHp(projectiles[i].getHp() - 1);
                    player.setHp(player.getHp() - 1);
                }
            }
        }

        if(colided(enemies[j], player)){ //colisao dos inimigos com o player
            if(player.getImortality() <= 0) //quando ele nao ta imortal
            {
                player.setHp(player.getHp() - 1);
                enemies[j].setHp(enemies[j].getHp() - player.getCurrentProjectile().getDamage()*7);
                player.setImortality(1000);
                player.setMidPoint(0, -80);
            }
        }
    }

    for(int i=0; i<colectibles.size(); i++){
        if(colided(colectibles[i], player)){ //colidiu coletavel com player
            player.upgradeManager(colectibles[i].getUpgradeType());
            colectibles[i].setHp(colectibles[i].getHp() -1);
        }
    }

    remover();
}

void Level::remover()
{
    for(int i=0; i<enemies.size(); i++)
    {
        if(enemies[i].getHp() <= 0)
        {
            score += enemies[i].getKillValue();
            
            int r = rand()%100;
            r = 0;
            printf("R: %d\n",r);

            if(r <= enemies[i].getDropPercentage())
            {
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                mantainInsideScreen(c);
                colectibles.push_back(c);
                //printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());
            }

            enemies.erase(enemies.begin() + i);
        }

        if(!enemies[i].getOnScreen() && enemies[i].getOnscreenTestable()) // se está fora da tela, e é para ser testado, remove ele
            enemies.erase(enemies.begin() + i);
    }

    for(int i=0; i<projectiles.size(); i++)
    {
        if(projectiles[i].getHp() <= 0)
            projectiles.erase(projectiles.begin() + i);

        if(!projectiles[i].getOnScreen())
            projectiles.erase(projectiles.begin() + i);
    }

    for(int i=0; i<colectibles.size(); i++)
    {
        if(colectibles[i].getHp() <= 0)
            colectibles.erase(colectibles.begin() + i);

        if(!colectibles[i].getOnScreen())
            colectibles.erase(colectibles.begin() + i);
    }

    if(player.getHp() <=0)
    {
        // jogo acaba
    }
}