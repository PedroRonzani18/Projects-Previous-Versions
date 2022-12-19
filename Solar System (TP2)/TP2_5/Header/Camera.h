#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"

class Camera{
    private:
        Coord midPoint;
        Coord directionVector;
        Coord moveSpeed;
        float theta;
        float fi;
        Coord angle;
        int mouseCoords_x, mouseCoords_y;
        Coord previousPosition;
        double sensibilidade;
        bool checkMouse;

    public:
        Camera();

        Coord getMidPoint(){return this->midPoint;}
        void setMidPoint(Coord midPoint){this->midPoint = midPoint;}

        Coord getDirectionVector(){return this->directionVector;}

        Coord getAngle(){return this->angle;}
        void setAngle(Coord angle){this->angle = angle;}

        void setCheckMouse(bool checkMouse){this->checkMouse = checkMouse;}
        void setMouseCoords(int x, int y){
            mouseCoords_x = x; mouseCoords_y = y;
            setCheckMouse(true);
        }

        void movimentation();


        void move();
        void setupCamera();
};

#endif