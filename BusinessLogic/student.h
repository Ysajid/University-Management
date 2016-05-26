#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <QString>
#include <QStringList>
#include <BusinessLogic/department.h>
#include <BusinessLogic/course.h>


using namespace std;

class Student
{
    QString id;
    QString name;
    QString father_name;
    QString address;

    int course_cnt;
    int dept_id;
    int year;
    int semester;
    QStringList courses_taken;

public:
    Student();
    Student(QString id, QString name ,QString father_name, QString address, int dept_id, int year, int semester);
    QString &getId(){return id;}
    QString &getName(){return name;}
    QString &getFatherName(){return father_name;}
    QString &getAddress(){return address;}
    int &getDept(){return dept_id;}
    int &getSemester(){return semester;}
    int &getYear(){return year;}
    int &getCourseCnt(){return course_cnt;}

    friend void operator << (Student &std , QSqlQuery query);
    friend void operator >> (Student &std , int notused);


//    Department& getDepartment(){return dept;}
//    QList <Course*> getCourses() {return courses_taken;}

//    void setDepartment(Department &dept){ this->dept = &dept;}
//    void addCourse(Course &newCourse) {
//        courses_taken.append(&newCourse);
//    }
//    friend QDataStream &operator >> (QDataStream &in, Student &student);

};

#endif // STUDENT_H
