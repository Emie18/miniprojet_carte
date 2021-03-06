/*--------------------------
    fichier main.cpp
    contient la fonction
    principale
    Auteurs : Emilie Le Rouzic
    &   Maryline Le Bot
----------------------------*/

#include <QApplication>
#include <QMessageBox>

#include "FenetrePrincipale.h"
#include "LoginDialog.h"
#include "BDD.h"
#include "Carte.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginDialog dlg;
    std::string host, base, user, pwd;
    if (!dlg.exec())
    {
         // Ouverture de la boite de dialogue
        std::cout << "Sortie de l'application\n";
        return 1;
    }
    // Récupération des saisies après fermeture de la Dialog box
    dlg.getResult(host, base, user, pwd);
    std::cout << "Lecture base plans" << std::endl;
    Carte cartes;
    try
    {
        // Connexion BD
        BDD bdd("tcp://"+host+":3306", base, user, pwd);

        //récupération de la carte
        cartes = Carte(bdd.getWaypoint(), bdd.getRoute(), bdd.getContour(), bdd.getVille());
    }
    catch (sql::SQLException &e)
    {
        std::cout << "Erreur MySQL. Sortie de l'application\n";
        QMessageBox msg(QMessageBox::Critical, "Erreur mySQL",
                        e.what());
        msg.exec();
        return 1;
    }

    FenetrePrincipale window(cartes);
    window.show();
    return app.exec();

    return 0;
}