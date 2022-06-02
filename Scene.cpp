/*------------------------------
	fichier Scene.cpp
fonctions de la class ScenePlan
Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
--------------------------------*/
#include "Scene.h"
#include <iostream>
#include <QGraphicsPolygonItem>
std::map<std::string, QColor> ScenePlan::tab_couleurs = {{"noir", Qt::black}, {"rouge", Qt::red}};

// constructeur
ScenePlan::ScenePlan(Carte carte, std::vector<int> chemin)
{
    QColor coul = tab_couleurs["noir"];
    qreal epais = 0;
    QGraphicsPolygonItem *polygonItem = new QGraphicsPolygonItem;
    QPolygonF c;
    Contour contour = carte.getContour();

    //Boucle qui récupère les contours du polygone (La Carte)
    for (auto &elem : contour.getPoints())
    {
        c << QPointF(elem.getLon(), elem.getLat());
    }

    //construction du polygone (La Carte)
    polygonItem->setPolygon(c);
    polygonItem->setPen(QPen(coul, epais, Qt::SolidLine));
    polygonItem->setBrush(Qt::green);
    this->addItem(polygonItem);

    std::vector<Ville> ville = carte.getVilles();
    std::vector<Waypoint *> wayp = carte.getWaypoints();
    std::vector<Waypoint *> w;
    for (auto &elem : wayp)
    {
        for (auto &elem2 : ville)
        {
            if (elem->getNom() == elem2.getNom())
            {
                w.push_back(elem);
            }
        }
    }
    QColor coul2 = tab_couleurs["rouge"];
    std::string text_tooltip;

    //construction des points waypoint sur la carte
    for (auto &elem : w)
    {
        text_tooltip = elem->getNom();
        qreal taille_o = 0.05;
        QGraphicsRectItem *vi = new QGraphicsRectItem(0, 0, -taille_o, -taille_o);
        vi->setPos(elem->getLon() + 0.025, elem->getLat() + 0.025);
        vi->setPen(QPen(coul2, taille_o / 4, Qt::SolidLine));
        vi->setBrush(coul2);
        std::string text_tooltip = elem->getNom();
        vi->setToolTip(QString::fromStdString(text_tooltip));
        this->addItem(vi);
    }
    float lon1 = 0;
    float lat1 = 0;
    float lon2 = 0;
    float lat2 = 0;

    //on récupère les routes et leurs coordonnées
    std::vector<Route> route = carte.getRoutes();
    for (auto &elem : route)
    {
        std::string deb = elem.getIDeb();
        std::string fin = elem.getIFin();
        for (auto &elem2 : wayp)
        {
            if (elem2->getNom() == deb)
            {
                lon1 = elem2->getLon();
                lat1 = elem2->getLat();
            }
        }
        for (auto &elem2 : wayp)
        {
            if (elem2->getNom() == fin)
            {
                lon2 = elem2->getLon();
                lat2 = elem2->getLat();
            }
        }
        //construction des routes
        QGraphicsLineItem *ligne2 = new QGraphicsLineItem(0, 0, lon2 - lon1, lat2 - lat1);

        // l'origine de la ligne est le point 1
        ligne2->setPos(lon1, lat1);
        ligne2->setPen(QPen(coul, epais, Qt::SolidLine));
        this->addItem(ligne2);
    }

    //si il y a un itinéraire, donc un chemin
    //on construit la route à suivre
    if (chemin[0] != -1)
    {
        qreal epais2 = 0.05;
        std::vector<Waypoint *> w_r = carte.getWaypoints();
        std::vector<float> longitude;
        std::vector<float> latitude;
        for (auto p : chemin)
        {
            longitude.push_back(w_r[p]->getLon());
            latitude.push_back(w_r[p]->getLat());
        }
        for (int id = 0; id < (int)longitude.size() - 1; id++)
        {
            QGraphicsLineItem *ligne4 = new QGraphicsLineItem(0, 0, longitude[id + 1] - longitude[id], latitude[id + 1] - latitude[id]);
            // l'origine de la ligne est le point 1
            ligne4->setPos(longitude[id], latitude[id]);
            ligne4->setPen(QPen(coul2, epais2, Qt::SolidLine));
            this->addItem(ligne4);
        }
    }
}