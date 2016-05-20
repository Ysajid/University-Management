#include "authorization.h"
#include <QDebug>
#include <QDataStream>
#include <QCryptographicHash>

Authorization::Authorization()
{
}

bool Authorization::checkValidity(QString name, QString password)
{
    QString authFileName = "passcodes.text";
    QFile *authFile = new QFile(authFileName);
    authFile->open(QFile::ReadOnly);

    QDataStream in(authFile);

    while(!in.atEnd()){
        QString checkName, checkPass;
        in >> checkName >> checkPass;
        if(checkName == name){
            Authorization a;
            if(checkPass == a.encodePassword(password)) return true;
            else return false;
        }
    }
    return false;
}

bool Authorization::checkUserValidity(QString name)
{
    QString authFileName = "passcodes.text";
    QFile *authFile = new QFile(authFileName);
    authFile->open(QFile::ReadOnly);

    QDataStream in(authFile);

    while(!in.atEnd()){
        QString checkName, checkPass;
        in >> checkName >> checkPass;
        if(checkName == name){
            return true;
        }
    }
    return false;
}

QString Authorization::encodePassword(QString pass)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    char * data = new char[pass.length()];
    for(int i=0; i<pass.length(); i++){
        data[i] = pass[i].unicodeVersion();
    }

    hash.addData(data);

    for(int i=0; i<pass.length(); i++){
        pass[i] = QChar(data[i]);
    }

    return pass;
}
