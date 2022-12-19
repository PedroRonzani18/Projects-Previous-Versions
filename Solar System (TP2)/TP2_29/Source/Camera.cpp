#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>
#include "../Header/drawings.h"

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    midPoint.x = -13.72;
    midPoint.y = 19.44;
    midPoint.z = -20.96;
    
    directionVector.x = 0.02;
    directionVector.y = -0.63;
    directionVector.z = 0.78;

    moveSpeed.x = 0.1;
    moveSpeed.y = 0.1;
    moveSpeed.z = 0.1;

    sensibilidade = 0.007;

    fi = 3.82;
    theta = 4.68;
}

double cossinLaw(double a)
{
    double aux = (2-pow(a,2))/2;
    if(aux <=-1)
        return 0;
    if(aux >= 1)
        return 0; 
    return acos(aux);
}

void Camera::move()
{   
    float deltaX = (mouseCoords_x - previousPosition_x) * sensibilidade;
    float deltaY = (mouseCoords_y - previousPosition_y) * sensibilidade;

    int signal_x = 0, signal_y = 0;

    if(deltaX > 0) signal_x = 1;
    else if(deltaX < 0) signal_x = -1;

    if(deltaY > 0) signal_y = 1;
    else if(deltaY< 0) signal_y = -1;

    previousPosition_x = mouseCoords_x;
    previousPosition_y = mouseCoords_y;

    theta += signal_x * cossinLaw(deltaX);
    fi += signal_y * cossinLaw(deltaY);

    if(tempo > 0.5)
    {
        if(fi < 1.60) fi = 1.60;
        if(fi > 4.7) fi = 4.7;
    }

    if(checkMouse)
    {
        directionVector.x = cos(theta)*cos(fi);
        directionVector.y = sin(fi);
        directionVector.z = sin(theta)*cos(fi);
    }

    midPoint.x += moveSpeed.x * ((keys->w - keys->s) * directionVector.x + (keys->d - keys->a) * (-directionVector.z)); 
    midPoint.y += moveSpeed.y * ( keys->w - keys->s) * directionVector.y ; 
    midPoint.z += moveSpeed.z * ((keys->w - keys->s) * directionVector.z + (keys->d - keys->a) * (directionVector.x)); // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed                     

}

void Camera::setupCamera()
{
    gluLookAt(midPoint.x                    , midPoint.y                    , midPoint.z                    ,
              midPoint.x + directionVector.x, midPoint.y + directionVector.y, midPoint.z + directionVector.z,
              0, 1, 0);
}

void Camera::movimentation()
{
    //setupCamera();
    move();
}