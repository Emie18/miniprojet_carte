#include  "FenetrePrincipale.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

FenetrePrincipale::FenetrePrincipale(Carte carte){
    this->setWindowTitle("Itineraire");
    this->setMinimumWidth(500);

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
    connect(view2, SIGNAL(valueChanged()), this, SLOT(slot_bouton1()));


    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

}
