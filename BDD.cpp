#include "BDD.h"

BDD::BDD ( std::string host, std::string nomBDD, std::string login, std::string pwd){
		/* Create a connection */
		sql::Driver *driver = get_driver_instance();
		con = driver->connect(host, login, pwd);

		/* Connect to the MySQL database */
		con->setSchema(nomBDD);

		setlocale(LC_ALL,"C");
}
BDD::~BDD(){
	std::cout << "Fermeture connection\n";
	delete con;
}
Contour BDD::getContour(){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
					"select * from contour ");
	res->next();
	std::vector<Point> p;
	while (res->next()){
		p.push_back(Point(res->getInt(1),res->getInt(2),res->getInt(3)));
		
	}
	Contour contour(p);

	delete res;
	delete stmt;
	return contour;
}
std::vector<Route> BDD::getRoute(){

	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
					"select * from route ");
	res->next();
	std::vector<Route> r;
	while (res->next()){
		r.push_back(Route(res->getInt(1),res->getInt(2),res->getInt(3)));
		
	}

	delete res;
	delete stmt;
	return r;
}
std::vector<Waypoint> BDD::getWaypoint(){

	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
					"select * from waypoint ");
	res->next();
	std::vector<Waypoint> w;
	while (res->next()){
		w.push_back(Waypoint(res->getInt(3),res->getString(1),res->getInt(1)));
		
	}

	delete res;
	delete stmt;
	return w;

}

