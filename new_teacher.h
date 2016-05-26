#ifndef NEW_TEACHER_H
#define NEW_TEACHER_H

#include <QDialog>
#include <QString>
#include "datahandler.h"
#include <QMessageBox>

namespace Ui {
class new_teacher;
}

class new_teacher : public QDialog
{
    Q_OBJECT
    QString name;
    QString designtaion;
    int dept_id;
    int salary;


public:
    explicit new_teacher(QWidget *parent = 0);
    ~new_teacher();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::new_teacher *ui;
};

#endif // NEW_TEACHER_H
