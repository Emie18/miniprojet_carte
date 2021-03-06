/*-----------------------
	fichier Route.h
contient la class Route
et ses fonctions membres
Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
-------------------------*/
#ifndef ROUTE_H
#define ROUTE_H

#include "Carte.h"
class Route
{
private:
    std::string i_deb;
    std::string i_fin;
    int distance;

public:
    Route(std::string de, std::string f, int di)
    {
        i_deb = de;
        i_fin = f;
        distance = di;
    }
    ~Route() {}
    std::string getIDeb() const { return i_deb; }
    std::string getIFin() const { return i_fin; }
    int getDistance() const { return distance; }
    std::string getInfos() const
    {
        std::string c = std::to_string(distance);
        return "debut:" + i_deb + " fin:" + i_fin + " distance:" + c;
    }
    void affiche() const
    {
        std::cout << this->getInfos() << "\n";
    }
};
#endif