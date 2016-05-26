#include "courses_tab.h"
#include "ui_courses_tab.h"

courses_tab::courses_tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::courses_tab)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable(DataHandler().courses_table);
    model->select();

    ui->tableView->setModel(model);
}

courses_tab::~courses_tab()
{
    delete ui;
}

void courses_tab::on_pushButton_clicked()
{
    new_course n;
    n.exec();

    model->select();
    ui->tableView->setModel(model);
}
