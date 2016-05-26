#ifndef STUDENTDASH_H
#define STUDENTDASH_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class StudentDash;
}

class StudentDash : public QDialog
{
    Q_OBJECT
    QString id;

public:
    explicit StudentDash(QString id , QWidget *parent = 0);
    ~StudentDash();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StudentDash *ui;
};

#endif // STUDENTDASH_H
