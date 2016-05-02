#ifndef NEWDEPARTMENT_H
#define NEWDEPARTMENT_H

#include <QDialog>

namespace Ui {
class newDepartment;
}

class newDepartment : public QDialog
{
    Q_OBJECT

public:
    explicit newDepartment(QWidget *parent = 0);
    ~newDepartment();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newDepartment *ui;
};

#endif // NEWDEPARTMENT_H
