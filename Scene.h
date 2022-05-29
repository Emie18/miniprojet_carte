#ifndef SCENEPLAN_H
#define SCENEPLAN_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "Carte.h"

class ScenePlan : public QGraphicsScene{
    Q_OBJECT
    public :
        ScenePlan(Carte carte);
        ~ScenePlan() override {}

    private:
        static std::map<std::string, QColor> tab_couleurs;  
};
#endif