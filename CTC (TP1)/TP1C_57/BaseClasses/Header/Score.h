#ifndef _SCORE_H
#define _SCORE_H

#include "Entity.h"
#include "../../GeneralFiles/Header/drawings.h"

class Score: public Entity
{
    private:
        int score;
        GLuint digitsScoreTextures [10];

    public:
        Score();

        double getScore(){return this->score;}
        void setScore(const double& score){score <= 999999999 ? this->score = score : this->score = 999999999;}

        void draw();
        void auxDraw(const int& dig);

};

#endif