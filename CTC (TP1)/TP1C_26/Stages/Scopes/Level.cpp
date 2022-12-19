#include "../Header/Level.h"
#include <stdio.h>

Level::Level() 
{

}

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

void Level::movements()
{
    this->player.move(); // movimentação geral do player
    //this->boss.move(); // movimentação geral do boss

    for(int i = 0; i < enemies.size(); i++){
        enemies[i].move(); // movimentação gerall de cada inimigo
        if(!enemies[i].getOnScreen() && enemies[i].getOnscreenTestable()) // se está fora da tela, e é para ser testado, remove ele
            enemies.erase(enemies.begin() + i);
    }

    for(int i=0; i < projectiles.size(); i++)
    {
        projectiles[i].move();
        if(!projectiles[i].getOnScreen())
            projectiles.erase(projectiles.begin() + i);
    }

    printf("Tamanho: %d\n",enemies.size());

    for(int i = 0; i < colectibles.size(); i++)
        colectibles[i].move();
}

void Level::drawEntities()
{
    drawModel(&this->player);
    drawHitbox(&this->player);
    //drawModel(&this->boss);
    //drawHitbox(&this->boss);
    for (Enemy e : enemies){
        drawModel(&e);
        drawHitbox(&e);
    }
    for (Projectile p : projectiles){
        drawModel(&p);
        drawHitbox(&p);
    }
    for (Colectible c : colectibles){
        drawModel(&c);
        drawHitbox(&c);
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
}

