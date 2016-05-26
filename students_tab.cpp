#include "students_tab.h"
#include "ui_students_tab.h"
#include <QSqlTableModel>
#include "datahandler.h"

students_tab::students_tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::students_tab)
{
    ui->setupUi(this);
//    ui->tableWidget->
    QSqlTableModel *model;

    model = new QSqlTableModel(this);
    model->setTable(DataHandler().student_column);
    model->select();

    ui->tableView->setModel(model);
}

students_tab::~students_tab()
{
    delete ui;
}
