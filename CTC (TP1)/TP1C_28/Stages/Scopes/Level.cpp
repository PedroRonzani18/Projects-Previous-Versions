#include "../Header/Level.h"
#include <stdio.h>
#include <stdlib.h>

Level::Level() {}

void Level::callWaves()
{
    if(this->waves.size() > 0)
    {
        for(Enemy e : waveCaller(this->waves[0]))
            this->addEnemy(e);
        this->waves.erase(this->waves.begin());
    }        
}

int Level::stageKeyboard()
{
    if(keys[4]) //space
    {
        for(Projectile p : getPlayer().fire())
        {
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

void Level::movements()
{
    this->player.move(); // movimentação geral do player
    //this->boss.move(); // movimentação geral do boss
    
    for(int i = 0; i < enemies.size(); i++)
        enemies[i].move(); // movimentação gerall de cada inimigo

    for(int i=0; i < projectiles.size(); i++)
        projectiles[i].move();
    
    //printf("Tamanho: %ld\n",enemies.size());

    for(int i = 0; i < colectibles.size(); i++)
        colectibles[i].move();
}

void Level::drawEntities()
{
    drawModel(&this->player);
    drawHitbox(&this->player);
    //drawModel(&this->boss);
    //drawHitbox(&this->boss);

    for (Enemy e : enemies)
    {
        drawModel(&e);
        drawHitbox(&e);
    }

    for (Projectile p : projectiles)
    {
        drawModel(&p);
        drawHitbox(&p);
    }

    for (Colectible c : colectibles)
    {
        drawModel(&c);
        drawHitbox(&c);
    }
}


void Level::player_EnemyProjectileColision()
{
    int colidiuTiroInimigoEPlayer = 0, auxi2;

    for(int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<projectiles.size(); i++)
        {
            if(projectiles[i].getOwner() == 2)
            {
                if(colided(projectiles[i],player))
                {
                    auxi2 = i;
                    colidiuTiroInimigoEPlayer = 1;
                }
            }
        }
    }

    if(colidiuTiroInimigoEPlayer){
        projectiles.erase(projectiles.begin() + auxi2);
        player.setHp(player.getHp() - 1);
    }

} 

void Level::player_EnemyColision()
{
    int colidiuInimigoPlayer = 0, auxi, auxj;

    for(int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<projectiles.size(); i++)
        {
            if(projectiles[i].getOwner() == 1)
            {
                if(colided(projectiles[i],enemies[j]))
                {
                    auxi = i;
                    auxj = j;
                    colidiuInimigoPlayer = 1;
                }
            }
        }
    }

    if(colidiuInimigoPlayer)
    {
        colidiuInimigoPlayer = 0;
        //score += enemies[auxj].getKillValue();
        projectiles.erase(projectiles.begin() + auxi);
        printf("Score: %.2f\n",score);
        //enemies.erase(enemies.begin() + auxj);
        enemies[auxj].setHp(enemies[auxj].getHp() - projectiles[auxi].getDamage());
    }

}

void Level::playerProjectile_EnemyColision()
{
    int colidiuInimigoETiroPlayer = 0, auxj2;

    for(int j=0; j<enemies.size(); j++)
    {        
        if(colided(player,enemies[j]))
        {
            colidiuInimigoETiroPlayer = 1;
            auxj2 = j;
            // apos 4 segundos tira o shield
        }
    }

    if(colidiuInimigoETiroPlayer){
        player.setImortality(1);
        player.setHp(player.getHp() - 1);
        enemies[auxj2].setHp(enemies[auxj2].getHp() - 1);
        printf("Hp: %.2f\n",player.getHp());
    }
}

void Level::player_ColectibleColision()
{
    int colidiuColetavelPlayer = 0, auxi3;

    for(int i=0; i<colectibles.size(); i++)
    {
        if(colided(colectibles[i],player))
        {
            colidiuColetavelPlayer = 1;
            auxi3 = i;
        }
    }

    if(colidiuColetavelPlayer)   {         
        //colectibles.erase(colectibles.begin() + auxi3);4
        printf("Colidiu\n");}
}

void Level::verifyEnemyDeath()
{
    for(int i=0; i<enemies.size(); i++) // confere se vida <=0 (morreu)
    {
        if(enemies[i].getHp() <=0)
        {
            score += enemies[i].getKillValue();

            if(100 >= enemies[i].getDropPercentage())
            {
                //printf("CRIEI\n");
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                colectibles.push_back(c);
                printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());

                //player.upgradeManager(c.getUpgradeType());
            }
            enemies.erase(enemies.begin() + i);
        }
    }
}

