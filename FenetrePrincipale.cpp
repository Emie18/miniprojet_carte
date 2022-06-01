/*---------------------
	fichier FenetrePrincipale.cpp
fonctions de la class FenetrePrincipale
-----------------------*/
#include  "FenetrePrincipale.h"
#include "dijkstra.h"
FenetrePrincipale::FenetrePrincipale(Carte carte){
    //initialisation de la fenêtre
    this->setWindowTitle("Itineraire");
    this->setMinimumWidth(800);
    this->setMinimumHeight(600);
    this->c = carte;
    mainLayout = new QHBoxLayout();

    std::vector<int> vide ={-1};
    myscene = new ScenePlan(carte,vide);
    mainLayout->addWidget(group_box());
    this->myview1 = new GrandeVue(myscene,this);
    mainLayout->addWidget(myview1);
    barre_statut = statusBar();

    mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    connect( myview1, &GrandeVue::coord_viewport, myview2, &MinieVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos);
	
}

QGroupBox * FenetrePrincipale::group_box() {
	QGroupBox * gb = new QGroupBox;
	QString str_tmp;

	vbox = new QVBoxLayout;
	gb->setLayout(vbox);

	this->villedep = new QLabel("Ville de départ");
    this->villearr = new QLabel("Ville d'arrivée");
    this->distance = new QLabel("Distance: ");
    this->ville1 = new QLineEdit;
    this->ville2 = new QLineEdit; 
    this->calculer = new QPushButton("calculer");

	myview2 = new MinieVue(myscene, this);

    connect(calculer, SIGNAL(clicked()), this, SLOT(slot_bouton()));

	vbox->addWidget(villedep);
    vbox->addWidget(ville1);
    vbox->addWidget(villearr);
    vbox->addWidget(ville2);
    vbox->addWidget(calculer);
    vbox->addWidget(distance);
    vbox->addWidget(myview2);

	return gb;
}

void FenetrePrincipale::affiche_pos( QPointF p){
	QString msg = "Coordonnées géographiques: "
			+ QString::number(p.y(),'f') + "°N "
			+ QString::number(p.x(),'f') + "°W";
	barre_statut->showMessage(msg);
}

//fonction affiche intineraire
void FenetrePrincipale::slot_bouton(){

    //on recupère les saisis de l'utilisateur
    std::string depart = this->ville1->text().toStdString();
    std::string arrive = this->ville2->text().toStdString();
    //on récupère les routes et les waypoints
    std::vector<Route> r =this->c.getRoutes();
    std::vector<Waypoint*> w = this->c.getWaypoints();
    QString d ;
    //nombre de waypoints = 58
    int nb_waypoint = (int)w.size();
    //construction du graph
    //tableau à deux entrées reliant
    //les différents chemins et leurs distances
    int graph[nb_waypoint][58] ={0};
    for (int source = 0; source<(int)w.size();source++){
        for (int dest = 0; dest<(int)w.size();dest++){
            for (int route = 0; route<(int)r.size();route++){
                if(r[route].getIDeb()==w[source]->getNom()&& r[route].getIFin()==w[dest]->getNom()){
                    graph[source][dest]=r[route].getDistance();
                    graph[dest][source]=r[route].getDistance();
                }
            }
        }
    }
    //vérification de l'entrer saisie de l'utilisateur
    if(-1==ville_index(depart,w)|| -1==ville_index(arrive,w)){
         QMessageBox::warning( this, "Warning", "Vous n'avez pas correctement saisi les villes\n(doit commencer par une Majuscule)");
    }
    //initialisaton de l'index de depart (src) et d'arrivée (dest)
    int src = ville_index(depart,w);
    int dest = ville_index(arrive,w);
    //variable qui contiendra la distance
    int distance;
    //fonction de recherche de chemin le plus court
    //elle renvoit un vector des chemins à prendre
    //elle prend en paramêtre le grap, le depart(src)
    //la destination (dest), et la référence de distance
    std::vector<int> chemin = dijkstra(graph, src, dest,&distance);
    //affichage de la distance dans la fenetre
    d = QString::fromStdString("Distance: " +std::to_string(distance)+" Km");
    this->distance->setText(d);
    //destruction de l'encienne scene,et les deux vues;
    delete myscene;
    delete myview1;
    delete myview2;
    //construction de la nouvelle scene des des vues
    //avec le chemin remplis
    this->myscene = new ScenePlan(c,chemin);
    this->myview1 = new GrandeVue(myscene,this);
    this-> myview2 = new MinieVue(myscene, this);
    this->mainLayout->addWidget(myview1);
    connect( myview1, &GrandeVue::coord_viewport, myview2, &MinieVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos);
    vbox->addWidget(myview2);
   
}
//fonction qui renvoit -1 si la ville rentrer est mauvaise
//sinon elle renvoit l'index de la ville
int FenetrePrincipale:: ville_index(std::string nom,std::vector<Waypoint*> w){
    int index=-1;
    for(int i = 0; i<(int)w.size();i++){
        if(nom==w[i]->getNom()){
            index = i;
        }
    }
    return index;
}


