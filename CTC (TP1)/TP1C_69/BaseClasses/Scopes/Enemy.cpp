#include "../Header/Enemy.h"
#include <stdio.h>
#include "../../GeneralFiles/Header/globalParameters.h"
#include <time.h>

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

Enemy::Enemy(int type) : MovableEntity()
{
    srand(time(0));
    this->type = type;
    this->onScreen = GL_TRUE;

    switch (this->type)
    {
    case 0: // kamikaze
        this->dropPercentage = 20;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeMove = 0;
        this->typeTiroManager = 0; // determina tipo do tiro
        this->numberOfShots = 0;
        this->hp = 1;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->alteredFireRate = 0;
        this->setDisplayListModel(textures[11]);
        this->setMax(20, 20);
        this->setMin(-20, -20);
        this->setVelocity(1, 1);
        this->setResize(0.5);
        break;

    case 1: // sniper
        this->dropPercentage = 30;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1;
        this->typeMove = 0;
        this->numberOfShots = 0;
        this->hp = 12;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->alteredFireRate = 1;
        this->setDisplayListModel(textures[13]);
        this->setMax(20, 20);
        this->setMin(-20, -20);
        this->setVelocity(0, 0);
        this->setResize(0.5);
        break;

    case 2: // nave que atira missel que segue
        this->dropPercentage = 17;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(5);
        this->typeMove = 4;
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 1;
        this->onscreenTestable = GL_FALSE;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->alteredFireRate = 1;
        this->setDisplayListModel(textures[27]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;

    case 3: // nave raio laser vermelho pequena 1/2
        this->dropPercentage = 13;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 1;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->alteredFireRate = 1;
        this->setDisplayListModel(textures[28]);
        this->setMax(20, 20);
        this->setMin(-20, -20);
        this->setVelocity(0.5, 1);
        this->setResize(0.36);
        break;

    case 4: // tank
        this->dropPercentage = 30;
        this->killValue = 10;
        this->angle = 180;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(4);
        this->typeTiroManager = 1;
        this->numberOfShots = 0;
        this->hp = 22;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->alteredFireRate = 1;
        this->setDisplayListModel(textures[29]);
        this->setMax(20, 20);
        this->setMin(-20, -20);
        this->setVelocity(0.5, 1);
        this->setResize(0.9);
        break;

    case 5: // torreta que estará sobre o png de asteroide
        this->dropPercentage = 20;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 1; /**/
        this->numberOfShots = 0;   // inutilizzadp
        this->hp = 13;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4; /**/
        this->continueMove = 0;
        this->fireRatePeriod = 0; // tem que ser 0
        this->alteredFireRate = 0.17;
        this->setDisplayListModel(textures[33]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(1, 1); // deixar padrao no cosntrutor e talvez mmudar na wave
        this->setResize(0.5);
        break;

    case 6: // asteroide
        this->dropPercentage = 10;
        this->killValue = 10;
        this->angle = 0;
        this->angularSpeed = 0;
        this->currentProjectile = Projectile(3);
        this->typeTiroManager = 3;
        this->numberOfShots = 0;
        this->hp = 10;
        this->onscreenTestable = GL_FALSE;
        this->typeMove = 4;
        this->continueMove = 0;
        this->fireRatePeriod = 0;
        this->setDisplayListModel(textures[32]);
        this->setMax(15, 15);
        this->setMin(-15, -15);
        this->setVelocity(0.5, 1);
        this->setResize(0.5);
        break;
    }
    this->setHitbox();
    this->setMidPoint();
}

Projectile Enemy::createProject(Projectile *auxP, double angle)
{
    auxP->setMidPoint(this->max.getX() * cos(grausParaRadianos(this->angle) + angle) + this->midPoint.getX(),
                      this->max.getY() * sin(grausParaRadianos(this->angle) + angle) + this->midPoint.getY());
    return *auxP;
}

void Enemy::parabolicMoveTemplate(double a, double b, double c)
{
    this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
    this->midPoint.setX(a * pow(this->midPoint.getY(), 2) + b * this->midPoint.getY() + c);
}

void Enemy::senoidMoveTemplate(double a, double b, double c, double d)
{
    this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
    this->midPoint.setX(a + b * sin(c * this->midPoint.getY() + d));
}

void Enemy::kamikazeMove()
{
    if (continueMove < 150)
    {
        aim(90);

        this->midPoint.setX(this->midPoint.getX() + cos(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getX());
        this->midPoint.setY(this->midPoint.getY() + sin(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getY());

        this->continueMove++;
    }
    else
    {
        this->midPoint.setX(this->midPoint.getX() + cos(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getX() * 2);
        this->midPoint.setY(this->midPoint.getY() + sin(grausParaRadianos(this->angle) + M_PI / 2) * this->velocity.getY() * 2);
    }

    // printf("%d\n", this->continueMove);
}

void Enemy::aim(double auxAngle) // mira  a frente do inimigo na direção do player
{
    double angle = atan2(this->followPoint.getY() - this->midPoint.getY(),
                         this->followPoint.getX() - this->midPoint.getX());

    this->angle = radianoParaGraus(angle) - auxAngle;
}

void Enemy::move()
{
    switch (this->typeMove)
    {
    case 0:
        break;

    case 1: // anda para baixo
        this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
        break;

    case 2: // elipse com entrada

        if(this->midPoint.getX() > 80)
            this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());

        if((-80 <= this->midPoint.getX()) && (this->midPoint.getX() <= 80))
        {
            if(this->midPoint.getY() > 0)
                this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());
              
            if(this->midPoint.getY() < 0)
                this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());

            if(this->midPoint.getY() == 0)
            {
                if(this->midPoint.getX() < 0)
                {
                    this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
                    this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());
                }
                if(this->midPoint.getX() > 0)
                {
                    this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());
                    this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());
                    }
            } 

            if(this->midPoint.getY() > 0)
                this->midPoint.setY(sqrt(100 - pow(this->midPoint.getX(), 2)/64));
            if(this->midPoint.getY() < 0)
                this->midPoint.setY(-(sqrt(100 - pow(this->midPoint.getX(), 2)/64)));
  
        }


        
        printf("Ang: %.2f\n",angle);
        //printf("Midpoint: (%.2f,%.2f)\n",this->midPoint.getX(),this->midPoint.getY());

        break;

    case 3: // Kamikaze
        kamikazeMove();
        break;

    case 4: // parabola  y = x²
        aim(90);
        parabolicMoveTemplate(-9.0 / 160, 9.0 / 2, -90);
        break;

    case 5: // parabola  y = x²
        aim(90);
        parabolicMoveTemplate(9.0 / 160, -9, 360);
        break;

    case 6: // parabola  y = x²
        aim(90);
        parabolicMoveTemplate(9.0 / 160, 0, 0);
        break;

    case 7: // senoide cima-baixo na direita
        aim(90);
        senoidMoveTemplate(45, 20, 0.1, -15);
        break;

    case 8: // senoite cima-baixo na esquerda
        aim(90);
        senoidMoveTemplate(-45, -20, 0.1, -15);
        break;

    case 9: // funcao de terceiro com 2 de segundo
        aim(90);
        if (this->midPoint.getY() >= 60)
            parabolicMoveTemplate(9.0 / 160, -27.0 / 4, 405.0 / 2);
        else
            parabolicMoveTemplate(-9.0 / 160, 27.0 / 4, -405.0 / 2);
        break;

    case 10: // anda para baixo e mira para a posição do player
        aim(0);
        this->midPoint.setY(this->midPoint.getY() - this->velocity.getY());
        break;

    case 11: // segue na posicao x o player e o y fica variando

        if(this->midPoint.getX() > this->followPoint.getX())
            this->midPoint.setX(this->midPoint.getX() - this->velocity.getX());
        else if(this->midPoint.getX() < this->followPoint.getX())
            this->midPoint.setX(this->midPoint.getX() + this->velocity.getX());
        

        if(this->midPoint.getY() + this->max.getY() > 70)
            this->velocity.setY(-abs(this->velocity.getY()));
        

        else if(this->midPoint.getY() + this->min.getY() < -30)
            this->velocity.setY(abs(this->velocity.getY()));
        

        this->midPoint.setY(this->midPoint.getY() + this->velocity.getY());

        
        break;
    }

    verifyVisibility(*this);

    if (this->onScreen)
        this->onscreenTestable = 1;

    generalHitBoxMovement();
}