void Level::colider()
{
    mantainInsideScreen(player);

    player_EnemyProjectileColision();
    player_EnemyColision();
    playerProjectile_EnemyColision();

    verifyEnemyDeath();

/*
    for(int i=0; i<getProjectiles().size(); i++)
        verifyVisibility(projectiles[i]);

    for(int i=0; i<getEnemies().size(); i++){
        verifyVisibility(enemies[i]);
        if(enemies[i].getOnScreen())
            enemies[i].setOnscreenTestable(1); // se ele entrar na tela, começa a verificar sua visibilidade
                                                   // para poder posteriormente remover o inimigo
    }

    int colidiuInimigoPlayer = 0, auxi, auxj;
    int colidiuInimigoETiroPlayer = 0, auxj2;
    int colidiuTiroInimigoEPlayer = 0, auxi2;
    int colidiuColetavelPlayer = 0, auxi3;

    
    // teste das colisões
    for(int j=0; j<enemies.size(); j++)
    {
        for(int i=0; i<projectiles.size(); i++)
        {
            if(projectiles[i].getOwner() == 1)
            {
                if(colided(projectiles[i],enemies[j]))
                {
                    auxi = i;
                    auxj = j;
                    colidiuInimigoPlayer = 1;
                }
            }

            if(projectiles[i].getOwner() == 2)
            {
                if(colided(projectiles[i],player))
                {
                    auxi2 = i;
                    colidiuTiroInimigoEPlayer = 1;
                }
            }
        }
        
        if(colided(player,enemies[j]))
        {
            colidiuInimigoETiroPlayer = 1;
            auxj2 = j;
            // apos 4 segundos tira o shield
        }
    }

    for(int i=0; i<colectibles.size(); i++)
    {
        if(colided(colectibles[i],player))
        {
            colidiuColetavelPlayer = 1;
            auxi3 = i;
        }
    }


    //tratamento das colisões
    if(colidiuInimigoPlayer)
    {
        colidiuInimigoPlayer = 0;
        //score += enemies[auxj].getKillValue();
        projectiles.erase(projectiles.begin() + auxi);
        printf("Score: %.2f\n",score);
        //enemies.erase(enemies.begin() + auxj);
        enemies[auxj].setHp(enemies[auxj].getHp() - projectiles[auxi].getDamage());
    }

    if(colidiuTiroInimigoEPlayer){
        projectiles.erase(projectiles.begin() + auxi2);
        player.setHp(player.getHp() - 1);
    }

    if(colidiuInimigoETiroPlayer){
        player.setImortality(1);
        player.setHp(player.getHp() - 1);
        enemies[auxj2].setHp(enemies[auxj2].getHp() - 1);
        printf("Hp: %.2f\n",player.getHp());
    }

    if(colidiuColetavelPlayer)   {         
        //colectibles.erase(colectibles.begin() + auxi3);4
        printf("Colidiu\n");}

    for(int i=0; i<enemies.size(); i++) // confere se vida <=0 (morreu)
    {
        if(enemies[i].getHp() <=0)
        {
            score += enemies[i].getKillValue();

            if(100 >= enemies[i].getDropPercentage())
            {
                //printf("CRIEI\n");
                Colectible c(enemies[i].getMidPoint().getX(),
                             enemies[i].getMidPoint().getY());
                colectibles.push_back(c);
                printf("hitbox: %.2f | %.2f\n",c.getHitbox()[3].getX(),c.getHitbox()[3].getY());

                //player.upgradeManager(c.getUpgradeType());
            }
            enemies.erase(enemies.begin() + i);
        }
    }
*/

    if(player.getHp() <=0)
    {
        // jogo acaba
    }
    
}

