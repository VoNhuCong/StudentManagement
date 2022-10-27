#include "teacher.h"
#include "student.h"
#include "connectsql.h"
#include <iostream>
#include <string>

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

void Teacher::getStudentsFromDataBase()
{

}

void Teacher::setStudentList1(QVector<QObject *> studentList)
{
    _studentList = studentList;
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

QList<QObject *> Teacher::studentList() const
{
    return _studentList;
}

void Teacher::createNewStudent(QString index, QString name, QString date, QString graduate)
{
    // need check date format
    // check index (int)
    // check graduate
    QDate dateStudent = QDate::fromString(date,"dd/MM/yyyy");
    qDebug() << __FUNCTION__ << "date: " << dateStudent.toString();
    Student* newStudent = new Student(index.toInt(), name, dateStudent, graduate);
    _studentList.push_back(newStudent);
    DATABASEMANAGER->insertNewStudent(index.toInt(), name, date, graduate, _id);
    qDebug() << __FUNCTION__ << "index: " << index << "name: " << name << "date: " << date << "graduate: " << graduate;
}

void Teacher::setStudentList(QList<QObject *> studentList)
{

}

