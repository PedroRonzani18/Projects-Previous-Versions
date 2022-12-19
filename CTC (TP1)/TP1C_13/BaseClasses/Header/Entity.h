#ifndef _ENTITY_H
#define _ENTITY_H

#include <GL/freeglut.h>
#include <stdbool.h>
#include <vector>
#include "OrderedPair.h"
#include "../../GenaralFiles/Header/globalParameters.h"

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

        int getDisplayListModel(){return this->displayListModel;}
        void setDisplayListModel(void model());

        GLboolean getOnScreen(){return this->onScreen;}
        void setOnScreen(const GLboolean& onScreen){this->onScreen = onScreen;}

        OrderedPair& getMidPoint() {return this->midPoint;}

        void setMidPoint(const OrderedPair& midpoint){this->midPoint = midPoint;}
        void setMidPoint(double x, double y){this->midPoint.setX(x); this->midPoint.setY(y);}
        void setMidPoint(){this->midPoint.setX((this->max.getX() + this->min.getX())/2); this->midPoint.setY((this->max.getY() + this->min.getY())/2);}

        OrderedPair& getMax(){return this->max;}
        void setMax(const OrderedPair& max){this->max = max;}
        void setMax(double x, double y){this->max.setX(x); this->max.setY(y);}

        OrderedPair& getMin(){return this->min;}
        void setMin(const OrderedPair& min){this->min = min;}
        void setMin(double x, double y){this->min.setX(x); this->min.setY(y);}
        
        std::vector<OrderedPair> getHitbox(){return this->hitbox;}
        void setHitbox();

        double getResize(){return this->resize;}
        void setResize(const double& resize){this->resize = resize;}
};

#endif