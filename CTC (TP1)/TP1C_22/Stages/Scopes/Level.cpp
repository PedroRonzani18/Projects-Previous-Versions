#include "../Header/Level.h"

Level::Level() {}

int Level::stageKeyboard()
{
    this->getPlayer().move();
    return 2;
}

void Level::drawEntities()
{
    drawPlayer();
    drawBoss();
    drawEnemies();
    drawProjectiles();
    drawColectibles();
}
void Level::drawPlayer()
{
    drawModel(&this->getPlayer());
    drawHitbox(&this->getPlayer());
}
void Level::drawBoss()
{
    drawModel(&this->getBoss());
    drawHitbox(&this->getBoss());
}
void Level::drawEnemies()
{
    for (Enemy e : getEnemies()){
        drawModel(&e);
        drawHitbox(&e);
    }
}
void Level::drawProjectiles()
{
    for (Projectile p : getProjectiles()){
        drawModel(&p);
        drawHitbox(&p);
    }
}
void Level::drawColectibles()
{
    for (Colectible c : getColectibles()){
        drawModel(&c);
        drawHitbox(&c);
    }
}

void Level::colider()
{
    insideScreen(getPlayer());
}