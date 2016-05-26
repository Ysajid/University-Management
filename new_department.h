#ifndef NEW_DEPARTMENT_H
#define NEW_DEPARTMENT_H

#include <QDialog>

namespace Ui {
class new_department;
}

class new_department : public QDialog
{
    Q_OBJECT

public:
    explicit new_department(QWidget *parent = 0);
    ~new_department();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::new_department *ui;
};

#endif // NEW_DEPARTMENT_H
