#include "../Header/Level.h"
#include <stdio.h>

Level::Level() {}

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
    this->player.move();
    this->boss.move();

    for(int i = 0; i < enemies.size(); i++)
        enemies[i].move();

    for(int i=0; i < projectiles.size(); i++)
    {
        projectiles[i].move();
        if(!projectiles[i].getOnScreen())
        {
            this->projectiles.erase(this->projectiles.begin() + i);
        }
    }

    for(int i = 0; i < colectibles.size(); i++)
        colectibles[i].move();
}

void Level::drawEntities()
{
    drawModel(&this->player);
    drawHitbox(&this->player);
    drawModel(&this->boss);
    drawHitbox(&this->boss);
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
        
    mantainInsideScreen(player);
}