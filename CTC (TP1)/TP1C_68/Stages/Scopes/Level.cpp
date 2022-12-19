#include "../Header/Level.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Level::Level(const int &l)
{
    srand(time(0));
    std::vector<int> auxWaves;
    switch (l)
    {
    case 0:
        auxWaves = {1, 1, 1, 5, 5, 0}; // executa todas as waves e para na wave 0
        initBackgrounds(0);
        break;

    case 1:
        auxWaves = {5, 4, 3, 4, 5, 5, 0};
        initBackgrounds(0);
        break;
    }
    player.setMidPoint(0, -80);
    this->addWaves(auxWaves);
    this->scorePontis = Score(0);
}

void Level::initBackgrounds(const int &typeBackground)
{
    switch (typeBackground)
    {
    case 0:
        backgrounds.resize(0);

        Background b1;
        b1.setDisplayListModel(textures[9]);
        b1.setMidPoint(0, 0);
        backgrounds.push_back(b1);

        Background b2;
        b2.setDisplayListModel(textures[10]);
        b2.setMidPoint(0, 200);
        backgrounds.push_back(b2);
        break;
    }
}

void Level::callWaves()
{
    if ((waves.size() > 0) && (enemies.size() == 0))
    {
        for (Enemy e : waveCaller(waves[0]))
            addEnemy(e);
        waves.erase(waves.begin());
    }
}

Enemy *Level::smallestDistanceEnemyPlayer(MovableEntity *m1)
{
    Enemy *auxEnemy = new Enemy();
    auxEnemy->setMidPoint(0, 200);

    double smallesDist = 10000;

    double auxD;

    for (int i = 0; i < enemies.size(); i++)
    {
        auxD = sqrt(pow((m1->getMidPoint().getX() - enemies[i].getMidPoint().getX()), 2) +
                    pow((m1->getMidPoint().getY() - enemies[i].getMidPoint().getY()), 2));

        if (auxD < smallesDist && &enemies[i] != nullptr)
        {
            auxEnemy = &enemies[i];
            smallesDist = auxD;
        }
    }

    return auxEnemy;
}

int Level::stageKeyboard()
{
    if (keys[4] && player.getFireRatePeriod() <= 0) // space
    {
        std::vector<Projectile> p = player.fire();
        projectiles.insert(projectiles.end(), p.begin(), p.end());
    }

    if (player.getHp() < 0)
    {
        player.deathMove();

        if (player.getResize() <= 0) // significa que player morreu e desapareceu da tela
        {
            return 0; // volta para o menu
        }
    }

    if (waves.size() == 0 && player.getHp() >= 0) // se acabaram as waves e o player está vivo, muda de level
    {
        return 2;
    }

    return -1; // chama o level
}

void Level::drawAndMove()
{
    for (int i = 0; i < backgrounds.size(); i++)
    {
        backgrounds[i].move();
        drawModel(&backgrounds[i]);
    }

    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i].move();
        drawModel(&projectiles[i]);
        drawHitbox(&projectiles[i]);
    }

    this->player.move(); // movimentação geral do player

    drawModel(&this->player);
    drawHitbox(&this->player);

    // this->boss.move(); // movimentação geral do boss
    // drawModel(&this->boss);
    // drawHitbox(&this->boss);

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(); // movimentação gerall de cada inimigo
        if(enemies[i].getTypeMove() == 10)
            drawModel(&enemies[i], 3.734, 0);
        else 
            drawModel(&enemies[i]);
            drawHitbox(&enemies[i]);

        //printf("Periodo: %d\n",enemies[i].getFireRatePeriod());

        if (enemies[i].getFireRatePeriod() <= 0)
        {
            std::vector<Projectile> p = enemies[i].fire();
            projectiles.insert(projectiles.end(), p.begin(), p.end());
        }
    }

    // printf("Tamanho: %ld\n",enemies.size());

    for (int i = 0; i < colectibles.size(); i++)
    {
        colectibles[i].move();
        drawModel(&colectibles[i]);
        drawHitbox(&colectibles[i]);
    }

    player.getScoreHp().draw();
    scorePontis.draw();
}

