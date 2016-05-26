#include "new_course.h"
#include "ui_new_course.h"
#include <QDebug>

new_course::new_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_course)
{
    ui->setupUi(this);

    QStringListModel *semesters;
    QStringListModel *ids;

    semesters = new QStringListModel();
    ids = new QStringListModel();

    QStringList semList;
    QStringList idList;

    for(int i=1; i<9;i++){
        QString s = QString::number(i);
        semList << s;
    }

    for(int i=1; i<99;i++){
        QString s = QString::number(i);
        idList << s;
    }

    semesters->setStringList(semList);
    ids->setStringList(idList);

    ui->semester->setModel(semesters);
    ui->id->setModel(ids);
    ui->dept->setModel(&DataHandler().departments_list_model);

    dept_accr = new QString[DataHandler().departments.size()];


    for(int i=0; i < DataHandler().departments.size() - 1; i++){
        QString name = DataHandler().departments[i].getName();
        QString accr;

        for(int j=0; j<name.size(); j++)
            if(name[j].isUpper()) accr.append(name[j]);
        qDebug() << accr;
        dept_accr[i] = accr;
    }
}

new_course::~new_course()
{
    delete ui;
}

//void new_course::on_buttonBox_accepted()
//{

//    }
//}







void new_course::on_pushButton_2_clicked()
{
    name = ui->name->text();
    dept_id = ui->dept->currentIndex() + 1;
    semester = ui->semester->currentText().toInt();
    credit = ui->credit->text().toDouble();
    int idNo = ui->id->currentIndex() + 1;

    if(name == "" || dept_id == 0 || semester == 0 || credit == 0.0) QMessageBox::critical(0,"", "All values are not set");
    else {
        QString id = dept_accr[dept_id];
        id.append("4").append(QString::number(semester));
        if(idNo < 10) id.append("0").append(QString::number(idNo));
        else id.append(QString::number(idNo));

        DataHandler().addNewCourse(id,name,dept_id,semester,credit);
        close();
    }
}

void new_course::on_pushButton_clicked()
{
    close();
}
