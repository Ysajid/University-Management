#include "department.h"

Department::Department()
{

}


Department::Department(QString id, QString name, QString building, QString budget)
{
    this->dept_id = id;
    this->dept_name = name;
    this->building = building;
    this->budget = budget;
}
