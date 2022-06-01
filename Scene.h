/*---------------------
	fichier Scene.h
contient la class ScenePlan
-----------------------*/
#ifndef SCENEPLAN_H
#define SCENEPLAN_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDebug>
#include "Carte.h"

class ScenePlan : public QGraphicsScene{
    Q_OBJECT
    public :
        ScenePlan(Carte carte,std::vector<int> chemin);
        ~ScenePlan() override {}
    private:
        static std::map<std::string, QColor> tab_couleurs;  
};
#endif