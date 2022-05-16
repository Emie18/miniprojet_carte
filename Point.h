#ifndef POINT_H
#define POINT_H
#include "Contour.h"
class Point{
    private:
        int num;
        float lon;
        float lat;
    public:
        Point(){}
        ~Point(){}
       float getLon()const{return lon;}
       float getLat()const{return lat;}

};
#endif