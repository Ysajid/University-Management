#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <QSqlQuery>

class Course
{
    QString id;
    QString name;
    int dept_id;
    int semester;
    double credit;

public:
    QString &getId() {return id;}
    QString &getName() {return name;}
    int &getDept() {return dept_id;}
    int &getSemester() {return semester;}
    double &getCredit() {return credit;}
    Course();
    Course(QString id, QString name, int dept_id, int semester, double credit);

    friend void operator << (Course &c , QSqlQuery query);
    friend void operator >> (Course &c , int notused);
};

#endif // COURSE_H
