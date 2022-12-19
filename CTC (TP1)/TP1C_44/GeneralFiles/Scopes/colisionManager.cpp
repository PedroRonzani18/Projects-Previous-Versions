#include "../Header/colisionManager.h"
#include "../Header/globalParameters.h"

int colided(Entity& e1, Entity& e2)
{
    /*
    OrderedPair iniDiag, fimDiag, iniLado, fimLado, deltaVet;
    double l=0, d1=0, d2=0;
    int overlap = 0;

    iniDiag.setX(e1.getMidPoint().getX());
    iniDiag.setY(e1.getMidPoint().getY());
    
    for(int i=0; i<4; i++)
    {
        deltaVet.setX(0);
        deltaVet.setY(0);

        fimDiag.setX(e1.getHitbox()[i].getX());
        fimDiag.setY(e1.getHitbox()[i].getY());

        for(int j=0, s=1; j<4; j++, s=(j+1)%4) 
        {
            iniLado = e2.getHitbox()[j];
            iniLado = e2.getHitbox()[s];

            l = (fimLado.getX() - iniLado.getX()) * (iniDiag.getY() - fimDiag.getY()) - (iniDiag.getX() - fimDiag.getX()) * (fimLado.getY() - iniLado.getY());

            d1 = ((iniLado.getY() - fimLado.getY()) * (iniDiag.getX() - iniLado.getX()) + (fimLado.getX() - iniLado.getX()) * (iniDiag.getY() - iniLado.getY())) / l;

            d2 = ((iniDiag.getY() - fimDiag.getY()) * (iniDiag.getX() - iniLado.getX()) + (fimDiag.getX() - iniDiag.getX()) * (iniDiag.getY() - iniLado.getY())) / l;

            if((0.0 <= d1 && d1 < 1.0) && (0.0 <= d2 && d2 < 1.0))
            {
                deltaVet.setX(deltaVet.getX() + (1.0 - d1) * (fimDiag.getX() - iniDiag.getX()));
                deltaVet.setY(deltaVet.getY() + (1.0 - d1) * (fimDiag.getY() - iniDiag.getY()));

                overlap = 1;
            }

            //e1.setMidPoint(e1.getMidPoint().getX() + (deltaVet.getX() * -1),  //e1.centro.x += deltaVet.x * -1;
            //                e1.getMidPoint().getY() + (deltaVet.getY() * -1)); //e1.centro.y += deltaVet.y * -1;            
            
        }
    }
    return overlap;
    */

         if(e1.getMidPoint().getY() + e1.getMax().getY() < e2.getMidPoint().getY() + e2.getMin().getY()) return 0;
    else if(e1.getMidPoint().getY() + e1.getMin().getY() > e2.getMidPoint().getY() + e2.getMax().getY()) return 0;
    else if(e1.getMidPoint().getX() + e1.getMax().getX() < e2.getMidPoint().getX() + e2.getMin().getX()) return 0;
    else if(e1.getMidPoint().getX() + e1.getMin().getX() > e2.getMidPoint().getX() + e2.getMax().getX()) return 0;
    
    return 1;
}

int mantainInsideScreen(Entity& e)
{
    // Se um dos extremos de cima, baixo, esqueda, direita ultrapassar seu respectivo limite da
    // caixa de visualização, sua coordenada X e/ou Y é programada para voltar para o limite,
    // fazendo que ele nunca saia da caixa de visualização.
    int aux = 0; 

    if(e.getMidPoint().getY() + e.getMax().getY() > top){
        e.getMidPoint().setY(top - e.getMax().getY());
        aux = 1;
    }

    if(e.getMidPoint().getY() + e.getMin().getY() < bottom){
        e.getMidPoint().setY(bottom - e.getMin().getY());
        aux = 1;
    }


    if(e.getMidPoint().getX() + e.getMax().getX() > right){
        e.getMidPoint().setX(right - e.getMax().getX());
        aux = 2;
    }

    if(e.getMidPoint().getX() + e.getMin().getX() < left){
        e.getMidPoint().setX(left - e.getMin().getX());
        aux = 2;
    }

    return aux;
}


void verifyVisibility(Entity& e)
{
    if(e.getMidPoint().getX() + e.getMin().getX() > right ||
       e.getMidPoint().getX() + e.getMax().getX() < left  ||
       e.getMidPoint().getY() + e.getMin().getY() > top   ||
       e.getMidPoint().getY() + e.getMax().getY() < bottom)
       e.setOnScreen(GL_FALSE);
    else
        e.setOnScreen(GL_TRUE);
}
