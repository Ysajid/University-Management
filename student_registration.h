#ifndef STUDENT_REGISTRATION_H
#define STUDENT_REGISTRATION_H

#include <QDialog>
#include <QString>
#include "datahandler.h"

namespace Ui {
class Student_Registration;
}

class Student_Registration : public QDialog, DataHandler
{
    Q_OBJECT
    QString name;
    QString id;
    QString father_name;
    QString address;
    int department_id;
    int year;
    int semester;
    QString password;
    QAbstractListModel *model;

public:
    explicit Student_Registration(QWidget *parent = 0);
    ~Student_Registration();

private slots:
    void on_done_clicked();

    void on_cancel_clicked();

private:
    Ui::Student_Registration *ui;
};

#endif // STUDENT_REGISTRATION_H
