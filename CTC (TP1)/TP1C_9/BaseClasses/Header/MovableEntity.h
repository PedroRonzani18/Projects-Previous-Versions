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

        OrderedPair& getVelocity(){return velocity;}
        void setVelocity(const OrderedPair& velocity){this->velocity = velocity;}
        void setVelocity(double x, double y){this->velocity.setX(x); this->velocity.setY(y);}

        double getAngle(){return angle;}
        void setAngle(const double& angle){this->angle = angle;}

        double getAngularSpeed(){return angularSpeed;}
        void setAngularSpeed(const double& angularSpeed){this->angularSpeed;}

        double getHp(){return hp;}
        void setHp(const double& hp){this->hp = hp;}

        int getMoveType(){return moveType;}
        void setMoveType(const int& moveType){this->moveType = moveType;}

        int getAngularMoveType(){return angularMoveType;}
        void setAngularMoveType(const int& angularMoveType){this->angularMoveType = angularMoveType;}

        virtual void move(); // movimentação padrão da entidade
        virtual void angularMove(); // movimentação angula padrão da entidade
        virtual void scaleMove(const double& scale); // movimentação usando escala de uma entidade
};

#endif