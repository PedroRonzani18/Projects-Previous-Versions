#include "../Header/Projectile.h"

Projectile::Projectile(){}

Projectile::Projectile(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize, const OrderedPair& velocity,
const double& angle, const double& angularSpeed, const double& hp, const int& moveType, const int& angularMoveType, const double& damage, 
const double& defaultFireRate, const int& owner) : MovableEntity(displayListModel, max, min, resize, velocity, angle, angularSpeed, hp, moveType,
angularMoveType)
{
    this->setDamage(damage);
    this->setDefaultFireRate(defaultFireRate);
    this->setOwner(owner);
}

double Projectile::getDamage()
{
    return this->damage;
}
void Projectile::setDamage(const double& damage)
{
    this->damage = damage;
}

double Projectile::getDefaultFireRate()
{
    return this->defaultFireRate;
}
void Projectile::setDefaultFireRate(const double& defaultFireRate)
{
    this->defaultFireRate = defaultFireRate;
}

int Projectile::getOwner()
{
    return this->owner;
}
void Projectile::setOwner(const int& owner)
{
    this->owner = owner;
}