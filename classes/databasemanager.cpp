#include "databasemanager.h"
#include <QDebug>
#include "student.h"


DatabaseManager* DatabaseManager::_connectSql = NULL;

DatabaseManager::DatabaseManager()
{
    _myDb = QSqlDatabase::addDatabase("QSQLITE");
    _myDb.setDatabaseName(QDir::currentPath()+"/myDb.db");
    qDebug() << __FUNCTION__ << "database path: " << QDir::currentPath()+"/myDb.db";
    initTable();
}

void DatabaseManager::initTable()
{
    if (!_myDb.open()) {
        return;
    }
    QSqlQuery query;
    query.exec("create table students (id primary key, "
               "name varchar(50), date date, graduate varchar(20), teacherId varchar(20))");
    query.exec("create table teachers (id primary key, "
               "name varchar(50), pass varchar(50))");
}

void DatabaseManager::insertNewStudent(int studentId, QString name, QString date, QString graduate, int teacherId)
{
    if (!_myDb.open()) {
        return;
    }
    QSqlQuery query;
    QString newStudent = QString("insert into students values(%1, '%2', '%3', '%4', '%5')").arg(studentId).arg(name).arg(date).arg(graduate).arg(teacherId);
    query.exec(newStudent);
    qDebug() << __FUNCTION__ << newStudent;
    qDebug() << __FUNCTION__ << "Insert new student successfully";
}

bool DatabaseManager::insertNewTeacher(int id, QString name, QString pass)
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

void DatabaseManager::deleteStudent(int studentId)
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

void DatabaseManager::genData()
{
    for(int i = 0; i < 100; i ++){
        QString name = QString("vonhucong%1").arg(i);
        insertNewStudent(i, "vonhucong", "11/11/2002", "dsdsd", 123);
    }
    for(int i = 0; i < 100; i ++){
        QString name = QString("vonhucong%1").arg(i);
        insertNewTeacher(i, name, "dsd");
    }

}

int DatabaseManager::checkAccount(QString name, QString password)
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

QVector<QObject *> DatabaseManager::getAllStudentByTeachId(int teacherId)
{
    //SELECT * FROM students WHERE teacherId = 0
    QString newQuery = QString("SELECT * FROM students WHERE teacherId = %1").arg(teacherId);
    QSqlQuery query;
    QVector<QObject *> studentList;
    try {
        query.exec(newQuery);
        while(query.next()){
            Student* student = new Student();
            student->setStudentId(query.value(0).toInt());
            student->setNameStudent(query.value(1).toString());
            QString date = query.value(2).toString();
            QDate dateStudent = QDate::fromString(date,"dd/MM/yyyy");
            student->setDate(dateStudent);
            student->setGraduate(query.value(3).toString());
            student->setTeacherId(query.value(4).toInt());
            studentList.push_back(student);
        }
        return studentList;
    }
    catch (_exception e) {
    }
}

DatabaseManager* DatabaseManager::getInstance() {
   if (_connectSql == NULL) {
      _connectSql = new DatabaseManager();
   }
   return(_connectSql);
}

