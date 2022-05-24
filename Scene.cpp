#include "Scene.h"
#include <iostream>
//int var=100;
std::map<std::string, QColor> ScenePlan::tab_couleurs = {{"noir", Qt::black}};

ScenePlan::ScenePlan(Carte carte) { // constructeur

    QColor coul = tab_couleurs["noir"];
    qreal epais = 0.5;
    Contour contour = carte.getContour();
    for (auto& elem: contour.getPoints()){

           std::cout<<elem.getLon();
    }
}
//     std::vector<Point> p=contour.getPoints();
//  QGraphicsLineItem *ligne = new QGraphicsLineItem (0, 0, 50,50);
//            // // l'origine de la ligne est le point 1
//             ligne->setPos(0,0);
//              ligne->setPen(QPen(coul,epais,Qt::SolidLine));
//             // //std::string text_tooltip = [j].getInfos();
//             // //ligne->setToolTip(QString::fromStdString(text_tooltip));
//              this->addItem(ligne);
//     for(auto& elem : p){
// std::cout<<elem.getLon();
        //  qreal taille_o = epais;
        // QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
        // origine->setPos(p[i+1].getLat(),p[i+1].getLon()); // le milieu du cercle est positionné au (0,0) de la scène
        // origine->setPen(QPen(Qt::black,0.25,Qt::SolidLine));// épaisseur du trait 0 = 1 pixel
        // this->addItem(origine);
            // // item ligne
             // QGraphicsLineItem *ligne = new QGraphicsLineItem (0, 0, p[i+1].getLat()-p[i].getLat(), p[i+1].getLon()-p[i].getLon());
           // // l'origine de la ligne est le point 1
            // ligne->setPos(p[i].getLat(), p[i].getLon());
            // ligne->setPen(QPen(coul,epais,Qt::SolidLine));
            // //std::string text_tooltip = [j].getInfos();
            // //ligne->setToolTip(QString::fromStdString(text_tooltip));
            // this->addItem(ligne);
    //}    

    // float lon[var];
    //     float lat[var];
    // // Ajout des items graphiques dans la scène
    // std::vector<Waypoint> waypoints = carte.getWaypoints();
    
    // for(int j=0;j<waypoints.size();j++){
       
        
    
    //     for(int i=0;i<var-1;i++){
    //          lon[i]=waypoints[j].getLon();
    //          lat[i]=waypoints[j].getLat();
    //         // item ligne
    //         QGraphicsLineItem *ligne = new QGraphicsLineItem (0, 0, lon[i+1]-lon[i], lat[i+1]-lat[i]);
    // //         // l'origine de la ligne est le point 1
    // //         ligne->setPos(lon[i], lat[i]);
    //         ligne->setPen(QPen(coul,epais,Qt::SolidLine));
    //         std::string text_tooltip = waypoints[j].getInfo();
    //         ligne->setToolTip(QString::fromStdString(text_tooltip));
    //         this->addItem(ligne);

            // if(i==0){
            //     // Matérialisation du point origine de la scène (taille=épaisseur mur)
            //     qreal taille_o = epais;
            //     QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
            //     origine->setPos(points[i].getX(),points[i].getY()); // le milieu du cercle est positionné au (0,0) de la scène
            //     origine->setPen(QPen(Qt::black,0.25,Qt::SolidLine));// épaisseur du trait 0 = 1 pixel
            //     this->addItem(origine);
            //     QGraphicsEllipseItem *origine2 = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
            //     origine2->setPos(points[i+1].getX(),points[i+1].getY()); // le milieu du cercle est positionné au (0,0) de la scène
            //     origine2->setPen(QPen(Qt::black,0.25,Qt::SolidLine));// épaisseur du trait 0 = 1 pixel
            //     this->addItem(origine2);
            // }else{
            //     qreal taille_o = epais;
            //     QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
            //     origine->setPos(points[i+1].getX(),points[i+1].getY()); // le milieu du cercle est positionné au (0,0) de la scène
            //     origine->setPen(QPen(Qt::black,0.25,Qt::SolidLine));// épaisseur du trait 0 = 1 pixel
            //     this->addItem(origine);
            // }
        //}   
          
    //} 
     

     
        
//}

