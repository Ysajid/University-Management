#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>
#include <QSqlQuery>

class Authorization
{
    QString password_table;

public:
    QString authFileName;
    Authorization();
    bool checkValidity(QString name , QString password);
    bool checkUserValidity(QString name);
    QString encodePassword(QString);

};

#endif // AUTHORIZATION_H
