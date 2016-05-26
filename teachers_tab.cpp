#include "teachers_tab.h"
#include "ui_teachers_tab.h"

teachers_tab::teachers_tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teachers_tab)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable(DataHandler().teachers_table);
    model->select();

    ui->tableView->setModel(model);

}

teachers_tab::~teachers_tab()
{
    delete ui;
}

void teachers_tab::on_pushButton_clicked()
{
    new_teacher teacher;
    teacher.exec();

    model->select();
    ui->tableView->setModel(model);
}
