#ifndef VILLE_H
#define VILLE_H

#include "Waypoint.h"
class Ville::Waypoint{
    private:
        int nb_habitant;
		std::string code_postal;
		std::string site;
    public:
        Ville (int c_post=0, std::string nom="", int nb_habi=0): code_postal(c_post), site(nom), nb_habitant(nb_habi){
		}
		std::string getSite() const {
			return site;
		}
		virtual bool isVille() const{
                return true;			
		}
	
		void affiche() const{
			std::cout << "Plan " << id_plan << " (" << nom_projet << ") version:" << version << " orientation:" << orientation <<" date: " << date_plan << "\n";
			for ( auto &mur : murs ){
					mur.affiche();
			}
		}
};

#endif