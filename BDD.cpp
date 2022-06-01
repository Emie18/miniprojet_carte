/*---------------------
	fichier BDD.cpp
contient les fonction 
de la class BDD.h
-----------------------*/
#include "BDD.h"
#include <cmath>
BDD::BDD(std::string host, std::string nomBDD, std::string login, std::string pwd)
{
	/* Create a connection */
	sql::Driver *driver = get_driver_instance();
	con = driver->connect(host, login, pwd);
	/* Connect to the MySQL database */
	con->setSchema(nomBDD);
	setlocale(LC_ALL, "C");
}

BDD::~BDD()
{
	std::cout << "Fermeture connexion\n";
	delete con;
}
//getRoute()récupère les routes de la base de donnée
//et retourne le vecteur des routes
std::vector<Route> BDD::getRoute()
{
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery("select * from route ");
	std::vector<Route> r;
	while (res->next())
	{
		r.push_back(Route(res->getString(1), res->getString(2), res->getInt(3)));
	}
	delete res;
	delete stmt;
	return r;
}
//getWaypoint()récupère les waypoint(ville,pont,...) de la base de donnée
//et retourne le vecteur pointeur des waypoints
std::vector<Waypoint *> BDD::getWaypoint()
{
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery("select * from waypoint ");
	std::vector<Waypoint *> w;
	while (res->next())
	{
		Waypoint *wayp = new Waypoint(res->getString(1), res->getDouble(2), res->getDouble(3) * -cos(48));
		w.push_back(wayp);
	}
	delete res;
	delete stmt;
	return w;
}
//getVille()récupère les villes de la base de donnée
//et retourne le vecteur des villes
std::vector<Ville> BDD::getVille()
{
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery("select * from ville");
	std::vector<Ville> v;
	while (res->next())
	{
		v.push_back(Ville(res->getString(1), res->getString(2), res->getInt(3), res->getString(4)));
	}
	delete res;
	delete stmt;
	return v;
}
//getRoute()récupère les Points de la base de donnée
//puis créer un contour avec ces points que
//la fonction va retourner le Contour créé
Contour BDD::getContour()
{
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery("select * from contour");
	std::vector<Point> p;
	while (res->next())
	{
		p.push_back(Point(res->getInt(1), res->getDouble(2), res->getDouble(3) * -cos(48)));
	}
	Contour contour(p);
	delete res;
	delete stmt;
	return contour;
}