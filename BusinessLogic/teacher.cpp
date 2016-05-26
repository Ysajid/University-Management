#include "teacher.h"
#include <QSqlQuery>

Teacher::Teacher()
{

}

Teacher::Teacher(int id, QString name, QString designation, int dept_id, int salary)
{
    this->id = id;
    this->name = name;
    this->designation = designation;
    this->dept_id = dept_id;
    this->salary = salary;
}
