#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <QString>
#include <QList>


using namespace std;
class Department
{
    QString dept_id;
    QString dept_name;
    QString building;
    QString budget;

public:
    Department();
    Department(QString id, QString name, QString building, QString budget);

    QList <QString> course_ids;
    QList <QString> teacher_ids;

    QString &getId(){return dept_id;}
    QString &getName(){return dept_name;}
    QString &getBuilding() {return building;}
    QString &getBudget() {return budget;}
};

#endif // DEPARTMENT_H
