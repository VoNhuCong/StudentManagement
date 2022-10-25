#include "connectsql.h"
#include <QDebug>


ConnectSQL* ConnectSQL::_connectSql = NULL;

ConnectSQL::ConnectSQL()
{
    _myDb = QSqlDatabase::addDatabase("QSQLITE");
    _myDb.setDatabaseName(QDir::currentPath()+"/myDb.db");
    qDebug() << __FUNCTION__ << "database path: " << QDir::currentPath()+"/myDb.db";
    initTable();
}

void ConnectSQL::initTable()
{
    if (!_myDb.open()) {
        return;
    }
    QSqlQuery query;
    query.exec("create table students (id primary key, "
               "name varchar(50), date varchar(50), graduate varchar(20))");
    query.exec("create table teachers (id primary key, "
               "name varchar(50), pass varchar(50))");
}

void ConnectSQL::insertNewStudent(int studentId, QString name, QString date, QString graduate)
{
    if (!_myDb.open()) {
        return;
    }
    QSqlQuery query;
    QString newStudent = QString("insert into students values(%1, '%2', '%3', '%4')").arg(studentId).arg(name).arg(date).arg(graduate);
    query.exec(newStudent);
    qDebug() << __FUNCTION__ << newStudent;
    qDebug() << __FUNCTION__ << "Insert new student successfully";
}

bool ConnectSQL::insertNewTeacher(int id, QString name, QString pass)
{
    if (!_myDb.open()) {
        return false;
    }
    QSqlQuery query;
    QString newTeacher = QString("insert into teachers values(%1, '%2', '%3')").arg(id).arg(name).arg(pass);

    if(query.exec(newTeacher)){
       qDebug() << __FUNCTION__ << newTeacher;
       qDebug() << __FUNCTION__ << "Insert new teacher successfully";
       return true;
    }
    else{
        return false;
    }
}

void ConnectSQL::deleteStudent(int studentId)
{
    QString newQuery = QString("delete from students where id = %1").arg(studentId);
    QSqlQuery query;
    try {
        query.exec(newQuery);
    }
    catch (_exception e) {
        qDebug() << __FUNCTION__ << "delete student error";
    }
}

void ConnectSQL::genData()
{
    for(int i = 0; i < 100; i ++){
        QString name = QString("vonhucong%1").arg(i);
        insertNewStudent(i, "vonhucong", "dsd", "dsdsd");
    }
    for(int i = 0; i < 100; i ++){
        QString name = QString("vonhucong%1").arg(i);
        insertNewTeacher(i, name, "dsd");
    }

}

int ConnectSQL::checkAccount(QString name, QString password)
{
    if (!_myDb.open()) {
        return -1;
    }
    QString newQuery = QString("SELECT id FROM teachers WHERE name = '%1' and pass = '%2'").arg(name).arg(password);
    QSqlQuery query;

    try {
        query.exec(newQuery);
        while(query.next()){
            int id = query.value(0).toInt();
            qDebug() << __FUNCTION__ << "teacher id: " << id;
            return id;
        }
        return -1;
    }
    catch (_exception e) {
       return -1;
    }
}

ConnectSQL* ConnectSQL::getInstance() {
   if (_connectSql == NULL) {
      _connectSql = new ConnectSQL();
   }
   return(_connectSql);
}

