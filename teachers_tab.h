#ifndef TEACHERS_TAB_H
#define TEACHERS_TAB_H

#include <QWidget>
#include <QSqlTableModel>
#include "datahandler.h"
#include "new_teacher.h"

namespace Ui {
class teachers_tab;
}

class teachers_tab : public QWidget
{
    Q_OBJECT

    QSqlTableModel *model;

public:
    explicit teachers_tab(QWidget *parent = 0);
    ~teachers_tab();

private slots:
    void on_pushButton_clicked();

private:
    Ui::teachers_tab *ui;
};

#endif // TEACHERS_TAB_H
