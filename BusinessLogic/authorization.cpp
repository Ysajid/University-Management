#include "authorization.h"
#include "datahandler.h"

Authorization::Authorization()
{
    password_table = "passwords";
}

bool Authorization::checkValidity(QString name, QString password)
{
    QSqlQuery query("select * from "+ password_table +";");

    while(query.next()){
        if(query.value(0).toString() == name){
            Authorization a;
            if(query.value(1).toString() == a.encodePassword(password)) return true;
            else return false;
        }
    }
//    authFile->close();
    return false;
}

bool Authorization::checkUserValidity(QString name)
{

    QSqlQuery query("select id from "+ password_table +";");

    while(query.next()){
        if(query.value(0).toString() == name){
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
