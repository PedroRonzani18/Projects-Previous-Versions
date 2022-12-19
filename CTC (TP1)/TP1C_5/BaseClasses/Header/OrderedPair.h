#ifndef _ORDEREDPAIR_H
#define _ORDEREDPAIR_H

class OrderedPair{
    private:
        double x;
        double y;

    public:
        OrderedPair();
    
        OrderedPair(const double& x, const double& y);

        double getX();
        void setX(const double& x);

        double getY();
        void setY(const double& y);
};

#endif