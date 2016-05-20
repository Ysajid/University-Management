#ifndef NEWDEPARTMENT_H
#define NEWDEPARTMENT_H

#include <QInputDialog>

namespace Ui {
class newDepartment;
}

class newDepartment : public QInputDialog
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
