#include "../Header/colisionManager.h"
#include "../Header/globalParameters.h"

int colided(Entity* e1, Entity* e2)
{
    OrderedPair iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;

    iniDiag.setX(e1->getMidPoint().getX());
    iniDiag.setY(e1->getMidPoint().getY());
    
    for(int i=0; i<4; i++)
    {
        deltaVet.setX(0);
        deltaVet.setY(0);

        fimDiag.setX(e1->getHitbox()[i].getX());
        fimDiag.setY(e1->getHitbox()[i].getY());

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2->getHitbox()[j];
            iniLado = e2->getHitbox()[s];

            l = (fimLado.getX() - iniLado.getX()) * (iniDiag.getY() - fimDiag.getY()) - (iniDiag.getX() - fimDiag.getX()) * (fimLado.getY() - iniLado.getY());

            d1 = ((iniLado.getY() - fimLado.getY()) * (iniDiag.getX() - iniLado.getX()) + (fimLado.getX() - iniLado.getX()) * (iniDiag.getY() - iniLado.getY())) / l;

            d2 = ((iniDiag.getY() - fimDiag.getY()) * (iniDiag.getX() - iniLado.getX()) + (fimDiag.getX() - iniDiag.getX()) * (iniDiag.getY() - iniLado.getY())) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.setX(deltaVet.getX() + (1.0 - d1) * (fimDiag.getX() - iniDiag.getX()));
                deltaVet.setY(deltaVet.getY() + (1.0 - d1) * (fimDiag.getY() - iniDiag.getY()));

                overlap = 1;
            }

            e1->setMidPoint(e1->getMidPoint().getX() + (deltaVet.getX() * -1),  //e1->centro.x += deltaVet.x * -1;
                            e1->getMidPoint().getY() + (deltaVet.getY() * -1)); //e1->centro.y += deltaVet.y * -1;            
            
        }
    }
    return overlap;
}

int insideScreen(Entity* e)
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.

    if(e->getMidPoint().getY() + e->getMax().getY() > 100){
        e->setMidPoint(e->getMidPoint().getX(),
                      100 - e->getMax().getY());
        return 0;
    }

    if(e->getMidPoint().getY() + e->getMin().getY() < -100){
        e->setMidPoint(e->getMidPoint().getX(),
                     -100 - e->getMin().getY());
        return 0;
    }

    if(e->getMidPoint().getX() + e->getMax().getX() > 100 * aspectRatio){
        e->setMidPoint(100 * aspectRatio - e->getMax().getX(),
                                      e->getMidPoint().getY());
        return 0;
    }


    if(e->getMidPoint().getX() + e->getMin().getX() < -100 * aspectRatio){
        e->setMidPoint(-100 * aspectRatio - e->getMin().getX(),
                                       e->getMidPoint().getY());
        return 0;
    }

    return 1;
}