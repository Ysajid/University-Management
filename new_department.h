#ifndef NEW_DEPARTMENT_H
#define NEW_DEPARTMENT_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include "datahandler.h"

namespace Ui {
class new_department;
}

class new_department : public QDialog
{
    Q_OBJECT

    int id;
    QString name;
    QString building;
    int budget;

public:
    explicit new_department(QWidget *parent = 0);
    ~new_department();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::new_department *ui;
};

#endif // NEW_DEPARTMENT_H