void Enemy::scaleMove(const double &scale) {}

std::vector<Projectile> Enemy::fire()
{
    Projectile projectile1 = this->currentProjectile;

    projectile1.setAngle(angle);

    projectile1.setOwner(2);

    std::vector<Projectile> vec;

    switch (this->typeTiroManager)
    {
    case 0: // tiro que sai na direcao do player
        switch (numberOfShots)
        {
        case 1:
            projectile1.setAngle(angle - 90);
            vec.push_back(createProject(&projectile1, 0));
            break;

        case 2:
            vec.push_back(createProject(&projectile1, 0));
            vec.push_back(createProject(&projectile1, M_PI));
            break;
        }
        break;
    case 1: // tiro simples que espalha (tank)
        switch (numberOfShots)
        {
        case 3:

            projectile1.setAngle(angle - 32);
            vec.push_back(createProject(&projectile1, 0));

            projectile1.setAngle(angle);
            vec.push_back(createProject(&projectile1, M_PI / 2));

            projectile1.setAngle(angle + 32);
            vec.push_back(createProject(&projectile1, M_PI));
            break;

        case 5:
            projectile1.setAngle(angle - 50);
            vec.push_back(createProject(&projectile1, 0));

            projectile1.setAngle(angle - 25);
            vec.push_back(createProject(&projectile1, M_PI / 4));

            projectile1.setAngle(angle);
            vec.push_back(createProject(&projectile1, M_PI / 2));

            projectile1.setAngle(angle + 25);
            vec.push_back(createProject(&projectile1, 3 * M_PI / 4));

            projectile1.setAngle(angle + 50);
            vec.push_back(createProject(&projectile1, M_PI));
            break;
        }
        break;

    case 2: // tiro que segue
        switch (numberOfShots)
        {
        case 1:
            vec.push_back(createProject(&projectile1, 0));
            break;
        }
        break;
    }
    // printf("Valor: %d\n",r);

    double r = 1 + rand() % 20;
    printf("R: %f\n", r);
    this->fireRatePeriod = (this->currentProjectile.getDefaultFireRate() * this->alteredFireRate) * (1 + 2*r/20);

    return vec;
}