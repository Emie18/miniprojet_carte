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
		std::vector<Waypoint*> waypoint;
		std::vector<Route> route;
		Contour contour;
		
	public :
		Carte(std::vector<Waypoint*> w,std::vector<Route> r,Contour c){
			waypoint = w;
			route = r;
			contour = c;
		
		}
		Carte(){}
        Contour getContour(){return contour;}
		float getEchelleLon()const{}
		std::vector<Waypoint*> getWaypoints() const{return waypoint;}
		std::vector<Route> getRoutes() const{return route;}
		std::vector<std::string> getNomVilles() const{
			for(auto& elem: waypoint){
				getNomVilles().push_back(elem->getNom());
			}
			}
		
		//void ajoutUnWaypoint(Waypoint w){}
		//void ajoutUneRoute(Route r){ }
		//void insereUneVille(Ville * v){}
		void affiche() const{
				std::cout << "Carte " << "\n";
				//for ( auto &route : routes ){
				//	route.affiche();
			//}
		}
};
#endif