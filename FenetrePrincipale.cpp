#include  "FenetrePrincipale.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

FenetrePrincipale::FenetrePrincipale(){//Plan plan){
    this->setWindowTitle("Itineraire");
    this->setMinimumWidth(500);

    QWidget* mainWidget = new QWidget();
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

    QGraphicsView* view2 = new QGraphicsView;
    mainLayout->addWidget(view2);

    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);

}