#include  "FenetrePrincipale.h"
#include "dijkstra.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

FenetrePrincipale::FenetrePrincipale(Carte carte){
    this->setWindowTitle("Itineraire");
    this->setMinimumWidth(500);
    this->c = carte;
    QHBoxLayout* mainLayout = new QHBoxLayout();
    //QGroupBox *groupBox = new QGroupBox;
    //QVBoxLayout *vbox = new QVBoxLayout;
    
    myscene = new ScenePlan(carte);
    mainLayout->addWidget(group_box());
    myview1 = new GrandeVue(myscene,this);
    mainLayout->addWidget(myview1);
    barre_statut = statusBar();
    //groupBox->setLayout(vbox);
    //mainLayout->addWidget(groupBox);

    
    // this->setCentralWidget(view2);
    // view2->fitInView(myscene2->sceneRect(),Qt::KeepAspectRatioByExpanding);
       
    
    // connect(view2, SIGNAL(valueChanged()), this, SLOT(slot_bouton1()));

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    connect( myview1, &GrandeVue::coord_viewport, myview2, &MinieVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos);
	
}

QGroupBox * FenetrePrincipale::group_box() {
	QGroupBox * gb = new QGroupBox;
	//gb->setMaximumWidth(largeur/3);
	QString str_tmp;

	QVBoxLayout *vbox = new QVBoxLayout;
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
    
    //qDebug() << "bouton 1 cliqué";
    
     
   std::string depart = this->ville1->text().toStdString();
   std::string arrive = this->ville2->text().toStdString();
    std::vector<Route> r =this->c.getRoutes();
    std::vector<Waypoint*> w = this->c.getWaypoints();
    QString d ;
    //int km =0;
    for(auto elem:r){
        if(depart==elem.getIDeb()&& arrive == elem.getIFin()){
           d = QString::fromStdString(std::to_string(elem.getDistance()));
        } 
        //std::cout<<elem.getDistance();
    }
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
    std::vector<int> chemin = dijkstra(graph, src, dest);
    std::cout<<"chemin: ";
    // for(int i=0;i<(int)w.size();i++){
    //         if(w[i]->getNom()==chemin[i] )
    //     }
    for(auto p:chemin){
        std::cout<<p<<" "<<w[p]->getNom();

    }  
     this->distance->setText(d);

}

int FenetrePrincipale:: ville_index(std::string nom,std::vector<Waypoint*> w){
    int i =0;
    while(nom!=w[i]->getNom()){
        i++;
    }
    return i;
}


