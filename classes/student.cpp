#include "student.h"

//Student::Student(QObject *parent)
//    : QObject{parent}
//{
//}

Student::Student()
{

}

Student::~Student()
{

}

Student::Student(int index, QString name, QDate date, QString graduate)
{
    _studentName = name;
    _date = date;
    _graduate = graduate;
    _studentId =  index;
}

void Student::setNameStudent(QString name)
{
    _studentName = name;
}

void Student::setDate(QDate date)
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

void Student::setTeacherId(int teacherid)
{
    _teacherId = teacherid;
}

QString Student::getStudentName()
{
    return _studentName;
}

QDate Student::getDate()
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

QString Student::studentName() const
{
    return _studentName;
}

QString Student::studentDate() const
{
    return _date.toString("dd.MM.yyyy");
}

QString Student::studentId() const
{
    return QString::number(_studentId);
}

QString Student::studentGraduate() const
{
    return _graduate;
}

void Student::setStudentName(const QString &studentName)
{

}

void Student::setStudentDate(const QString &studentDate)
{

}

void Student::setStudentId(const QString &studentId)
{

}

void Student::setStudentGraduate(const QString &studentGraduate)
{

}
