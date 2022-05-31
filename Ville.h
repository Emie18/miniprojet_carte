#ifndef VILLE_H
#define VILLE_H
#include <iostream>
#include <string>
#include "Waypoint.h"

class Ville : public Waypoint{
    private:
        	
		std::string nom;
		std::string code_postal;
		int nb_habitant;
		std::string site;


    public:
        Ville (std::string nom1="",std::string c_post=0,  int nb_habi=0, std::string site1=""): nom(nom1),code_postal(c_post), nb_habitant(nb_habi), site(site1){}
		std::string getSite() const{return site;}
		std::string getNom(){return nom;}
		bool isVille() const{return true;}
		std::string getInfos(){return "info";}
		void affiche() const{
			std::cout << "nom: "<<";\n code postal: " << code_postal << "; \n site: " << site << ";\n nb_habitant: " << nb_habitant << ".\n";
		}
};
#endif