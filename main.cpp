#include "mainwindow.h"
#include "loginscreen.h"
#include "student_registration.h"
#include "studentdashboard.h"
#include "loginscreen.h"
#include "information.h"
#include "ui_information.h"
#include "BusinessLogic/student.h"
#include "BusinessLogic/department.h"
#include "BusinessLogic/teacher.h"
#include "BusinessLogic/course.h"
#include <QDebug>
#include "BusinessLogic/authorization.h"
#include "loginscreen.h"
#include "datahandler.h"
#include <QApplication>



QMap <int , Department> DataHandler::departments;
QMap <QString , Student> DataHandler::students;
QMap <int , Teacher> DataHandler::teachers;

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
     dept.dept_name = query.value(0).toString();
     dept.building = query.value(1).toString();
     dept.budget = query.value(2).toInt();
 }

 void operator >>(Department &dept , int notused)
 {
     QSqlQuery query;
     query.exec("insert into "+DataHandler().dept_table + " values ("
                + "'" + dept.dept_name + "',"
                + "'" + dept.building + "',"
                + QString::number(dept.budget)
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
    query.exec("insert into "+ DataHandler().students_table + " values ("
               + "'" + student.id + "',"
               + "'" + student.name + "',"
               + "'" + student.father_name + "',"
               + "'" + student.address + "',"
               +QString::number(student.course_cnt) + ","
               +QString::number(student.dept_id) + ","
               +QString::number(student.semester) + ","
               +QString::number(student.year)
               + ");");
}

void operator << (Teacher &teacher, QSqlQuery query)
{
    teacher.name = query.value(0).toString();
    teacher.designation = query.value(1).toString();
    teacher.dept_id = query.value(2).toInt();
    teacher.salary = query.value(3).toInt();
}

void operator >> (Teacher &teacher , int notused)
{
    QSqlQuery query;
    query.exec("insert into "+ DataHandler().teachers_table + " values ("
               + "'" + teacher.name + "',"
               + "'" + teacher.designation + "',"
               +QString::number(teacher.dept_id) + ","
               +QString::number(teacher.salary)
               + ");");
}

void operator << (Course &course , QSqlQuery query)
{
    course.id = query.value(0).toString();
    course.name = query.value(1).toString();
    course.dept_id = query.value(2).toInt();
    course.semester = query.value(3).toInt();
    course.credit = query.value(4).toDouble();
}

void operator >> (Course &course , int notused)
{
    QSqlQuery query;
    query.exec("insert into "+ DataHandler().courses_table + " values ("
               + "'" + course.id + "',"
               + "'" + course.name + "',"
               +QString::number(course.dept_id) + ","
               +QString::number(course.semester) + ","
               +QString::number(course.credit)
               + ");");
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
