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

Enemy* Level::smallestDistanceEnemyPlayer(MovableEntity* m1)
{
    Enemy *auxEnemy = new Enemy();
    auxEnemy->setMidPoint(0, 200);

    double smallesDist = 10000;
   
    double auxD;

    for(int i=0; i<enemies.size(); i++)
    {
        auxD = sqrt(pow((m1->getMidPoint().getX() - enemies[i].getMidPoint().getX()), 2) + 
                    pow((m1->getMidPoint().getY() - enemies[i].getMidPoint().getY()), 2));

        if(auxD < smallesDist && &enemies[i] != nullptr)
        {
            auxEnemy = &enemies[i];
            smallesDist = auxD;
        }
    }
    
    return auxEnemy;
}

int Level::stageKeyboard()
{
    if(keys[4] && player.getFireRatePeriod() <= 0) //space
    {
        std::vector<Projectile> p = player.fire();
        projectiles.insert(projectiles.end(), p.begin(), p.end());
    }

    for(int i = 0; i < projectiles.size(); i++){
        if(projectiles[i].getType() == 2){
            Enemy *e = smallestDistanceEnemyPlayer(&projectiles[i]);
            projectiles[i].setFollowedEnemy(e);
        }
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

        if(enemies[i].getFireRatePeriod() <= 0){
            std::vector<Projectile> p = enemies[i].fire();
            projectiles.insert(projectiles.end(), p.begin(), p.end());
        }
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
        player.setFireRatePeriod(player.getFireRatePeriod() - 1);

    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i].getFireRatePeriod() >= 0)
            enemies[i].setFireRatePeriod(enemies[i].getFireRatePeriod() - 1);

        //printf("Tempo: %d\n", tempo);

        if(tempo%5 == 0) // roda de 1 em 1 segundos
        {
            if(enemies[i].getTypeMove() == 3)
            {
                //printf("enreiasdasd\n");
                enemies[i].setFollowPoint(player.getMidPoint().getX(), player.getMidPoint().getY());
                //printf("Follow: (%.2f,%.2f)\n",enemies[i].getFollowPoint().getX(),enemies[i].getFollowPoint().getY());
            }
        }
    }

    if(player.getImortality() >= 0)
        player.setImortality(player.getImortality() - 1);

}

void Level::colider() // proibido.
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
                player.setImortality(120);
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

    remover(); // nao aguento mais corrigir erro de colisao haaaaaaaaaaaaaaaaaa
}

void Level::remover()
{
    for(int i=0; i<enemies.size(); i++)
    {
        int aux = 0;
        if(enemies[i].getHp() <= 0)
        {
            score += enemies[i].getKillValue();
            
            int r = rand()%100;
            r = 0;
            //printf("R: %d\n",r);

            if(r <= enemies[i].getDropPercentage())
            {
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                mantainInsideScreen(c);
                colectibles.push_back(c);
                //printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());
            }

            aux = 1;
        }

        if(!enemies[i].getOnScreen() && enemies[i].getOnscreenTestable()) // se está fora da tela, e é para ser testado, remove ele
            aux = 1;

        if(aux)
            enemies.erase(enemies.begin() + i);
    }

    for(int i=0; i<projectiles.size(); i++)
    {
        if(projectiles[i].getHp() <= 0 || !projectiles[i].getOnScreen())
            projectiles.erase(projectiles.begin() + i);
    }

    for(int i=0; i<colectibles.size(); i++)
    {
        if(colectibles[i].getHp() <= 0 || !colectibles[i].getOnScreen())
            colectibles.erase(colectibles.begin() + i);
    }

    if(player.getHp() <=0)
    {
        // jogo acaba
    }
}