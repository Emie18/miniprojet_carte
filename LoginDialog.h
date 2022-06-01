/*-------------------------
    fichier LoginDialog.h
    contient la class 
    LoginDialog
--------------------------*/
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>

#include <string>

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog();
    ~LoginDialog(){};
    void getResult(std::string &host, std::string &base, std::string &user, std::string &pwd);

private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;

    QPushButton *button1;
    QPushButton *button2;

    QString l1;
    QString l2;
    QString l3;
    QString l4;

public slots:
    void slot_bouton1();
    void slot_bouton2();
};
#endif