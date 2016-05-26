#ifndef STUDENTDASHBOARD_H
#define STUDENTDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class StudentDashboard;
}

class StudentDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentDashboard(QWidget *parent = 0);
    ~StudentDashboard();

private:
    Ui::StudentDashboard *ui;
};

#endif // STUDENTDASHBOARD_H
