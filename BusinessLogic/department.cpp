#include "department.h"

Department::Department()
{

}


Department::Department(int id, QString name, QString building, int budget)
{
    this->dept_id = id;
    this->dept_name = name;
    this->building = building;
    this->budget = budget;
}

