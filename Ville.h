/*------------------------
	fichier Ville.h
contient la class Villes
et ses fonctions membres
Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
--------------------------*/
#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include <string>
#include "Waypoint.h"

class Ville : public Waypoint
{
private:
	std::string nom;
	std::string code_postal;
	int nb_habitant;
	std::string site;

public:
	//constructeur
	Ville(std::string nom1 = "", std::string c_post = 0, int nb_habi = 0, std::string site1 = "")
			: nom(nom1), code_postal(c_post), nb_habitant(nb_habi), site(site1) {}

	//getteurs
	std::string getSite() const { return site; }
	std::string getNom() { return nom; }

	//fonction revoit toujours vrai
	bool isVille() const { return true; }

	//affiche les info d'une ville
	void affiche() const
	{
		std::cout << "nom: "<< nom <<"\n code postal: " << code_postal
					<< "; \n site: " << site << ";\n nb_habitant: " << nb_habitant << ".\n";
	}
};
#endif