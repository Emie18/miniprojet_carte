#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contour.h"
#include "Waypoint.h"
#include "Route.h"

class Carte {
	private :
	
	public :
		Carte (){}
         Contour getContour()
		int getNum() const{
			return num;
		}
		float getX() const{
			return x;
		}
		float getY() const{
			return y;
		}
		void setX(float x){
			this->x = x;
		}
		void setY(float y){
			this->y = y;
		}
		std::string getInfos() const {
			std::ostringstream texte;
			texte << "Point " << std::setprecision(2) << std::fixed 
					<< num << "\n(" << x << "," << y << ")";
			return texte.str();
		}
		void affiche() const{
				std::cout << "\tpoint " << num << " (" << x << "," << y << ")\n";
		}

};

#endif