#ifndef DEPARTMENT_TAB_H
#define DEPARTMENT_TAB_H

#include <QWidget>

namespace Ui {
class department_tab;
}

class department_tab : public QWidget
{
    Q_OBJECT

public:
    explicit department_tab(QWidget *parent = 0);
    ~department_tab();

private slots:
    void on_pushButton_clicked();

private:
    Ui::department_tab *ui;
};

#endif // DEPARTMENT_TAB_H
