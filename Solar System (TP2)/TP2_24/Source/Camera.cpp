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
    
    directionVector.x = 0.05;
    directionVector.y = -0.62;
    directionVector.z = 0.78;

    moveSpeed.x = 0.1;
    moveSpeed.y = 0.1;
    moveSpeed.z = 0.1;

    sensibilidade = 0.007;

    fi = 3.9;
    theta = 3.04;
}

// Lei dos cossenos
double cossinLaw(double a)
{
    double aux = (2-pow(a,2))/2;
    if(aux <=-1)
        return 0;
    if(aux >= 1)
        return 0; 
    return acos(aux);
}

// Função que movimenta câmera de acordo com posição atual e anterior do mouse
void Camera::move()
{   
    // Variações do mouse em x e y multiplicados por uma sensibilidade 
    float delta_x = (mouseCoords_x - previousPosition_x) * sensibilidade;
    float delta_y = (mouseCoords_y - previousPosition_y) * sensibilidade;

    // Sinais de 1 ou -1 para lei dos cossenos funcionar propriamente
    int signal_x = 0, signal_y = 0;

    if(delta_x > 0) signal_x = 1;
    else if(delta_x < 0) signal_x = -1;

    if(delta_y > 0) signal_y = 1;
    else if(delta_y< 0) signal_y = -1;

    // Grava a posição anterior do mouse
    previousPosition_x = mouseCoords_x;
    previousPosition_y = mouseCoords_y;

    // Incrementa os valores de theta e fi de acordo com as variações do mouse
    theta += signal_x * cossinLaw(delta_x);
    fi += signal_y * cossinLaw(delta_y);

    // Garante que mouse não mova para cima ou baixo além do esperado
    if(fi < 1.60) fi = 1.60;
    if(fi > 4.7) fi = 4.7;

    // Configura as posições do vetor direção da câmera de acordo com coordenadas esféricas
    if(checkMouse) // se mouse não tiver mexido, não há necessidade de alterar os valores do vetor
    {
        directionVector.x = cos(theta)*cos(fi);
        directionVector.y = sin(fi);
        directionVector.z = sin(theta)*cos(fi);
    }

    // Altera os valores do ponto central da câmera com acréscimo do vetor diretor em suas respectivas coordenadas x, y, z
    // Para permitir a movimentação para esquerda e direita, foi somado o produto vetorial entre o vetor "UP" e o vetor direção
    // "keys.x - keys.y" determina se a variação de posição em determinado eixo será de valor positivo, negativo (caso uma das teclas esteja ativa)
    // ou nulo, caso nenhuma das teclas esteja ativada
    midPoint.x += moveSpeed.x * ((keys->w - keys->s) * directionVector.x + (keys->d - keys->a) * (-directionVector.z)); 
    midPoint.y += moveSpeed.y * ( keys->w - keys->s) * directionVector.y ; 
    midPoint.z += moveSpeed.z * ((keys->w - keys->s) * directionVector.z + (keys->d - keys->a) * (directionVector.x));                   
}

// Função que configura a posição da camera de acordo com seus atributos de posição e vetor direção
void Camera::setupCamera()
{
    gluLookAt(midPoint.x                    , midPoint.y                    , midPoint.z                    ,
              midPoint.x + directionVector.x, midPoint.y + directionVector.y, midPoint.z + directionVector.z,
              0, 1, 0);
}
