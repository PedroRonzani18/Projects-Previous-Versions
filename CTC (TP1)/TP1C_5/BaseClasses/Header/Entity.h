#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include <vector>
#include "OrderedPair.h"

class Entity{
    private:
        int displayListModel;
        GLboolean onScreen;
        OrderedPair midPoint;
        OrderedPair max;
        OrderedPair min;
        std::vector<OrderedPair> hitbox;
        double resize;

    public:
        Entity();

        Entity(const int& displayListModel, const OrderedPair& max, const OrderedPair& min, const double& resize);

        int getDisplayListModel();
        void setDisplayListModel(const int& displayListModel);

        GLboolean getOnScreen();
        void setOnScreen(const GLboolean& onScreen);

        OrderedPair& getMidPoint();
        void setMidPoint(const OrderedPair& midpoint);
        void setMidPoint(double x, double y);
        void setMidPoint();

        OrderedPair& getMax();
        void setMax(const OrderedPair& max);
        void setMax(double x, double y);

        OrderedPair& getMin();
        void setMin(const OrderedPair& min);
        void setMin(double x, double y);

        std::vector<OrderedPair>& getHitbox();
        void setHitbox(const std::vector<OrderedPair> &hitbox);

        double getResize();
        void setResize(const double& resize);

        void push_backHitbox(const OrderedPair& pair);
};

#endif