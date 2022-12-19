#ifndef _ENTITYCLASS_H
#define _ENTITYCLASS_H

#include <GL/freeglut.h>
#include <vector>
#include <stdbool.h>

using namespace std;

typedef struct VERTICE
{
    double x,y;
}vertice;

class Entity{
    private:
        double x_max, x_min; // Valores maximos e minimos que x e y podem alcançar 
        double y_max, y_min; // baseados nas coordenadas extremas do desenho.
        double x_move, y_move; // Unidade de movimento nos eixos x e y ("velocidade" da entidade).
        int ladoHorizontal, ladoVertical; // LH = 1: anda na horizontal. 
                                        // LV = 1: anda na vertical.
        vertice centro;  // Coordenadas do ponto central.
        vertice hitbox[4]; // Modelo de hitbox do objeto
                         // Vetor de tamanho 4
        vertice alteredHitbox[4]; // Modelo de hitbox alterado por rotação e translação do objeto
                                // Vetor de tamanho 4
        vertice resize; // Escalas de redimensionamento das coordenadas.
        double angularSpeed; // Velocidade angular do objeto
        double vetorialSpeed; // Velocidade vetorial do objeto
        double angulo;
        GLboolean onScreen; // Objeto se econtra dentro da caixa de visualização ou não.
        GLuint model; // ID da displayList de desenho.
        double bulletSpeed;
        GLboolean drawHitbox;

    public:
        
        int continuar;

        double getX_Max();
        void setX_Max(double x_max);

        double getX_Min();
        void setX_Min(double x_min);

        double getY_Max();
        void setY_Max(double y_max);

        double getY_Min();
        void setY_Min(double y_min);

        double getX_Move();
        void setX_Move(double x_move);

        double getY_Move();
        void setY_Move(double y_move);

        int getLadoHorizontal();
        void setLadoHorizontal(int ladoHorizontal);

        int getLadoVertical();
        void setLadoVertical(int ladoVertical);

        double getCentroX();
        void setCentroX(double centroX);

        double getCentroY();
        void setCentroY(double centroY);

        vertice* getHitbox();
        void setHitbox(vertice* hitbox);

        vertice* getAlteredHitbox();
        void setAlteredHitbox(vertice* aleredHitbox);

        double getResizeX();
        void setResizeX(double resize);

        double getResizeY();
        void setResizeY(double resize);

        double getAngularSpeed();
        void setAngularSpeed(double angularSpeed);

        double getVetorialSpeed();
        void setVetorialSpeed(double vetorialSpeed);

        double getAngulo();
        void setAngulo(double angulo);

        GLboolean getOnScreen();
        void setOnScreen(GLboolean getOnScreen);

        GLuint getModel();
        void setModel(GLuint model);

        double getBulletSpeed();
        void setBulletSpeed(double bulletSpeed);

        int getContinuar();
        void setContinuar(int continuar);

        GLboolean getDrawHitbox();
        void setDrawHitbox(GLboolean drawHitbox);      
};

#endif