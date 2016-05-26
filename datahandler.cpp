#include "datahandler.h"
#include <QDebug>


DataHandler::DataHandler(int type)
{
    this->type = type;

    students_table ="students";
    dept_table = "departments";
    courses_table = "courses";
    teachers_table = "teachers";
    password_table = "passwords";
    generalInfo_fileName.append(HOME_DIR) += "general.txt";

    if(type != 0){
//        departments = new QAbstractListModel();
//        students_model = new QStandardItemModel(this);

//        dept_list = new QStringList;

        loadData();
    }
}


void DataHandler::loadData()
{
//    deptFile = new QFile(dept_column);
//    if(deptFile->open(QFile::ReadWrite | QFile::Text))qDebug() << deptFile->fileName() << " Opened";

//    QTextStream *in;
//    in = new QTextStream(deptFile);

    QSqlQuery query;

    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = QString().append(HOME_DIR).append(DB_NAME);
    db.setDatabaseName(dbname);


    try {
        if(!db.open()) throw "Database failed to open\nClosing programme";
    }
    catch(QString error){
        QMessageBox::critical(0,"" , error ,0,0);
    }

    query =  QSqlQuery("select * from "+dept_table +";");

    while(query.next()){
        Department dept;
        dept << query;
        dept.getId() = query.at() + 1;
        qDebug() << dept.getId();
        if(dept.getId() == 0) continue;

        dept_list << dept.getName();
        departments[dept.getId()] = dept;
    }
//    departments_list_model = new QStringListModel();
    departments_list_model.setStringList(dept_list);
//    deptFile->close();

    query =  QSqlQuery("select * from "+students_table +";");

    while(query.next()){
        Student student;

        student << query;

        qDebug() << student.getId();
        if(student.getId() == "")continue;
//        *in << student.getName();
        students[student.getId()] = student;
    }
//    students_list_model = new QStringListModel();

//    students_list_model.setStringList(student_list);
//    studentFile->close();

//    delete in;
}

//void DataHandler::saveData()
//{
//    deptFile->open(QFile::WriteOnly);
//    QTextStream *out;
//    out = new QTextStream(deptFile);
//    QList<QString> keys = departments.keys();
//    qDebug() << "length = " << keys.length();
//    foreach(QString i , keys){
////        QString i = keys[j];
//        *out << departments[i].getId() << " "
//            << departments[i].getName().replace(" ","_") << " "
//            << departments[i].getBuilding().replace(" ","_") << " "
//            << departments[i].getBudget() << "\n";
//        qDebug() << departments[i].getId() << departments[i].getName() << departments[i].getBuilding() << departments[i].getBudget();
//    }
//    deptFile->close();


//    studentFile->open(QFile::WriteOnly | QFile::Text);
//    out = new QTextStream(studentFile);
//    keys = students.keys();
//    qDebug() << "length = " << keys.length();
//    foreach(QString i , keys){
////        QString i = keys[j];
//        *out << students[i].getId() << " "
//            << students[i].getName().replace(" ","_") << " "
//            << students[i].getFatherName().replace(" ","_") << " "
//            << students[i].getAddress().replace(" ","_") << " "
//            << students[i].getDept() << " "
//            << students[i].getCourseCnt() << " "
//            << students[i].getSemester() << " "
//            << students[i].getYear() << endl;
//    }
//    studentFile->close();

//    delete out;
//}

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

        QSqlQuery query;
        query.exec("insert into "+password_table +" values('"+
                   id +"','" + Authorization().encodePassword(password)+"')");

        query.exec("insert into "+ students_table + " values ("
                   + "'" + student.getId() + "',"
                   + "'" + student.getName() + "',"
                   + "'" + student.getFatherName() + "',"
                   + "'" + student.getAddress() + "',"
                   +QString::number(student.getCourseCnt()) + ","
                   +QString::number(student.getDept()) + ","
                   +QString::number(student.getSemester()) + ","
                   +QString::number(student.getYear())
                   + ");");

        qDebug() << "insert into "+ students_table + " values ("
                    + "'" + student.getId() + "',"
                    + "'" + student.getName() + "',"
                    + "'" + student.getFatherName() + "',"
                    + "'" + student.getAddress() + "',"
                    +QString::number(student.getCourseCnt()) + ","
                    +QString::number(student.getDept()) + ","
                    +QString::number(student.getSemester()) + ","
                    +QString::number(student.getYear())
                    + ");";
    }
    else return false;

    return true;
}

void DataHandler::addNewDepartment(QString name, QString building, int budget)
{
    Department dept(departments.size() + 1, name, building , budget);

    dept >> 0;
    departments[dept.getId()] = dept;
}

void DataHandler::addNewTeacher(int id, QString name, QString designation, int dept_id, int salary)
{
    Teacher t(id, name, designation, dept_id, salary);

    t >> 0;
    teachers[t.getId()] = t;
}

void DataHandler::addNewCourse(QString id, QString name, int dept_id, int semester,double credit)
{
    Course course(id, name, dept_id, semester, credit);

    course >> 0;
}


DataHandler::~DataHandler()
{
//    qDebug() << "asd";
//    if(type != 0) saveData();
    db.close();
}
