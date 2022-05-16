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

class Carte {
	private :
	
	public :
		Carte (){}
        Contour getContour(){}
		float getEchelleLon()const{}
		std::vector<Waypoint> getWaypoints() const{	}
		std::vector<Route>getRoutes() const{}
		std::vector<std::string> getNomVilles() const{}
		void ajoutUnWaypoint(Waypoint w){}
		void ajoutUneRoute(Route r){}
		void insereUneVille(Ville * v){}
		void affiche() const{
				std::cout << "Carte " << "\n";
		}
};
#endif