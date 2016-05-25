#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QFile>
#include <BusinessLogic/student.h>
#include <BusinessLogic/course.h>
#include <BusinessLogic/department.h>
#include <BusinessLogic/authorization.h>
#include <QTextStream>
#include <QMap>
#include <QDialog>
#include <QStringListModel>

#define HOME_DIR "/mnt/sda7/workshop/qt Projects/UniversityManagement/Data/"

class DataHandler
{

public:

    int type;

    QString student_fileName;
    QString dept_fileName;
    QString courses_fileName;
    QString programme_fileName;
    QString generalInfo_fileName;

    static QStringListModel departments_list_model;
    static QStringListModel students_list_model;
    static QStringListModel courses_list_model;
    static QStringListModel teachers_list_model;

    static QFile *studentFile;
    static QFile *deptFile;
    static QFile *coursesFile;
    static QFile *programmeFile;
    static QFile *generalFile;

    static QStringList dept_list;
    static QStringList student_list;
    static QStringList teacher_list;
    static QStringList course_list;


//    QMap < QString , Student *> students;
//    QMap <QString , Course*> courses;
    static QMap <QString , Department> departments;
    static QMap <QString , Student> students;
//    static QMap <QString , Department> courses;
//    static QMap <QString , Department> teachers;

//    static QMap <QString , QString> passwords;

    DataHandler(int i=0);
    ~DataHandler();

    static DataHandler data;

//    QDataStream &operator >> (QDataStream &in , Department &dept);
    void loadData();
    void saveData();

    bool addNewStudent(int int_id ,QString name, QString father_name , QString address , int dept_id, int year,int semester, QString password);
};

#endif // DATAHANDLER_H
