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
    b1.setDisplayListModel(textures[7]);
    b1.setMidPoint(0,0);

    Background b2;
    b2.setDisplayListModel(textures[9]);
    b2.setMidPoint(0,200);

    backgrounds.push_back(b1);
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

int Level::stageKeyboard()
{
    if(keys[4] && player.getFireRatePeriod() <= 0) //space
    {
        for(Projectile p : getPlayer().fire())
        {
            player.setFireRatePeriod(player.getCurrentProjectile().getDefaultFireRate() * player.getAlteredFireRate());
            //printf("Valor: %.d\n", player.getFireRatePeriod());
            this->addProjectile(p);
        }
    }

    return 2;
}


void Level::remover()
{
    for(int i=0; i<enemies.size(); i++)
    {
        if(!enemies[i].getOnScreen() && enemies[i].getOnscreenTestable()) // se está fora da tela, e é para ser testado, remove ele
            enemies.erase(enemies.begin() + i);
    }

    for(int i=0; i<projectiles.size(); i++)
    {
        if(!projectiles[i].getOnScreen())
            projectiles.erase(projectiles.begin() + i);
    }

    for(int i=0; i<colectibles.size(); i++)
    {
        if(!colectibles[i].getOnScreen())
            colectibles.erase(colectibles.begin() + i);
    }
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
    for(int i = 0; i < getProjectiles().size(); i++)
        verifyVisibility(projectiles[i]);

    for(int i = 0; i < getEnemies().size(); i++){
        verifyVisibility(enemies[i]);
        if(enemies[i].getOnScreen())
            enemies[i].setOnscreenTestable(1); // se ele entrar na tela, começa a verificar sua visibilidade
                                                   // para poder posteriormente remover o inimigo
    }
    
    for(int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<projectiles.size(); i++)
        {
            if(projectiles[i].getOwner() == 1)
            {
                if(colided(projectiles[i], enemies[j]))
                {
                    collisions.push_back(std::make_tuple(1, j, i, NULL));
                }
            }else if(projectiles[i].getOwner() == 2){
                if(colided(projectiles[i], player)){
                    collisions.push_back(std::make_tuple(2, NULL, i, NULL));
                }
            }
        }

        if(colided(enemies[j], player)){
            collisions.push_back(std::make_tuple(3, j, NULL, NULL));
        }
    }

    for(int i=0; i<colectibles.size(); i++){
        if(colided(colectibles[i], player)){
            collisions.push_back(std::make_tuple(4, NULL, NULL, i));
        }
    }

    mantainInsideScreen(player);
    
    if(collisions.size() > 0)
    {
        collisionHandler();
    }

    verifyDeath();
}

void Level::collisionHandler()
{
    //tupla<int, inimigo, projetil, coletavel>
    for(std::tuple<int, int, int, int> t: collisions)
    {
        int posEnemie = std::get<1>(t);
        int posProjectile = std::get<2>(t);
        int posColectibles = std::get<3>(t);

        switch (std::get<0>(t))
        {
        case 1: //colisao dos tiros do player com o inimido
            projectiles.erase(projectiles.begin() + posProjectile);
            enemies[posEnemie].setHp(enemies[posEnemie].getHp() - projectiles[posProjectile].getDamage());
            break;
        
        case 2: //colisao dos tiros dos inimigos com o player
            projectiles.erase(projectiles.begin() + posProjectile);
            player.setHp(player.getHp() - 1);
            break;

        case 3: //colisao dos inimigos com o player
            if(player.getImortality() <= 0) //quando ele nao ta imortal
            {
                player.setHp(player.getHp() - 1);
                printf("%.2f/n", player.getHp());
                enemies[posEnemie].setHp(enemies[posEnemie].getHp() - 5);
                player.setImortality(1000);
                player.setMidPoint(0, -80);
            }
            
            break;
        case 4: //colidiu coletavel com player
            player.upgradeManager(colectibles[posColectibles].getUpgradeType());
            colectibles.erase(colectibles.begin() + posColectibles);
            break;
        }
    }
    collisions.clear();
}

void Level::verifyDeath()
{
    for(int i=0; i<enemies.size(); i++) // confere se vida <=0 (morreu)
    {
        if(enemies[i].getHp() <=0)
        {
            score += enemies[i].getKillValue();
            
            int r = rand()%100;
            printf("R: %d\n",r);

            if(r <= enemies[i].getDropPercentage())
            {
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                colectibles.push_back(c);
                //printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());
            }

            enemies.erase(enemies.begin() + i);
        }
    }

    if(player.getHp() <=0)
    {
        // jogo acaba
    }
}