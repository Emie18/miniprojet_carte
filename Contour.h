#ifndef CONTOUR_H
#define CONTOUR_H
#include "Point.h"
#include <vector>
class Contour{
    private:
    std::vector<Point> point;

    public:
    Contour(std::vector<Point> p ){
        point=p;
    }
    Contour(){}
    ~Contour(){}
    std::vector<Point> getPoints()const{
        return point;
    }
    void ajoutUnPoint(Point p){
        point.push_back(p);
    }



};
#endif