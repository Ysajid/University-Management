#include "student.h"

Student::Student()
{

}

Student::Student(QString id, QString name, QString father_name, QString address, int dept_id, int year, int semester)
{
    this->name = name;
    this->id = id;
    this->father_name = father_name;
    this->address = address;
    this->dept_id = dept_id;
    this->year = year;
    this->semester = semester;
    this->course_cnt = 0;
}


//QDataStream &operator >> (QDataStream &in, Student &student)
//{
//    QString id, name, father_name, address;
//    int dept_id;
//    in >> student.id >> student.name >> student.dept->getId();

//    return in;
//}
