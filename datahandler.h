#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QFile>
#include <BusinessLogic/student.h>
#include <BusinessLogic/course.h>
#include <BusinessLogic/department.h>
#include <QDataStream>
#include <QMap>
#include <QDialog>

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

//    QMap < QString , Student *> students;
//    QMap <QString , Course*> courses;
    QMap <QString , Department*> departments;

public:
    DataHandler();
    DataHandler(QMap <QString , Department*>&);

    static DataHandler data;

//    QDataStream &operator >> (QDataStream &in , Department &dept);
    void loadInfos();
    void saveInfos();
};

#endif // DATAHANDLER_H
