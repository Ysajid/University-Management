#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include "BusinessLogic/authorization.h"
#include <QMessageBox>
#define REGISTRATION 2
#define LOGGED_IN 1
#define LOGGED_IN_ADMIN 4
#define CANCELED 3
#define ADMIN "admin"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = 0);
    int result;
    QString id;
    ~LoginScreen();

private slots:

    void on_login_clicked();

    void on_cancel_clicked();

    void on_register_2_clicked();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
