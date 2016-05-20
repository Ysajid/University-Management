#include "student_registration.h"
#include "ui_student_registration.h"
#include "datahandler.h"
#include <QStringListModel>

Student_Registration::Student_Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Registration)
{
    ui->setupUi(this);
    ui->department->setModel(this->departments);
}

Student_Registration::~Student_Registration()
{
    delete ui;
}

void Student_Registration::on_done_clicked()
{
    name = ui->name->text();
    father_name = ui->father_name->text();
    address = ui->address->text();
    department_id = ui->department->currentIndex();
    year = ui->year->currentData().toInt();
}

void Student_Registration::on_cancel_clicked()
{
    exit(1);
}
