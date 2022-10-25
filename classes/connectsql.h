#ifndef CONNECTSQL_H
#define CONNECTSQL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>

class ConnectSQL
{
public:
    ConnectSQL();
    void initTable();
    void insertNewStudent(int studentId, QString name, QString date, QString graduate);
    bool insertNewTeacher(int id, QString name, QString pass);
    void deleteStudent(int studentId);
    void genData();
    int checkAccount(QString name, QString password);
    static ConnectSQL *getInstance();


private:
    QSqlDatabase _myDb;
    static ConnectSQL* _connectSql;
};


#endif // CONNECTSQL_H
