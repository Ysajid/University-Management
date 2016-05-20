#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QDebug>
#include <QThread>

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    result = CANCELED;
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_login_clicked()
{
    QString name = ui->name->text();
    QString pass = ui->password->text();
    if(Authorization().checkUserValidity(name)){
        if(Authorization().checkValidity(name,pass)){
            qDebug() << "true";
            result = LOGGED_IN;
            emit finished(1);
        }
        else ui->name->setText("wrong password");
    } else ui->name->setText("user name invalid");
}

void LoginScreen::on_cancel_clicked()
{
    result= CANCELED;
    exit(1);
}

void LoginScreen::on_register_2_clicked()
{
    result = REGISTRATION;
    close();
}
