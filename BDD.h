/*---------------------
	fichier BDD.h
contient la class BDD
-----------------------*/
#ifndef BDD_H
#define BDD_H
#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Carte.h"
class BDD
{
public:
	BDD(std::string host, std::string nomBDD, std::string login, std::string pwd);
	BDD();
	~BDD();
	//fonction recupérant les Routes de la bdd
	std::vector<Route> getRoute();
	//fonction recupérant les waypoint de la bdd
	std::vector<Waypoint *> getWaypoint();
	//fonction le contour via les points de la bdd
	Contour getContour();
	//fonction les villes de la bdd
	std::vector<Ville> getVille();

private:
	Carte cartes;
	sql::Connection *con;
};
#endif