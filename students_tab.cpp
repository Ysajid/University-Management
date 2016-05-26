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
//    model->setTable("select id , students.name , father_name, address , departments.name , semester , year from "
//                    +DataHandler().dept_table +"," +DataHandler().students_table
//                    +"where departments.rowid = dept_id;");

    model->setTable(DataHandler().students_table);
    model->select();

    ui->tableView->setModel(model);
}

students_tab::~students_tab()
{
    delete ui;
}
