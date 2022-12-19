#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"
#include <GL/freeglut.h>

class Camera{
    private:
        Coord midPoint;
        Coord directionVector;
        Coord moveSpeed;
        float theta;
        float fi;
        Coord angle;
        int mouseCoords_x, mouseCoords_y;
        int previousPosition_x, previousPosition_y;
        double sensibilidade;
        bool checkMouse;
        GLuint border;

    public:
        Camera();

        Coord getMidPoint(){return this->midPoint;}
        void setMidPoint(Coord midPoint){this->midPoint = midPoint;}

        Coord getDirectionVector(){return this->directionVector;}

        void setAngle(Coord angle){this->angle = angle;}

        void setCheckMouse(bool checkMouse){this->checkMouse = checkMouse;}
        void setMouseCoords(int x, int y){
            mouseCoords_x = x; mouseCoords_y = y;
            setCheckMouse(true);
        }

        float getTheta(){return this->theta;}
        float getFi(){return this->fi;}

        void setBorder(GLuint border){this->border = border;}
        GLuint getBorder(){return this->border;}

        void movimentation();


        void move();
        void setupCamera();
};

#endif