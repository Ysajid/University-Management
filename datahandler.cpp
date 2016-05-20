#include "datahandler.h"
#include "BusinessLogic/student.h"
#include <QDebug>


DataHandler::DataHandler()
{
    student_fileName = "student.txt";
    dept_fileName = "/mnt/sda7/workshop/qt Projects/UniversityManagement/department.txt";
    courses_fileName = "courses.txt";
    programme_fileName = "programme.txt";
    generalInfo_fileName = "general.txt";

//    departments = new QAbstractListModel();

    dept_list = new QStringList;

    loadInfos();
}

//DataHandler::DataHandler(QMap<QString, Department*> &departments){

//    student_fileName = "student.txt";
//    dept_fileName = "department.txt";
//    courses_fileName = "courses.txt";
//    programme_fileName = "programme.txt";
//    generalInfo_fileName = "general.txt";

//    loadInfos();

//    this->students = students;
//    this->courses = courses;
//    this->departments = departments;
//}

void DataHandler::loadInfos()
{
    deptFile = new QFile(dept_fileName);
    if(deptFile->open(QFile::ReadWrite | QFile::Text))qDebug() << deptFile->fileName();

//    if(!studentFile->open(QFile::ReadWrite || QFile::Text)){
//        return;
//    }

    QTextStream in(deptFile);
    while(!in.atEnd()){
        Department dept;
        in >> dept.getId() >> dept.getName() >> dept.getBuilding() >> dept.getBudget();
        qDebug() << dept.getId();
        *dept_list << dept.getName();
        departments_map[dept.getId()] = &dept;
    }
    departments = new QStringListModel();
    departments->setStringList(*dept_list);
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


