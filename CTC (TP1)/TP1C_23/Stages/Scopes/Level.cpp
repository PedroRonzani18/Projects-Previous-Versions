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
    this->getPlayer().move();
    this->getBoss().move();

    for(int i = 0; i < getEnemies().size(); i++)
        getEnemy(i).move();

    for(int i=0; i<getProjectiles().size(); i++)
    {
        getProjectile(i).move();
        if(!getProjectile(i).getOnScreen())
        {
            this->removeProjectile(i);
        }
    }
    
    printf("Tamanho: %ld\n",getProjectiles().size());

    for(int i = 0; i < getColectibles().size(); i++)
        getColectible(i).move();
}

void Level::drawEntities()
{
    drawModel(&this->getPlayer());
    drawHitbox(&this->getPlayer());
    drawModel(&this->getBoss());
    drawHitbox(&this->getBoss());
    for (Enemy e : getEnemies()){
        drawModel(&e);
        drawHitbox(&e);
    }
    for (Projectile p : getProjectiles()){
        drawModel(&p);
        drawHitbox(&p);
    }
    for (Colectible c : getColectibles()){
        drawModel(&c);
        drawHitbox(&c);
    }
}

void Level::colider()
{
    for(int i=0; i<getProjectiles().size(); i++)
        verifyVisibility(getProjectile(i));
        
    mantainInsideScreen(getPlayer());
}