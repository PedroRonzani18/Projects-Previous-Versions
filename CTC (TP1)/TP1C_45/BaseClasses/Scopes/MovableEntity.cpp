#include "../Header/MovableEntity.h"

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

MovableEntity::MovableEntity() : Entity()
{}


void MovableEntity::generalHitBoxMovement()
{
    for(int i=0; i<4; i++)
    {
        double auxAngle = grausParaRadianos(this->getAngle());
        
        // Usadas no calculo dos valores de x' e y' ao rotacionar a entidade
        double x = this->getHitbox()[i].getX();
        double y = this->getHitbox()[i].getY();

        // Altera o valor das coordenadas x e y da hitbox de acordo com as rotações

        x = x * cos(auxAngle) - y * sin(auxAngle);
        y = x * sin(auxAngle) + y * cos(auxAngle);
        this->setAlteredHitbox(i, x, y);

        // Altera o valor das coordenadas x e y da hitbox de acordo com as translações
        this->setAlteredHitbox(i, x + this->getMidPoint().getX(), y + this->getMidPoint().getY());
    }  
}  
