#include  "FenetrePrincipale.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "dijkstra.h"
FenetrePrincipale::FenetrePrincipale(Carte carte){
    this->setWindowTitle("Itineraire");
    this->setMinimumWidth(500);
    this->c = carte;
    // Contour contour = carte.getContour();
    // for (auto& elem: contour.getPoints()){

    //        std::cout<<elem.getLon();
    // }
    // std::cout<<"coucouc";
    
    QHBoxLayout* mainLayout = new QHBoxLayout();

    QGroupBox *groupBox = new QGroupBox;
    QVBoxLayout *vbox = new QVBoxLayout;
    
    this->villedep = new QLabel("Ville de départ");
    this->villearr = new QLabel("Ville d'arrivée");
    this->distance = new QLabel("Distance: ");
    this->coordgeo = new QLabel("Coordonnées géographiques: ");
    this->ville1 = new QLineEdit;
    this->ville2 = new QLineEdit; 
    this->calculer = new QPushButton("calculer");

    ScenePlan* myscene1 = new ScenePlan(carte);
    QGraphicsView* view1 = new QGraphicsView;
    //view1->scale(1,-1);
    //view1->fitInView(myscene1->sceneRect(),Qt::KeepAspectRatioByExpanding);
    
   
    vbox->addWidget(villedep);
    vbox->addWidget(ville1);
    vbox->addWidget(villearr);
    vbox->addWidget(ville2);
    vbox->addWidget(calculer);
    vbox->addWidget(distance);
    vbox->addWidget( view1);
    vbox->addWidget(coordgeo);

    
    groupBox->setLayout(vbox);
    mainLayout->addWidget(groupBox);

    ScenePlan* myscene2 = new ScenePlan(carte);
    QGraphicsView* view2 = new QGraphicsView(myscene2,this);
    view2->scale(1,-1);
    this->setCentralWidget(view2);
    view2->fitInView(myscene2->sceneRect(),Qt::KeepAspectRatioByExpanding);
    
    
    
    mainLayout->addWidget(view2);
   // connect(view2, SIGNAL(valueChanged()), this, SLOT(slot_bouton1()));

    connect(calculer, SIGNAL(clicked()), this, SLOT(slot_bouton()));
    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

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
        if(depart==elem.getIdeb()&& arrive == elem.getIfin()){
           d = QString::fromStdString(std::to_string(elem.getDistance()));
        } 
        //std::cout<<elem.getDistance();
    }
    std::string ville = "";
    int i =0;
    int graph[58][58] ={0};
    for (int source = 0; source<w.size();source++){
        for (int dest = 0; dest<w.size();dest++){
            for (int route = 0; route<r.size();route++){
                if(r[route].getIdeb()==w[source]->getNom()&& r[route].getIfin()==w[dest]->getNom()){
                    graph[source][dest]=r[route].getDistance();
                    graph[dest][source]=r[route].getDistance();
                }
            }
        }
    }
    // int deb = 0;
    // int fine = 0;
    // for(int i = 0; i< w.size();i++){
    //     if(w[i]->getNom()==depart){
    //         std::cout<<i<<"\n";
    //         deb = i;
    //     }
    //      if(w[i]->getNom()==arrive){
    //         std::cout<<i<<"\n";
    //         fine= i;
    //     }
    // }
    // std::cout<<graph[deb][fine];
    
    dijkstra(graph, 1);
    //printShortestDistance(graph, 1, 3, r.size());
    //dijkstra(graph, 3);
 //std::cout<< w.size();
    // for (int i = 0; i<w.size();i++){
    //         for (int j = 0; j<w.size();j++){
    //         std::cout<< graph[i][j] <<"  ";
    //     }
    //     std::cout<<"\n";
    // }




    //depart != arrive ||
    // std::vector<std::string> liste;
    // while ( i !=7){
        
    //     for(int i=0;i<r.size();i++){
    //         ville = r[i].getIdeb();
    //         if(ville==depart){
    //             i++;
    //             std::cout<<"debut :"<<r[i].getIdeb()<<"      next :"<<r[i].getIfin()<<"\n";
    //             // km = km + r[i].getDistance();
    //             ville = depart;
    //             depart = r[i].getIfin();
    //            // km += r[i].getDistance();
    //         }
    //     }
    // }
    // std::string s = "";
    // int l = 99999;
    // while(depart !=arrive){
    //     for(auto elem : r){
    //         if(elem.getIdeb() == depart && l< elem.getDistance()){
    //             l = elem.getDistance();
    //             depart = elem.getIfin();
    //             liste.push_back(elem.getIfin());
    //         }
    //     }
    // }
 
    //std::cout<<km;
     this->distance->setText(d);
   //distance = "13 Km";
}

