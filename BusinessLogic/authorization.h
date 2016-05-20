#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H
#include <QString>
#include <QFile>

class Authorization
{
//    QString authFileName = "passcodes.text";
//    QFile authFile;

public:
    Authorization();
    static bool checkValidity(QString name , QString password);
    static bool checkUserValidity(QString name);
    QString encodePassword(QString);

};

#endif // AUTHORIZATION_H
