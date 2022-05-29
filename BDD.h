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
//#include "Contour.h"
//#include "Point.h"
//#include "Ville.h"
//#include "Waypoint.h"

class BDD {
	public :
		BDD(std::string host, std::string nomBDD, std::string login, std::string pwd);
		BDD();
		~BDD();
		
		std::vector<Route> getRoute();
		std::vector<Waypoint*> getWaypoint();
		Contour getContour();
		Carte carte(std::vector<Waypoint*>,std::vector<Route>,Contour,std::vector<Ville>);
		std::vector<Ville> getVille();
		
	private :
		Carte cartes;
		sql::Connection *con;
};
#endif