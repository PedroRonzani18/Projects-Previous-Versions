#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include <vector>
#include "OrderedPair.h"

class Entity{
    public:
        int displayListModel;
        double hp;
        
        GLboolean onScreen;

        OrderedPair midPoint;
        OrderedPair max;
        OrderedPair min;
        std::vector<OrderedPair> hitbox;

    public:
        Entity(int displayListModel, double hp, GLboolean onScreen, OrderedPair midPoint, 
                OrderedPair max,OrderedPair min);

        virtual int getDisplayListModel();
        virtual void setDisplayListModel(int displayListModel);

        virtual GLboolean getOnScreen();
        virtual void setOnScreen(GLboolean onScreen);

        virtual OrderedPair getMidPoint();
        virtual void setMidPoint(double x, double y);

        virtual OrderedPair getMax();
        virtual void setMax(double x, double y);

        virtual OrderedPair getMin();
        virtual void setMin(double x, double y);

        virtual std::vector<OrderedPair> getHitbox();
        virtual void setHitbox(std::vector<OrderedPair> hitbox);
};

#endif