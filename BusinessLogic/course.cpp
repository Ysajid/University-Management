#include "course.h"

Course::Course()
{

}

Course::Course(QString id, QString name, int dept_id, int semester, double credit)
{
    this->id = id;
    this->name = name;
    this->dept_id = dept_id;
    this->semester = semester;
    this->credit = credit;
}
