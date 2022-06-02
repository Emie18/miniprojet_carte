/*-------------------------
	fichier Contour.h
contient la class Contour
Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
---------------------------*/
#ifndef CONTOUR_H
#define CONTOUR_H

#include <vector>
#include "Point.h"

class Contour
{
private:
    std::vector<Point> point;

public:
    Contour(std::vector<Point> p) { point = p; }
    Contour() {}
    ~Contour() {}
    //getteur point (vecteur de Point)
    std::vector<Point> getPoints() const { return point; }
    //fonction ajoutant un point à l'attribu point
    void ajoutUnPoint(Point p)
    {
        point.push_back(p);
    }
};
#endif