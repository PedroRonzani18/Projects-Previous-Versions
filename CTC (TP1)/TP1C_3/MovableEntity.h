#ifndef _MOVABLEENTITY_H
#define _MOVABLEENTITY_H

#include "Entity.h"
#include "OrderedPair.h"

class MovableEntity: public Entity
{
    private:
        OrderedPair velocity;

        double angle;
        double angularSpeed;
        double hp;

        int moveType;
        int angularMoveType;

    public:
        virtual OrderedPair getVelocity();
        virtual void setVelocity(OrderedPair Velocity);

        virtual double getAngle();
        virtual void setAngle(double angle);

        virtual double getAngularSpeed();
        virtual void setAngularSpeed(double angularSpeed);

        virtual double getHp();
        virtual void setHp(double hp);

        virtual int getMoveType();
        virtual void setMoveType(int moveType);

        virtual int getAngularMoveType();
        virtual void setAngularMoveType(int angularMoveType);

        virtual void move(); // movimentação padrão da entidade
        virtual void angularMove(); // movimentação angula padrão da entidade
        virtual void scaleMove(double scale); // movimentação usando escala de uma entidade
};

#endif