#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <QString>
#include <QSqlQuery>
#include <QList>
#include <QVariant>

using namespace std;
class Department
{
    int dept_id;
    QString dept_name;
    QString building;
    int budget;

public:
    Department();
    Department(int id, QString name, QString building, int budget);

    QList <QString> course_ids;
    QList <QString> teacher_ids;

    int &getId(){return dept_id;}
    QString &getName(){return dept_name;}
    QString &getBuilding() {return building;}
    int &getBudget() {return budget;}

    friend void operator << (Department &dept , QSqlQuery query);
    friend void operator >> (Department &dept , int notused);
};

#endif // DEPARTMENT_H
