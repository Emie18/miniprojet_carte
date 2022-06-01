/*---------------------
	fichier Carte.h
contient la class Carte
et ses fonctions membre
-----------------------*/
#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include "Contour.h"
#include "Waypoint.h"
#include "Route.h"
#include "Ville.h"
class Carte
{
private:
	std::vector<Waypoint *> waypoint;
	std::vector<Route> route;
	Contour contour;
	std::vector<Ville> ville;
	std::vector<std::string> nomvilles;

public:
	Carte(std::vector<Waypoint *> w, std::vector<Route> r, Contour c, std::vector<Ville> v)
	{
		waypoint = w;
		route = r;
		contour = c;
		ville = v;
	}
	Carte() {}
	Contour getContour() { return contour; }
	//float getEchelleLon()const{return 0;}
	std::vector<Waypoint *> getWaypoints() const { return waypoint; }
	std::vector<Route> getRoutes() const { return route; }
	std::vector<Ville> getVilles() const { return ville; }
	std::vector<std::string> getNomVilles()
	{
		for (auto &elem : ville)
		{
			nomvilles.push_back(elem.getNom());
		}
		return nomvilles;
	}
	//void ajoutUnWaypoint(Waypoint w){}
	//void ajoutUneRoute(Route r){ }
	//void insereUneVille(Ville * v){}
	//void affiche() const{}
};
#endif