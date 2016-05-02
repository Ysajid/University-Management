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

DataHandler::DataHandler(QMap<QString, Department*> &departments){

    student_fileName = "student.txt";
    dept_fileName = "department.txt";
    courses_fileName = "courses.txt";
    programme_fileName = "programme.txt";
    generalInfo_fileName = "general.txt";

    loadInfos();

//    this->students = students;
//    this->courses = courses;
    this->departments = departments;
}

void DataHandler::loadInfos()
{
    deptFile = new QFile(dept_fileName);
    deptFile->open(QFile::ReadWrite);

//    if(!studentFile->open(QFile::ReadWrite || QFile::Text)){
//        return;
//    }

    QDataStream in(deptFile);
    while(!in.atEnd()){
        Department dept;
        in >> dept.getId() >> dept.getName() >> dept.getBuilding() >> dept.getBudget();
        departments[dept.getId()] = &dept;
    }
    deptFile->close();

}

//QDataStream &operator << (QDataStream &out, const Student &student)
//{
//    out << student.getId() << student.getName();
//        << student.getDepartment()->dept_id;
//    return out;
//}

//QDataStream &operator >> (Department &dept)
//{
//    QString id, name, building, budget;
//    this >> id >> name >> building >> budget;
//    Department dept2(id,name,building,budget);
//    dept = dept2;
//    return in;
//}


