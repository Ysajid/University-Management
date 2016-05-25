#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"
#include "ui_information.h"
#include "BusinessLogic/student.h"
#include "BusinessLogic/department.h"
#include "newdepartment.h"
#include <QDebug>
#include "BusinessLogic/authorization.h"
#include "loginscreen.h"
#include "student_registration.h"
#include "datahandler.h"

QMap <QString , Department> DataHandler::departments;
QMap <QString , Student> DataHandler::students;

 QStringListModel DataHandler::departments_list_model;
 QStringListModel DataHandler::students_list_model;
 QStringListModel DataHandler::courses_list_model;
 QStringListModel DataHandler::teachers_list_model;


 QFile *DataHandler::studentFile;
 QFile *DataHandler::deptFile;
 QFile *DataHandler::coursesFile;
 QFile *DataHandler::programmeFile;
 QFile *DataHandler::generalFile;

 QStringList DataHandler::dept_list;
 QStringList DataHandler::student_list;
 QStringList DataHandler::teacher_list;
 QStringList DataHandler::course_list;


DataHandler data(1);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    LoginScreen login(this);
    login.exec();

    switch(login.result){
        case REGISTRATION :
            Student_Registration registration;
//            login.finished(1);
            registration.exec();
    }

    ui->setupUi(this);

//    QMap <int , Student> students;
//    QMap <int , Course> courses;
    QMap <int , Department> departments;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //show information page
    Information info;
    info.exec();
//    qDebug() << "done";
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_actionDepartment_triggered()
{
    newDepartment dept;
    dept.exec();
}
