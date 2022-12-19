#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"
#include <GL/freeglut.h>

class Camera{
    private:
        Coord3 midPoint;
        Coord3 directionVector;
        Coord3 moveSpeed;
        float theta;
        float fi;
        Coord3 angle;
        int mouseCoords_x, mouseCoords_y;
        int previousPosition_x, previousPosition_y;
        double sensibilidade;
        bool checkMouse;
        GLuint border;

    public:
        Camera();

        Coord3 getMidPoint(){return this->midPoint;}
        void setMidPoint(Coord3 midPoint){this->midPoint = midPoint;}

        Coord3 getDirectionVector(){return this->directionVector;}

        void setAngle(Coord3 angle){this->angle = angle;}

        void setCheckMouse(bool checkMouse){this->checkMouse = checkMouse;}
        void setMouseCoords(int x, int y){
            mouseCoords_x = x; mouseCoords_y = y;
            setCheckMouse(true);
        }

        float getTheta(){return this->theta;}
        float getFi(){return this->fi;}

        void setBorder(GLuint border){this->border = border;}
        GLuint getBorder(){return this->border;}

        void move();
        void setupCamera();
        void backPosition();
};

#endif