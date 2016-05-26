#ifndef NEW_COURSE_H
#define NEW_COURSE_H

#include <QDialog>
#include <QStringListModel>
#include <QList>
#include "datahandler.h"
#include <QString>
#include <QMessageBox>

namespace Ui {
class new_course;
}

class new_course : public QDialog
{
    Q_OBJECT

    QString name;
    int dept_id;
    int semester;
    QString *dept_accr;
    double credit;

public:
    explicit new_course(QWidget *parent = 0);
    ~new_course();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::new_course *ui;
};

#endif // NEW_COURSE_H
