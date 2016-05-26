#include "mainwindow.h"
#include "loginscreen.h"
#include "student_registration.h"
#include "studentdashboard.h"
#include "loginscreen.h"
#include "information.h"
#include "ui_information.h"
#include "BusinessLogic/student.h"
#include "BusinessLogic/department.h"
#include "newdepartment.h"
#include <QDebug>
#include "BusinessLogic/authorization.h"
#include "loginscreen.h"
#include "datahandler.h"
#include <QApplication>



QMap <int , Department> DataHandler::departments;
QMap <QString , Student> DataHandler::students;

 QStringListModel DataHandler::departments_list_model;
 QStringListModel DataHandler::students_list_model;
 QStringListModel DataHandler::courses_list_model;
 QStringListModel DataHandler::teachers_list_model;

 QStandardItemModel *DataHandler::students_model;

 QFile *DataHandler::studentFile;
 QFile *DataHandler::deptFile;
 QFile *DataHandler::coursesFile;
 QFile *DataHandler::programmeFile;
 QFile *DataHandler::generalFile;

 QStringList DataHandler::dept_list;
 QStringList DataHandler::student_list;
 QStringList DataHandler::teacher_list;
 QStringList DataHandler::course_list;


 void operator <<(Department &dept , QSqlQuery query)
 {
//     dept.dept_id = query.value(0).toInt();
     dept.dept_name = query.value(1).toString();
     dept.building = query.value(2).toString();
     dept.budget = query.value(3).toInt();
 }

 void operator >>(Department &dept , int notused)
 {
     QSqlQuery query;
     query.exec("insert into "+DataHandler().dept_table
                + dept.dept_id
                + "'" + dept.dept_name + "'"
                + "'" + dept.building + "'"
                + dept.budget
                + ");");
 }

void operator << (Student &student , QSqlQuery query)
{
    student.id = query.value(0).toString();
    student.name = query.value(1).toString();
    student.father_name = query.value(2).toString();
    student.address = query.value(3).toString();

    student.course_cnt = query.value(4).toInt();
    student.dept_id = query.value(5).toInt();
    student.semester = query.value(6).toInt();
    student.year = query.value(7).toInt();
}

void operator >> (Student &student , int notused)
{
    QSqlQuery query;
    query.exec("insert into "+ DataHandler().student_column + " values ("
               + "'" + student.id + "'"
               + "'" + student.name + "'"
               + "'" + student.father_name + "'"
               + "'" + student.address + "'"
               +student.course_cnt
               +student.dept_id
               +student.semester
               +student.year
               + ");");

    qDebug() << "insert into "+ DataHandler().student_column + " values ("
                + "'" + student.id + "'"
                + "'" + student.name + "'"
                + "'" + student.father_name + "'"
                + "'" + student.address + "'"
                +student.course_cnt
                +student.dept_id
                +student.semester
                +student.year
                + ");";
}




int main(int argc, char *argv[])
{
    DataHandler data(1);

    QApplication a(argc, argv);

    LoginScreen login;
    login.exec();
    Student_Registration registration;
    MainWindow w;

    switch(login.result){
    case REGISTRATION :
//            login.finished(1);
        registration.exec();
        login.exec();
        break;
    case LOGGED_IN_ADMIN :
        qDebug() << "admin logged in";
        w.show();
    break;
    case LOGGED_IN :
        qDebug() << "user logged in";
        StudentDashboard dashboard;
        dashboard.show();
    break;
    }

    return a.exec();
}
