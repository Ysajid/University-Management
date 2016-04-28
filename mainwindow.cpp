#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"
#include "ui_information.h"
#include "BusinessLogic/student.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMap <int , Student> students;
    QMap <int , Course> courses;
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
    qDebug() << "done";
}

void MainWindow::on_pushButton_2_clicked()
{

}
