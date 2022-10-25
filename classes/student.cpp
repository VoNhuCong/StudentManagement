#include "student.h"

Student::Student(QObject *parent)
    : QObject{parent}
{

}

void Student::setStudentName(QString name)
{
    _studentName = name;
}

void Student::setDate(QString date)
{
    _date = date;
}

void Student::setGraduate(QString granduate)
{
    _graduate = granduate;
}

void Student::setStudentId(int studentId)
{
    _studentId = studentId;
}

QString Student::getStudentName()
{
    return _studentName;
}

QString Student::getDate()
{
    return _date;
}

QString Student::getGraduate()
{
    return _graduate;
}

int Student::getStudentId()
{
    return _studentId;
}
