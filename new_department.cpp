#include "new_department.h"
#include "ui_new_department.h"

new_department::new_department(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_department)
{
    ui->setupUi(this);
}

new_department::~new_department()
{
    delete ui;
}

void new_department::on_buttonBox_accepted()
{

}
