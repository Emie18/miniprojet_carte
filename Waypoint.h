#ifndef WAYPOINT_H
#define WAYPOINT.h
#include "Carte.h"
#include <iostream>
#include <string>
#include <vector>
class Waypoint{
    private:
        float lon;
		std::string nom;
		float lat;
    public:
        Waypoint(float lo=0, std::string nom1="", float la=0): lon(lo), nom(nom1), lat(la){};
        std::string getNom(){
            return nom;
        }
        float getLon(){
            return lon;
        }
        float getLat(){
            return lat;
        }
        virtual bool isVille(){
            return true;
        }
        std::string getInfo(){
            return "info:";
        }
        void affiche(){
            std::cout << nom << "longitude" << lon << "latitude:" << lat << "\n";
			
        }
};

#endif