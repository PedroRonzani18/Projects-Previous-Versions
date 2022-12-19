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

        MovableEntity();
        MovableEntity(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize,
        const OrderedPair& velocity, const double& angle, const double& angularSpeed, const double& hp,
        const int& moveType, const int& angularMoveType);

        OrderedPair& getVelocity();
        void setVelocity(const OrderedPair& velocity);
        void setVelocity(double x, double y);


        double getAngle();
        void setAngle(const double& angle);

        double getAngularSpeed();
        void setAngularSpeed(const double& angularSpeed);

        double getHp();
        void setHp(const double& hp);

        int getMoveType();
        void setMoveType(const int& moveType);

        int getAngularMoveType();
        void setAngularMoveType(const int& angularMoveType);

        virtual void move(); // movimentação padrão da entidade
        virtual void angularMove(); // movimentação angula padrão da entidade
        virtual void scaleMove(const double& scale); // movimentação usando escala de uma entidade
};

#endif