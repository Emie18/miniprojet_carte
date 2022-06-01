/*---------------------
	fichier FenetrePrincipale.h
contient la class FenetrePrincipale
-----------------------*/
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
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QMessageBox>
#include "Carte.h"
#include "Scene.h"
#include "GrandeVue.h"
#include "MinieVue.h"

class FenetrePrincipale : public QMainWindow{
    Q_OBJECT
    public:
        FenetrePrincipale(Carte carte);
        ~FenetrePrincipale() override {}
        QGroupBox* group_box();
        //fonction pour récupérer l'index de la ville
        //rentrée par l'utilisation
        int ville_index(std::string nom,std::vector<Waypoint*> w);
    private:
    
        QLabel* villedep;
        QLabel* villearr;
        QLabel* distance;
        QLineEdit* ville1;
        QLineEdit* ville2;
        QPushButton* calculer;
        GrandeVue *myview1;
		MinieVue *myview2;
        ScenePlan *myscene;
        QStatusBar *barre_statut;
        QWidget* mainWidget;
        QHBoxLayout* mainLayout;
        QVBoxLayout *vbox;
        Carte c;
        private slots:
		    void affiche_pos( QPointF p);
            void slot_bouton();
};
#endif

