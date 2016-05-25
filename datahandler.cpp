#include "datahandler.h"
#include <QDebug>


DataHandler::DataHandler(int type)
{
    this->type = type;
    if(type != 0){
        student_fileName.append(HOME_DIR) += "students.txt";
        dept_fileName.append(HOME_DIR) += "department.txt";
        courses_fileName.append(HOME_DIR) += "courses.txt";
        programme_fileName.append(HOME_DIR) += "programme.txt";
        generalInfo_fileName.append(HOME_DIR) += "general.txt";

//        departments = new QAbstractListModel();

//        dept_list = new QStringList;

        loadData();
    }
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

void DataHandler::loadData()
{
    deptFile = new QFile(dept_fileName);
    if(deptFile->open(QFile::ReadWrite | QFile::Text))qDebug() << deptFile->fileName() << " Opened";

    QTextStream *in;
    in = new QTextStream(deptFile);
    while(!in->atEnd()){
        Department dept;
        *in >> dept.getId() >> dept.getName().replace("_"," ") >> dept.getBuilding().replace("_"," ") >> dept.getBudget();
        qDebug() << dept.getId();
        if(dept.getId() == "") continue;
        dept_list << dept.getName();
        departments[dept.getId()] = dept;
    }
//    departments_list_model = new QStringListModel();
    departments_list_model.setStringList(dept_list);
    deptFile->close();

    studentFile = new QFile(student_fileName);
    if(studentFile->open(QFile::ReadWrite | QFile::Text))qDebug() << studentFile->fileName() << " Opened";

    in = new QTextStream(studentFile);

    while(!in->atEnd()){
        Student student;
        *in >> student.getId()
           >> student.getName().replace("_"," ")
           >> student.getFatherName().replace("_"," ")
           >> student.getAddress().replace("_"," ")
           >> student.getDept()
           >> student.getCourseCnt()
           >> student.getSemester()
           >> student.getYear();
        qDebug() << student.getId();
        if(student.getId() == "")continue;
//        *in << student.getName();
        students[student.getId()] = student;
    }
//    students_list_model = new QStringListModel();

    students_list_model.setStringList(student_list);
    studentFile->close();

    delete in;
}

void DataHandler::saveData()
{
    deptFile->open(QFile::WriteOnly);
    QTextStream *out;
    out = new QTextStream(deptFile);
    QList<QString> keys = departments.keys();
    qDebug() << "length = " << keys.length();
    foreach(QString i , keys){
//        QString i = keys[j];
        *out << departments[i].getId() << " "
            << departments[i].getName().replace(" ","_") << " "
            << departments[i].getBuilding().replace(" ","_") << " "
            << departments[i].getBudget() << "\n";
        qDebug() << departments[i].getId() << departments[i].getName() << departments[i].getBuilding() << departments[i].getBudget();
    }
    deptFile->close();


    studentFile->open(QFile::WriteOnly | QFile::Text);
    out = new QTextStream(studentFile);
    keys = students.keys();
    qDebug() << "length = " << keys.length();
    foreach(QString i , keys){
//        QString i = keys[j];
        *out << students[i].getId() << " "
            << students[i].getName().replace(" ","_") << " "
            << students[i].getFatherName().replace(" ","_") << " "
            << students[i].getAddress().replace(" ","_") << " "
            << students[i].getDept() << " "
            << students[i].getCourseCnt() << " "
            << students[i].getSemester() << " "
            << students[i].getYear() << endl;
    }
    studentFile->close();

    delete out;
}

bool DataHandler::addNewStudent(int int_id ,
                                QString name,
                                QString father_name,
                                QString address,
                                int dept_id,
                                int year,
                                int semester,
                                QString password){

    QString id = QString::number(year%100);
    if(id.size() == 1) id = "0" + id;
    id += (QString::number(dept_id) + "4");
    if(int_id < 10) id += "0" + QString::number(int_id);
    else id += QString::number(int_id);
//    qDebug() << id;
    Student student(id,name,father_name,address,dept_id,year,semester);
    if(students[id].getId() == NULL) {
        students[id] = student;
        QFile *passFile;
        Authorization auth;
        passFile = new QFile(auth.authFileName);
        qDebug() << auth.authFileName;
        passFile->open(QFile::ReadWrite | QFile::Text);
        QTextStream out(passFile);
        out.seek(passFile->size());
        out << id << " " << Authorization().encodePassword(password);
        passFile->close();
    }
    else return false;

    return true;
}


DataHandler::~DataHandler()
{
    qDebug() << "asd";
    if(type != 0) saveData();
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
