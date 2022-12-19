#include "../Header/Enemy.h"
#include <stdio.h>

Enemy::Enemy() : MovableEntity()
{}

void Enemy::move(){}
void Enemy::scaleMove(const double& scale){}

std::vector<Projectile> Enemy::fire()
{
    std::vector<Projectile> p;
    return p;
}