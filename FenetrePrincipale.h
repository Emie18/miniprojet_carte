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

class FenetrePrincipale : public QMainWindow{
    Q_OBJECT
    public:
        FenetrePrincipale();//Plan plan);
        ~FenetrePrincipale() override {}
        QGroupBox* group_box();
    
    private:
        QLabel* villedep;
        QLabel* villearr;
        QLabel* distance;
        QLabel* coordgeo;
        QLineEdit* ville1;
        QLineEdit* ville2;
        QPushButton* calculer;
};
#endif
