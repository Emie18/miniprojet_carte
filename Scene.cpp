#include "Scene.h"
#include <iostream>
//int var=100;
#include <cmath>

#define pi 3.14159265358979323846
std::map<std::string, QColor> ScenePlan::tab_couleurs = {{"noir", Qt::black}};

double calculateDistance(double lat1, double long1, double lat2, double long2) {
    double dist;
    dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
    dist = acos(dist);
    dist = (6371 * pi * dist) / 180;
    return dist;
}

ScenePlan::ScenePlan(Carte carte) { // constructeur

    QColor coul = tab_couleurs["noir"];
    qreal epais = 0;
    Contour contour = carte.getContour();
    std::vector<Point> p=contour.getPoints();
    for (int j=0;j<p.size()-2; ++j){    
        QGraphicsLineItem *ligne = new QGraphicsLineItem (0, 0,p[j+1].getLon()-p[j].getLon(),p[j+1].getLat()-p[j].getLat());
        // l'origine de la ligne est le point 1
        ligne->setPos(p[j].getLon(),p[j].getLat());
        ligne->setPen(QPen(coul,epais,Qt::SolidLine));
        this->addItem(ligne);
    }



    //std::vector<std::string><Ville> ville=carte.getNomVilles();
    std::vector<Waypoint*> v = carte.getWaypoints();
    

     for (auto& elem: v){
         if(elem->isVille()==false){
  std::cout<<'\n';
  std::cout<<elem->getNom();
        std::cout<<'\n';
         }
         
   }

}
