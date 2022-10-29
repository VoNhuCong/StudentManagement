#include "appcontroller.h"
#include <QRandomGenerator>
#include "classes/connectsql.h"

AppController::AppController()
{
    _appScreenId = 0;
    _teacher = new Teacher();
}

int AppController::appScreenId()
{
    return _appScreenId;
}

void AppController::setAppScreenId(int screenId)
{
    _appScreenId =  screenId;
    emit appScreenIdChanged();
}

void AppController::setMessBox(QString message)
{
    _messBox = message;
    emit messBoxChanged();
}

QString AppController::messBox()
{
    return _messBox;
}

Teacher* AppController::getCurTeacher()
{
    return _teacher;
}

void AppController::checkLogin(QString name, QString password)
{
    _teacher->setTeacherName(name);
    _teacher->setTeacherPassword(password);
    int teacherId = DATABASEMANAGER->checkAccount(name, password);
    if(teacherId != -1){
        _teacher->setTeacherId(teacherId);
        setMessBox("Login Sucessfully");
        _teacher->setStudentList(DATABASEMANAGER->getAllStudentByTeachId(teacherId));
        emit _teacher->studentListChanged(_teacher->studentList());
        setAppScreenId(1);       
        // add student list to layout
    }else{
        setMessBox("Login Failed");
    }
}

QString AppController::checkMessBox()
{
    return _messBox;
}

void AppController::checkCreateAccout(QString accout, QString password)
{
    int newId = QRandomGenerator::global()->bounded(10000, 99999);
    if(DATABASEMANAGER->insertNewTeacher(newId, accout, password))
    {
        setMessBox("Create new account sucessfully");
    }else{
        setMessBox("Enter account again");
    }
}
