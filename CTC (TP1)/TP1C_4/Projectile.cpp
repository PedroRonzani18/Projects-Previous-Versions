#include "Projectile.h"

Projectile::Projectile(double damage, double defaultFireRate, int owner)
{
    this->damage = damage;
    this->defaultFireRate = defaultFireRate;
    this->owner = owner;
}

double Projectile::getDamage()
{
    return this->damage;
}
void Projectile::setDamage(double damage)
{
    this->damage = damage;
}

double Projectile::getDefaultFireRate()
{
    return this->defaultFireRate;
}
void Projectile::setDefaultFireRate(double defaultFireRate)
{
    this->defaultFireRate = defaultFireRate;
}

int Projectile::getOwner()
{
    return this->owner;
}
void Projectile::setOwner(int owner)
{
    this->owner = owner;
}