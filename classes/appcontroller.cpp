#include "appcontroller.h"
#include <QRandomGenerator>

AppController::AppController()
{
    _appScreenId = 0;
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

Teacher *AppController::getCurTeacher()
{
    return _teacher;
}

void AppController::checkLogin(QString name, QString password)
{
    _teacher = new Teacher();
    _teacher->setTeacherName(name);
    _teacher->setTeacherPassword(password);
    int teacherId = ConnectSQL::getInstance()->checkAccount(name, password);
    if(teacherId != -1){
        _teacher->setTeacherId(teacherId);
        setMessBox("Login Sucessfully");
        setAppScreenId(1);
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
    if(ConnectSQL::getInstance()->insertNewTeacher(newId, accout, password))
    {
        setMessBox("Create new account sucessfully");
    }else{
        setMessBox("Enter account again");
    }
}
