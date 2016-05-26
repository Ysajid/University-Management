#include "studentdash.h"
#include "ui_studentdash.h"
#include <QDebug>

StudentDash::StudentDash(QString id , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDash)
{
    ui->setupUi(this);
    this->id = id;

    QSqlQuery query, query2;
    query = QSqlQuery("select * from students where id = "+id + ";");
    query.next();

    query2 = QSqlQuery("select name from departments where id = "+query.value(5).toString() +";");
    qDebug() << "select name from departments where id = "+query.value(5).toString() +";";
    query2.next();

    ui->details->setText(
                query.value(1).toString() + "\n\n"
                +"Id : "+query.value(0).toString() + "\n\n"
                +"Father's Name : " +query.value(2).toString() + "\n\n"
                +"Address : "+ query.value(3).toString() + "\n\n"
                +"Department : "+ query2.value(0).toString() + "\n\n"
                +"Semester : " + query.value(6).toString() + "\n\n"
                +"Admission Year : " + query.value(7).toString());

    QSqlQuery query3;
    query3.exec("drop table temp;");

    query3.exec("create table temp as select courses.id , courses.name from takes "
               "natural join courses where id = course_id and "
                "student_id = " +id +";");

    QSqlTableModel *model;
    model = new QSqlTableModel(this);
    model->setTable("temp");
    model->select();

    ui->courses->setModel(model);
}

StudentDash::~StudentDash()
{
    delete ui;
}

void StudentDash::on_pushButton_clicked()
{
    //programme closes
    close();
}
