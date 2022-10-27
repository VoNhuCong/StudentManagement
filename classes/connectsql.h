#ifndef CONNECTSQL_H
#define CONNECTSQL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QVector>
#include "student.h"

#define DATABASEMANAGER ConnectSQL::getInstance()

class ConnectSQL
{
public:
    ConnectSQL();
    void initTable();
    void insertNewStudent(int studentId, QString name, QString date, QString graduate, int teacherId);
    bool insertNewTeacher(int id, QString name, QString pass);
    void deleteStudent(int studentId);
    void genData();
    int checkAccount(QString name, QString password);
    QVector<QObject*> getAllStudentByTeachId(int teacherId);
    static ConnectSQL *getInstance();


private:
    QSqlDatabase _myDb;
    static ConnectSQL* _connectSql;
};


#endif // CONNECTSQL_H
