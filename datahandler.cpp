#include "datahandler.h"
#include "BusinessLogic/student.h"
DataHandler::DataHandler()
{
    student_fileName = "student.txt";
    dept_fileName = "department.txt";
    courses_fileName = "courses.txt";
    programme_fileName = "programme.txt";
    generalInfo_fileName = "general.txt";

    loadInfos();
}

DataHandler::DataHandler(QMap<int, *Student> &students,
                         QMap<int, *Course> &courses,
                         QMap<int, *Department> &departments){
    student_fileName = "student.txt";
    dept_fileName = "department.txt";
    courses_fileName = "courses.txt";
    programme_fileName = "programme.txt";
    generalInfo_fileName = "general.txt";

    loadInfos();

    this->students = students;
    this->courses = courses;
    this->departments = departments;
}

void DataHandler::loadInfos()
{
    studentFile = new QFile(student_fileName);
    studentFile->open(QFile::ReadWrite);

//    if(!studentFile->open(QFile::ReadWrite || QFile::Text)){
//        return;
//    }

    QDataStream in(studentFile);
    while(!in.atEnd()){
        Student student;
        in >> student;
    }
    studentFile->close();

}

//QDataStream &operator<<(QDataStream &out, const Student &student)
//{
//    out << student.getId() << student.getName();
//        << student.getDepartment()->dept_id;
//    return out;
//}

QDataStream &operator >> (QDataStream &in, const Student &student)
{
    in >> student.id >> student.name;
        >> student.dept->dept_id;
    return out;
}
