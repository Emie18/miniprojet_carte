#ifndef VILLE_H
#define VILLE_H
#include <iostream>
#include <string>
#include "Waypoint.h"
class Ville : public Waypoint{
    private:
        int nb_habitant;
		std::string code_postal;
		std::string site;
    public:
        Ville (std::string c_post=0, std::string nom="", int nb_habi=0): code_postal(c_post), site(nom), nb_habitant(nb_habi){
		}
		std::string getSite() const {
			return site;
		}
		virtual bool isVille() const{
                return true;			
		}
	
		void affiche() const{
			std::cout << "code postal :" << code_postal << "site:" << site << "nb_habitant:" << nb_habitant << "\n";
		}
};

#endif