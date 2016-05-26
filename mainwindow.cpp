#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datahandler.h"
#include "students_tab.h"
#include "department_tab.h"
#include "teachers_tab.h"
#include "courses_tab.h"
#include <QTabWidget>
#include <QTableView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DataHandler data;
    ui->student_cnt->setText(QString::number(data.students.size()));
    ui->dept_cnt->setText(QString::number(data.departments.size()));
    ui->course_cnt->setText(QString::number(data.courses.size()));
    ui->teacher_cnt->setText(QString::number(data.teachers.size()));

    ui->home_tab->setAccessibleName("Home");

    ui->home->addTab(new students_tab, QIcon(""), "Students");
    ui->home->addTab(new teachers_tab, QIcon(""), "Teachers");
    ui->home->addTab(new courses_tab, QIcon(""), "Courses");
    ui->home->addTab(new department_tab, QIcon(""), "Departments");

}

MainWindow::~MainWindow()
{
    delete ui;
}
