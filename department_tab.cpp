#include "department_tab.h"
#include "ui_department_tab.h"
#include <QSqlTableModel>
#include "datahandler.h"

department_tab::department_tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::department_tab)
{
    ui->setupUi(this);
    QSqlTableModel *model;
    model = new QSqlTableModel(this);
    model->setTable(DataHandler().dept_table);
    model->select();

    ui->tableView->setModel(model);
}

department_tab::~department_tab()
{
    delete ui;
}

void department_tab::on_pushButton_clicked()
{

}
