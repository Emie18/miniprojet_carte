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
        Ville (std::string n, float lo, float la, std::string c_post=0, std::string nom="", int nb_habi=0): code_postal(c_post), site(nom), nb_habitant(nb_habi){
			lon = lo;
			lat = la;
			nom = n;
		}
		std::string getSite() const {
			return site;
		}
		int getNb_habitant(){return nb_habitant;}
		bool isVille() const{
		// 		std::string str =this->getNom();
		// 	if(str.find("Pont ") != std::string::npos){
        //         return 0;			
		// }else{
		// 	return 1;
		// }
		return true;
		}
		std::string getInfos(){}
		void affiche() const{
			std::cout << "code postal :" << code_postal << "site:" << site << "nb_habitant:" << nb_habitant << "\n";
		}
};
#endif