#include "teacher.h"
#include "student.h"
#include "databasemanager.h"
#include <iostream>
#include <string>

Teacher::Teacher()
{

}

Teacher::~Teacher()
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

void Teacher::deleteAllStudent()
{
    for(auto student : _studentList){
        if(student){
            delete student;
        }
    }
    _studentList.clear();
}

bool Teacher::isValidForNewStudent(QString studentId)
{
    if(studentId == ""){
        setMessPopup("Enter Id!");
        return false;
    }
    if(studentId.toInt() == 0){
        setMessPopup("Invalid Id! \nId is interger number");
        return false;
    }
    if(DATABASEMANAGER->isExistStudentId(studentId)){
        setMessPopup("This id already exists!");
        return false;
    }
    return true;
}

bool Teacher::isValidGraduate(QString graduate)
{
    if(graduate == "") {
        setMessPopup("Enter graduate!");
        return false;
    }
    if(graduate != "No" && graduate != "Yes"){
        setMessPopup("Enter graduate follow\nas: Yes/No");
        return false;
    }
    else return true;
}

bool Teacher::isValidDateInput(QString date)
{
    QDate dateStudent = QDate::fromString(date,"dd/MM/yyyy");
    if(date == ""){
        setMessPopup("Enter date!");
        return false;
    }
    if(dateStudent.isValid()){
        return true;
    }else{
        setMessPopup("Enter date follow: \ndd/mm/yyyy");
        return false;
    }
}

bool Teacher::isValidNameInput(QString name)
{
    if(name == ""){
        setMessPopup("Enter name!");
        return false;
    }
    return true;
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

QString Teacher::messCreateStudentBox() const
{
    return _messagePopup;
}

QString Teacher::messPopup() const
{
    return _messagePopup;
}

void Teacher::onCreateNewStudent(QString index, QString name, QString date, QString graduate)
{
    if(!isValidForNewStudent(index))return;

    if(!isValidNameInput(name)) return;

    if(!isValidDateInput(date)) return;

    if(!isValidGraduate(graduate)) return;

    QDate dateStudent = QDate::fromString(date,"dd/MM/yyyy");

    Student* newStudent = new Student(index.toInt(), name, dateStudent, graduate);
    _studentList.push_back(newStudent);
    emit studentListChanged(_studentList);

    DATABASEMANAGER->insertNewStudent(index.toInt(), name, date, graduate, _id);

    setMessPopup("Create new student\nsuccesfully");
}

void Teacher::onDeleteStudentByPos(int pos)
{
    if(pos > _studentList.size()) return;
    int studentId =  static_cast<Student*>(_studentList[pos])->getStudentId();
    qDebug() << __FUNCTION__ << "delete student id =" << studentId;
    _studentList.remove(pos);
    emit studentListChanged(_studentList);
    DATABASEMANAGER->deleteStudent(studentId);
}

void Teacher::onDeleteAllStudents()
{
    for(int i = 0; i < _studentList.size(); i++){
        Student* student = static_cast<Student*>(_studentList[i]);
        DATABASEMANAGER->deleteStudent(student->getStudentId());
    }
    _studentList.clear();
    setStudentList(_studentList);
}

void Teacher::onCancelCreateNewStudent()
{
    setMessPopup("");
}

void Teacher::setStudentList(QList<QObject *> studentList)
{
    _studentList = studentList;
    emit studentListChanged(_studentList);
}

void Teacher::setMessPopup(QString mess)
{
    _messagePopup = mess;
    emit messPopupChanged(mess);
}

