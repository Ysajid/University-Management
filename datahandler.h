#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QFile>
#include <BusinessLogic/student.h>
#include <BusinessLogic/course.h>
#include <BusinessLogic/department.h>
#include <BusinessLogic/teacher.h>
#include <BusinessLogic/authorization.h>
#include <QTextStream>
#include <QMap>
#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QtSql>
#include <QMessageBox>

#define HOME_DIR "/mnt/sda7/workshop/qt Projects/UniversityManagement/Data/"
#define DB_NAME "university.db"

class DataHandler
{

    QSqlDatabase db;

public:

    int type;

    QString students_table;
    QString dept_table;
    QString courses_table;
    QString teachers_table;
    QString password_table;
    QString programme_fileName;
    QString generalInfo_fileName;

    static QStringListModel departments_list_model;
    static QStringListModel students_list_model;
    static QStringListModel courses_list_model;
    static QStringListModel teachers_list_model;

    static QStandardItemModel *students_model;

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
    static QMap <int , Department> departments;
    static QMap <QString , Student> students;
    static QMap <QString , Course> courses;
    static QMap <int , Teacher> teachers;
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
    void addNewDepartment(QString name, QString building, int budget);
    void addNewTeacher(QString name, QString designation, int dept_id, int salary);
    void addNewCourse(QString id, QString name, int dept_id, int semester, double credit);


};

#endif // DATAHANDLER_H
