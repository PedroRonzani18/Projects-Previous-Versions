#include "../Header/Level.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Level::Level() 
{
    srand(time(0));
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
    if(keys[4] && player.getAlteredFireRate() <= 0) //space
    {
        for(Projectile p : getPlayer().fire())
        {
            player.setAlteredFireRate(25);
            this->addProjectile(p);
        }
    }
    
    if(player.getAlteredFireRate() >= 0)
        player.setAlteredFireRate(player.getAlteredFireRate() - 8);

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

void Level::player_EnemyProjectileColision()
{
    int colidiuTiroInimigoEPlayer = 0, aux;

    for(int i=0; i<projectiles.size(); i++)
    {
        if(projectiles[i].getOwner() == 2)
        {
            if(colided(projectiles[i],player))
            {
                aux = i;
                colidiuTiroInimigoEPlayer = 1;
            }
        }
    }

    if(colidiuTiroInimigoEPlayer){
        projectiles.erase(projectiles.begin() + aux);
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
                    //myVec.erase(remove(myVec.begin(), myVec.end(), myVec[2]), myVec.end());
                }
            }
        }
    }

    if(colidiuInimigoPlayer)
    {
        projectiles.erase(projectiles.begin() + auxi);
        enemies[auxj].setHp(enemies[auxj].getHp() - projectiles[auxi].getDamage());
    }

}

void Level::playerProjectile_EnemyColision()
{
    int colidiuInimigoETiroPlayer = 0, aux;

    for(int j=0; j<enemies.size(); j++)
    {        
        if(colided(player,enemies[j]))
        {
            colidiuInimigoETiroPlayer = 1;
            aux = j;
            // apos 4 segundos tira o shield
        }
    }

    if(colidiuInimigoETiroPlayer)
    {        
        if(player.getImortality() <= 0) //quando ele nao ta imortal
        {
            player.setHp(player.getHp() - 1);
            enemies[aux].setHp(enemies[aux].getHp() - 5);
            player.setImortality(1000);
            player.setMidPoint(0, -80);
        }

        //printf("Hp: %.0f | IM: %d \n",player.getHp(),player.getImortality());
    }

    if(player.getImortality() >=0)
        player.setImortality(player.getImortality() - 8); // diminui o tempo da imortalidade

    //printf("Hp: %.2f | IM: %d\n",player.getHp(),player.getImortality());
}

void Level::player_ColectibleColision()
{
    int colidiuColetavelPlayer = 0, aux;

    for(int i=0; i<colectibles.size(); i++)
    {
        if(colided(colectibles[i],player))
        {
            printf("Colidiu\n");
            colidiuColetavelPlayer = 1;
            aux = i;
        }
    }

    if(colidiuColetavelPlayer)
    {
        player.upgradeManager(colectibles[aux].getUpgradeType());
        colectibles.erase(colectibles.begin() + aux);
    }
}

void Level::verifyEnemyDeath()
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
}

void Level::colider()
{
    for(int i=0; i<getProjectiles().size(); i++)
        verifyVisibility(projectiles[i]);

    for(int i=0; i<getEnemies().size(); i++){
        verifyVisibility(enemies[i]);
        if(enemies[i].getOnScreen())
            enemies[i].setOnscreenTestable(1); // se ele entrar na tela, começa a verificar sua visibilidade
                                                   // para poder posteriormente remover o inimigo
    }

    mantainInsideScreen(player);

    player_EnemyProjectileColision();
    player_EnemyColision();
    playerProjectile_EnemyColision();
    player_ColectibleColision();

    verifyEnemyDeath();

    if(player.getHp() <=0)
    {
        // jogo acaba
    }
}