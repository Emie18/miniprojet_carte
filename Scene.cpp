#include "Scene.h"
#include <iostream>
#include <QGraphicsPolygonItem>
std::map<std::string, QColor> ScenePlan::tab_couleurs = {{"noir", Qt::black},{"rouge", Qt::red}};


ScenePlan::ScenePlan(Carte carte,std::vector<int> chemin) { // constructeur

    QColor coul = tab_couleurs["noir"];
    qreal epais = 0;
    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem;
    QPolygonF c ;
    Contour contour = carte.getContour();
    for(auto &elem:contour.getPoints()){
        c<< QPointF( elem.getLon(),elem.getLat());
    }
    // for (int j=0;j<(int)p.size()-2; ++j){    
    //     QGraphicsLineItem *ligne = new QGraphicsLineItem (0, 0,p[j+1].getLon()-p[j].getLon(),p[j+1].getLat()-p[j].getLat());
    //    // c << QPointF ( p[j+1].getLon()-p[j].getLon() , p[j+1].getLat()-p[j].getLat() );
    //     // l'origine de la ligne est le point 1
    //     ligne->setPos(p[j].getLon(),p[j].getLat());
    //     ligne->setPen(QPen(coul,epais,Qt::SolidLine));
    //     this->addItem(ligne);
    // }
    polygonItem->setPolygon(c);
    polygonItem->setPen(QPen(coul,epais,Qt::SolidLine));
    polygonItem->setBrush( Qt::green );
    this->addItem(polygonItem);



    std::vector<Ville> ville=carte.getVilles();
    std::vector<Waypoint*> wayp = carte.getWaypoints();
    std::vector<Waypoint*> w;

    for (auto& elem: wayp){
          for(auto& elem2: ville){
             if(elem->getNom()==elem2.getNom()){
                 w.push_back(elem);
              }

             }
          }

     
QColor coul2 = tab_couleurs["rouge"];     
std::string  text_tooltip;         
for (auto& elem: w){  
    
    text_tooltip = elem->getNom();
	
    qreal taille_o =0.1;
    QGraphicsRectItem* vi= new QGraphicsRectItem(0,0,-taille_o/4,-taille_o/4);  
         vi->setPos(elem->getLon(),elem->getLat());
         vi->setPen(QPen(coul2,taille_o/4,Qt::SolidLine));
         std::string  text_tooltip = elem->getNom();
		vi->setToolTip(QString::fromStdString(text_tooltip));
         this->addItem(vi);
    }
     float lon1= 0;
                 float lat1 =0;
  
                 float lon2= 0;
                 float lat2 =0;

    
    
    
    std::vector<Route> route=carte.getRoutes();
   
    for (auto& elem: route){  
        std::string deb = elem.getIDeb();
        std::string fin = elem.getIFin();
        for(auto& elem2: wayp){
             if(elem2->getNom()==deb){   
                 lon1= elem2->getLon();
                 lat1 =elem2->getLat();
              }
             }
             for(auto& elem2: wayp){
             if(elem2->getNom()==fin){
                 lon2= elem2->getLon();
                 lat2 =elem2->getLat();
              }

             }
        QGraphicsLineItem *ligne2 = new QGraphicsLineItem (0, 0,lon2-lon1,lat2-lat1);
        // l'origine de la ligne est le point 1
        ligne2->setPos(lon1,lat1);
        ligne2->setPen(QPen(coul,epais,Qt::SolidLine));
        this->addItem(ligne2);
    
     }
    
     if(chemin[0]!=-1){
        qreal epais2 = 0.05;
        std::cout<<"calcule ...\n";
        std::vector<Waypoint*> w_r = carte.getWaypoints();
        std::vector<float> longitude;
        std::vector<float> latitude;
        for(auto p:chemin){
            longitude.push_back(w_r[p]->getLon());
            latitude.push_back(w_r[p]->getLat());
        }
        for(int id=0;id<(int)longitude.size()-1;id++){
            
            QGraphicsLineItem *ligne4 = new QGraphicsLineItem (0, 0,longitude[id+1]-longitude[id],latitude[id+1]-latitude[id]);
         // l'origine de la ligne est le point 1
            ligne4->setPos(longitude[id],latitude[id]);
            ligne4->setPen(QPen(coul2,epais2,Qt::SolidLine));
            this->addItem(ligne4);
           // std::cout<<w_r[id]->getLon();
        }
        }
   

}