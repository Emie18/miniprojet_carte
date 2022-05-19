#include <QApplication>
#include <QMessageBox>
#include <vector>
#include "FenetrePrincipale.h"
#include "LoginDialog.h"
#include "BDD.h"
#include "Carte.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    LoginDialog dlg;
    std::string host, base, user, pwd;
    if ( ! dlg.exec() ){ // Ouverture de la boite de dialogue
        std::cout << "Sortie de l'application\n";
        return 1;
    }
    // Récupération des saisies après fermeture de la Dialog box
    
    try {
        // Connexion BD
        BDD bdd("tcp://localhost:3306", "itineraires", "root", "jojo0108");
        //Contour co =bdd.getContour();
        // std::vector<Route> ro =bdd.getRoute();
        
        // // for(auto &elem : ro ){
        // //     std::cout<<'z'<<elem<'\n';
        // // }
        //Carte carte(bdd.getWaypoint(),bdd.getRoute(),bdd.getContour());
    }
    catch (sql::SQLException &e) {
        std::cout << "Erreur MySQL. Sortie de l'application\n";
        QMessageBox msg( QMessageBox::Critical, "Erreur mySQL", 
        e.what());
        msg.exec();
        return 1;
    }

    FenetrePrincipale window;
    window.show();
    Carte a;
    a.affiche();
    return app.exec();
    return 0; 
}