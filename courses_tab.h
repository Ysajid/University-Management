#ifndef COURSES_TAB_H
#define COURSES_TAB_H

#include <QWidget>
#include <QSqlTableModel>
#include "datahandler.h"
#include "new_course.h"

namespace Ui {
class courses_tab;
}

class courses_tab : public QWidget
{
    Q_OBJECT

    QSqlTableModel *model;

public:
    explicit courses_tab(QWidget *parent = 0);
    ~courses_tab();

private slots:
    void on_pushButton_clicked();

private:
    Ui::courses_tab *ui;
};

#endif // COURSES_TAB_H
