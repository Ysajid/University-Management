#include "newdepartment.h"
#include "ui_newdepartment.h"

newDepartment::newDepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDepartment)
{
    ui->setupUi(this);
}

newDepartment::~newDepartment()
{
    delete ui;
}

void newDepartment::on_buttonBox_accepted()
{

}
