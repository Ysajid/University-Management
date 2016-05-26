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

//void new_department::on_buttonBox_accepted()
//{

//}

void new_department::on_pushButton_2_clicked()
{
    name = ui->name->text();
    building = ui->building->text();
    budget = ui->budget->text().toInt();

    if(name == "" || building == "" || budget == 0) QMessageBox::critical(this,"","All value not set");
    else {
        DataHandler().addNewDepartment(name,building, budget);
        close();
    }
}

void new_department::on_pushButton_clicked()
{
    close();
}
