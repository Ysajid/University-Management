#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QCryptographicHash>

class Authorization
{
    QFile* authFile;

public:
    QString authFileName;
    Authorization();
    bool checkValidity(QString name , QString password);
    bool checkUserValidity(QString name);
    QString encodePassword(QString);

};

#endif // AUTHORIZATION_H
