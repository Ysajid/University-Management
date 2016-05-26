#ifndef STUDENTS_TAB_H
#define STUDENTS_TAB_H

#include <QWidget>
#include <QTableView>

namespace Ui {
class students_tab;
}

class students_tab : public QWidget
{
    Q_OBJECT

public:
    explicit students_tab(QWidget *parent = 0);
    ~students_tab();

private:
    Ui::students_tab *ui;
};

#endif // STUDENTS_TAB_H
