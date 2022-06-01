#include  "FenetrePrincipale.h"
#include "dijkstra.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

FenetrePrincipale::FenetrePrincipale(Carte carte){
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
	//gb->setMaximumWidth(largeur/3);
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
 
void FenetrePrincipale::slot_bouton(){

    std::string depart = this->ville1->text().toStdString();
    std::string arrive = this->ville2->text().toStdString();
    std::vector<Route> r =this->c.getRoutes();
    std::vector<Waypoint*> w = this->c.getWaypoints();
    QString d ;
    std::string ville = "";
    int graph[58][58] ={0};
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
    int src = ville_index(depart,w);
    int dest = ville_index(arrive,w);
    int distance;
    std::vector<int> chemin = dijkstra(graph, src, dest,&distance);
    d = QString::fromStdString("distance: " +std::to_string(distance)+" Km");
    std::cout<<"chemin: ";
  
    for(auto p:chemin){
        std::cout<<p<<" "<<w[p]->getNom();
    }  
    this->distance->setText(d);
    delete myscene;
    delete myview1;
    delete myview2;
    this->myscene = new ScenePlan(c,chemin);
    this->myview1 = new GrandeVue(myscene,this);
    this-> myview2 = new MinieVue(myscene, this);
    this->mainLayout->addWidget(myview1);
    connect( myview1, &GrandeVue::coord_viewport, myview2, &MinieVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos);
    vbox->addWidget(myview2);

}

int FenetrePrincipale:: ville_index(std::string nom,std::vector<Waypoint*> w){
    int i =0;
    while(nom!=w[i]->getNom()){
        i++;
    }
    return i;
}


