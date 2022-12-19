#ifndef _SCORE_H
#define _SCORE_H

#include "Entity.h"

class Score: public Entity
{
    private:
        double score;
        std::vector<GLuint> digitsScoreTexxtures;

    public:
        Score();

        double getScore(){return this->score;}
        void setScore(double score){this->score = score;}
};

#endif