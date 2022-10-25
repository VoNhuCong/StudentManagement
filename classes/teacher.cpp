#include "teacher.h"

Teacher::Teacher()
{

}

void Teacher::setTeacherName(QString name)
{
    _name = name;
}

void Teacher::setTeacherPassword(QString pass)
{
    _password = pass;
}

void Teacher::setTeacherId(int id)
{
    _id = id;
}

int Teacher::getIdTeacher()
{
    return _id;
}

QString Teacher::getTeacherName()
{
    return _name;
}

QString Teacher::getTeacherPass()
{
    return _password;
}

