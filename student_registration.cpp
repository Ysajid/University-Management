#include "student_registration.h"
#include "ui_student_registration.h"
#include "datahandler.h"
#include <QStringListModel>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>

Student_Registration::Student_Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student_Registration)
{
    ui->setupUi(this);
    ui->department->setModel(&departments_list_model);

    QStringListModel *years;
    QStringListModel *ids;
    QStringListModel *semesters;

    years = new QStringListModel();
    ids = new QStringListModel();
    semesters = new QStringListModel();

    QStringList yearList;
    QStringList idList;
    QStringList semList;

    for(int i=1990; i<2017;i++){
        QString s = QString::number(i);
        yearList << s;
    }

    for(int i=1; i<50;i++){
        QString s = QString::number(i);
        idList << s;
    }

    for(int i=1; i<9;i++){
        QString s = QString::number(i);
        semList << s;
    }

    ids->setStringList(idList);
    years->setStringList(yearList);
    semesters->setStringList(semList);

    ui->year->setModel(years);
    ui->ids->setModel(ids);
    ui->semester->setModel(semesters);
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
    department_id = ui->department->currentIndex() + 1;
    year = ui->year->currentText().toInt();
    semester = ui->semester->currentText().toInt();
    password = ui->password->text();
    password2 = ui->password_2->text();

    if(name == NULL || father_name == NULL || address == NULL || department_id == 0 || year == 0 || semester == 0 || password == NULL){
        QMessageBox::information(this,"","All items are not set");
    }
    else {
        qDebug() << "new student";

        if(password != password2) QMessageBox::warning(this,"","Passwords dont match");
        else {
            if( DataHandler().addNewStudent(ui->ids->currentIndex() + 1, name, father_name, address, department_id, year,semester, password)) {
                close();
            }
            else  QMessageBox::information(this,"","Student already exists");
        }
    }
}

void Student_Registration::on_cancel_clicked()
{
    exit(1);
}
