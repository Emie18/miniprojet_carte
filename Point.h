/*---------------------
	fichier Point.h
contient la class Point
et ses fonctions membres
Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
-----------------------*/
#ifndef POINT_H
#define POINT_H

#include "Contour.h"
class Point
{
private:
    int num;
    float lon;
    float lat;

public:
    Point(int n, float la, float lo)
    {
        num = n;
        lon = lo;
        lat = la;
    }
    ~Point() {}
    float getLon() const { return lon; }
    float getLat() const { return lat; }
};
#endif