#include "LoginDialog.h"
#include <QDebug>
#include <QGridLayout>

LoginDialog::LoginDialog(){
    this->setWindowTitle("BDD Login");
    this->setMinimumWidth(100);

    QGridLayout* hl = new QGridLayout();

    label1 = new QLabel("Hôte (nom ou ip)");
    hl->addWidget(label1,0,0);

    label2 = new QLabel("Nom base données");
    hl->addWidget(label2,1,0);

    label3 = new QLabel("User base");
    hl->addWidget(label3,2,0);

    label4 = new QLabel("Mot de passe");
    hl->addWidget(label4,3,0);

    line1 = new QLineEdit();
    hl->addWidget(line1,0,1);

    line2 = new QLineEdit();
    hl->addWidget(line2,1,1);

    line3 = new QLineEdit();
    hl->addWidget(line3,2,1);

    line4 = new QLineEdit();
    hl->addWidget(line4,3,1);
    line4->setEchoMode(QLineEdit::Password);

    button1 = new QPushButton("Login");
    button2 =  new QPushButton("Annuler");    
    hl->addWidget(button1,4,0);
    hl->addWidget(button2,4,1);
    connect(button1, SIGNAL(clicked()), this, SLOT(slot_bouton1()));
    connect(button2, SIGNAL(clicked()), this, SLOT(slot_bouton2()));
    this->setLayout(hl);
    
}


void LoginDialog::slot_bouton1(){
    l1 = line1->text();
    l2 = line2->text();
    l3 = line3->text();
    l4 = line4->text();

    line1->clear();
    line2->clear();
    line3->clear();
    line4->clear();

    if(l1.isEmpty()||l2.isEmpty()||l3.isEmpty()||l4.isEmpty()){
        QMessageBox::warning( this, "Warning", "Tous les champs doivent être remplis");
    }

    accept();


}

void LoginDialog::slot_bouton2(){
    close();
}

void LoginDialog::getResult(std::string& host, std::string& base, std::string& user, std::string& pwd){
    host = l1.toStdString();
    base = l2.toStdString();
    user = l3.toStdString();
    pwd = l4.toStdString();
}