void Level::timeCounter()
{
    if (player.getFireRatePeriod() >= 0)
        player.setFireRatePeriod(player.getFireRatePeriod() - 1);

    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].getFireRatePeriod() >= 0)
            enemies[i].setFireRatePeriod(enemies[i].getFireRatePeriod() - 1);
            enemies[i].setFollowPoint(player.getMidPoint().getX(), player.getMidPoint().getY());
    }

    for (int i = 0; i < projectiles.size(); i++)
    {
        if (projectiles[i].getType() == 2)
        {
            Enemy *e = smallestDistanceEnemyPlayer(&projectiles[i]);
            projectiles[i].setFollowedEnemy(e);   
        }
        else if(projectiles[i].getType() == 5){
            projectiles[i].setFollowedEnemy(&player);   
        }
    }

    if (player.getImortality() >= 0)
        player.setImortality(player.getImortality() - 1);
}

void Level::colider() // proibido.
{
    for (int j = 0; j < enemies.size(); j++)
    {
        for (int i = 0; i < projectiles.size(); i++)
        {
            if (projectiles[i].getOwner() == 1)
            {
                if (colided(projectiles[i], enemies[j])) // colisao dos tiros do player com o inimido
                {
                    projectiles[i].setHp(projectiles[i].getHp() - 1);
                    enemies[j].setHp(enemies[j].getHp() - projectiles[i].getDamage());
                }
            }
            else if (projectiles[i].getOwner() == 2)
            {
                if (colided(projectiles[i], player)) // colisao dos tiros dos inimigos com o player
                {
                    if (player.getImortality() <= 0 && player.getHp() >= 0)
                    {
                        projectiles[i].setHp(projectiles[i].getHp() - 1);
                        player.damage();
                    }
                }
            }
        }

        if (colided(enemies[j], player))
        {                                                           // colisao dos inimigos com o player
            if (player.getImortality() <= 0 && player.getHp() >= 0) // quando ele nao ta imortal
            {
                enemies[j].setHp(enemies[j].getHp() - player.getCurrentProjectile().getDamage() * 7);
                player.damage();
            }
        }
    }

    for (int i = 0; i < colectibles.size(); i++)
    {
        if (colided(colectibles[i], player) && player.getHp() >= 0)
        { // colidiu coletavel com player
            player.upgradeManager(colectibles[i].getUpgradeType());
            colectibles[i].setHp(0);
        }
    }

    remover(); // nao aguento mais corrigir erro de colisao haaaaaaaaaaaaaaaaaa
}

void Level::remover()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        int aux = 0;
        if (enemies[i].getHp() <= 0)
        {
            scorePontis.setScore(scorePontis.getScore() + enemies[i].getKillValue());

            int r = rand() % 100;
            r = 0;
            // printf("R: %d\n",r);

            if (r <= enemies[i].getDropPercentage())
            {
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                mantainInsideScreen(c);
                colectibles.push_back(c);
                // printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());
            }

            aux = 1;
        }

        if (!enemies[i].getOnScreen() && enemies[i].getOnscreenTestable()) // se está fora da tela, e é para ser testado, remove ele
            aux = 1;

        if (aux)
            enemies.erase(enemies.begin() + i);
    }

    for (int i = 0; i < projectiles.size(); i++)
    {
        if (projectiles[i].getHp() <= 0 || !projectiles[i].getOnScreen())
            projectiles.erase(projectiles.begin() + i);
    }

    for (int i = 0; i < colectibles.size(); i++)
    {
        if (colectibles[i].getHp() <= 0 || !colectibles[i].getOnScreen())
            colectibles.erase(colectibles.begin() + i);
    }
}