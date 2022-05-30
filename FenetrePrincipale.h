#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QGroupBox>
#include <string>
#include <QBoxLayout>
#include <QGraphicsView>
#include "Carte.h"
#include "Scene.h"
//#include "GrandeVue.h"

class FenetrePrincipale : public QMainWindow{
    Q_OBJECT
    public:
        FenetrePrincipale(Carte carte);
        ~FenetrePrincipale() override {}
        QGroupBox* group_box(Carte carte);
        
    
    private:
        QLabel* villedep;
        QLabel* villearr;
        QLabel* distance;
        QLabel* valeur;
        QLabel* coordgeo;
        QLineEdit* ville1;
        QLineEdit* ville2;
        QPushButton* calculer;
        Carte c;
    public slots:
    void slot_bouton();
};
#endif