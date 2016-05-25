#include "authorization.h"
#include "datahandler.h"

Authorization::Authorization()
{
    authFileName.append(HOME_DIR) += "passcodes.txt";
}

bool Authorization::checkValidity(QString name, QString password)
{
    authFile = new QFile(authFileName);
    authFile->open(QFile::ReadOnly);

    QTextStream in(authFile);

    while(!in.atEnd()){
        QString checkName, checkPass;
        in >> checkName >> checkPass;
        if(checkName == name){
            Authorization a;
            if(checkPass == a.encodePassword(password)) return true;
            else return false;
        }
    }
    authFile->close();
    return false;
}

bool Authorization::checkUserValidity(QString name)
{
    qDebug() << authFileName;
    QFile *authFile = new QFile(authFileName);
    authFile->open(QFile::ReadOnly | QFile::Text);

    QTextStream in(authFile);

    while(!in.atEnd()){
        QString checkName, checkPass;
        in >> checkName >>  checkPass;
        qDebug() << checkName;
        if(checkName == name){
            authFile->close();
            return true;
        }
    }
    authFile->close();
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
