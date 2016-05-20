#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QFile>
#include <BusinessLogic/student.h>
#include <BusinessLogic/course.h>
#include <BusinessLogic/department.h>
#include <QTextStream>
#include <QMap>
#include <QDialog>
#include <QStringListModel>

class DataHandler
{

public:

    QString student_fileName;
    QString dept_fileName;
    QString courses_fileName;
    QString programme_fileName;
    QString generalInfo_fileName;

    static QStringListModel *departments;

    static QFile *studentFile;
    static QFile *deptFile;
    static QFile *coursesFile;
    static QFile *programmeFile;
    static QFile *generalFile;

    QStringList *dept_list;

//    QMap < QString , Student *> students;
//    QMap <QString , Course*> courses;
    static QMap <QString , Department*> departments_map;

    DataHandler();

    static DataHandler data;

//    QDataStream &operator >> (QDataStream &in , Department &dept);
    void loadInfos();
    void saveInfos();
};

#endif // DATAHANDLER_H
