#ifndef TEACHER_H
#define TEACHER_H
#include <QString>
#include <QSqlQuery>

class Teacher
{
    int id;
    QString name;
    int dept_id;
    int salary;
    QString designation;

public:
    Teacher();
    Teacher(int id, QString name, QString designation , int dept_id, int salary);
    int &getId() {return id;}
    QString &getName() {return name;}
    QString &getDesignation() {return designation;}
    int &getDept() {return dept_id;}
    int &getSalary() {return salary;}


    friend void operator << (Teacher &t , QSqlQuery query);
    friend void operator >> (Teacher &t , int notused);
};

#endif // TEACHER_H
