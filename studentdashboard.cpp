#include "studentdashboard.h"
#include "ui_studentdashboard.h"
#include <QDebug>

StudentDashboard::StudentDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentDashboard)
{
    qDebug() << "here";
    ui->setupUi(this);
//    this->setCentralWidget(ui->gridLayout);
}

StudentDashboard::~StudentDashboard()
{
    delete ui;
}
