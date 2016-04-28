#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QFile>
#include <BusinessLogic/student.h>
#include <BusinessLogic/course.h>
#include <BusinessLogic/department.h>
#include <QDataStream>

class DataHandler
{
    QString student_fileName;
    QString dept_fileName;
    QString courses_fileName;
    QString programme_fileName;
    QString generalInfo_fileName;

    QFile *studentFile;
    QFile *deptFile;
    QFile *coursesFile;
    QFile *programmeFile;
    QFile *generalFile;

    QMap <int , *Student> students;
    QMap <int , *Course> courses;
    QMap <int , *Department> departments;

public:
    DataHandler();
    DataHandler(QMap <int, *Student>&, QMap <int, *Course>&, QMap <int , *Department>&);
    void loadInfos();
    void saveInfos();
};

#endif // DATAHANDLER_H
