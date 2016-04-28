#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <QString>
#include <QList>
#include <BusinessLogic/department.h>
#include <BusinessLogic/course.h>


using namespace std;

class Student
{
    int id;
    string name;
    string address;

    int course_cnt;
    QList <Course> courses_taken;
    Department *dept;

public:
    Student();
    int getId(){return id;}
    void setID(int id){this->id = id;}
    QString getName(){return QString::fromStdString(name);}

    Department* getDepartment(){return dept;}
    QList <Course> getCourses() {return courses_taken;}

    void setDepartment(Department &dept){ this->dept = &dept;}
    void addCourse(Course &newCourse) {
        courses_taken.append(newCourse);
    }
    friend QDataStream &operator >> (QDataStream &in, const Student &student);

};

#endif // STUDENT_H
