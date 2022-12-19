#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    midPoint.x = -33.57;
    midPoint.y = 19.86;
    midPoint.z = 3.67;
    
    directionVector.x = 0.76;
    directionVector.y = -0.63;
    directionVector.z = 0.14;

    moveSpeed.x = 0.1;
    moveSpeed.y = 0.1;
    moveSpeed.z = 0.1;

    sensibilidade = 0.007;

    fi = 3.9;
    theta = 21.89;
}

void Camera::move()
{
    float offset_x = (xMouse - previousPosition.x) * sensibilidade;
    float offset_y = (yMouse - previousPosition.y) * sensibilidade;

    previousPosition.x = xMouse;
    previousPosition.y = yMouse;

    theta+=offset_x;
    fi+=offset_y;

    if(tempo > 0.5)
    {
        if(fi<1.46)
            fi = 1.46;
        if(fi > 4.46)
            fi = 4.46;
    }

    if(checkMouse)
    {
        directionVector.x = cos(theta)*cos(fi);
        directionVector.y = sin(fi);
        directionVector.z = sin(theta)*cos(fi);
    }


    //printf("Valor: %.2f\n",asin(-0.63));

    midPoint.x += moveSpeed.x * ((keys->w - keys->s) * directionVector.x + (keys->d - keys->a) * (-directionVector.z)); 
    midPoint.y += moveSpeed.y * ( keys->w - keys->s) * directionVector.y ; 
    midPoint.z += moveSpeed.z * ((keys->w - keys->s) * directionVector.z + (keys->d - keys->a) * (directionVector.x)); // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed                     

    //printf("Midpoint: (%.2f,%.2f,%.2f)     Look: (%.2f,%.2f,%.2f)\n",midPoint.x,midPoint.y,midPoint.z,look.x,look.y,look.z);]
    //printf("Theta: %.2f    Fi: %.2f\n",theta,fi);
}

void Camera::setupCamera()
{
    gluLookAt(midPoint.x                    , midPoint.y                    , midPoint.z                    ,
              midPoint.x + directionVector.x, midPoint.y + directionVector.y, midPoint.z + directionVector.z,
              0, 1, 0);
}