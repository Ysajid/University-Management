#include "new_teacher.h"
#include "ui_new_teacher.h"

new_teacher::new_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_teacher)
{
    ui->setupUi(this);

    ui->dept->setModel(&DataHandler().departments_list_model);
}

new_teacher::~new_teacher()
{
    delete ui;
}

void new_teacher::on_pushButton_2_clicked()
{
    name = ui->name->text();
    designtaion = ui->des->text();
    dept_id = ui->dept->currentIndex() + 1;
    salary = ui->salary->text().toInt();

    if(name == "" || designtaion == "" || dept_id == 0 || salary == 0) QMessageBox::critical(0,"","All Values are not ser");
    else {
        DataHandler().addNewTeacher(name, designtaion, dept_id, salary);
        close();
    }
}

void new_teacher::on_pushButton_clicked()
{
    close();
}
