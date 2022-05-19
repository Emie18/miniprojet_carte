#ifndef BDD_H
#define BDD_H

#include <iostream>
#include <string>
#include <vector>
#include <clocale>

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Ville.h"
#include "Carte.h"
#include "Point.h"
#include "Waypoint.h"
#include "Contour.h"

class BDD {
	public :
		BDD ( std::string host, std::string nomBDD, std::string login, std::string pwd);
		BDD (){}
		~BDD();

		
		std::vector<Route> getRoute();
		std::vector<Waypoint> getWaypoint();
		Contour getContour();

	private :
		Carte carte;
		sql::Connection *con;
};
#endif
