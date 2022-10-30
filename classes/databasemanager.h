#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QVector>

#define DATABASEMANAGER DatabaseManager::getInstance()

class DatabaseManager
{
public:
    DatabaseManager();
    void initTable();
    void insertNewStudent(int studentId, QString name, QString date, QString graduate, int teacherId);
    bool insertNewTeacher(int id, QString name, QString pass);
    bool isExistStudentId(QString id);
    void deleteStudent(int studentId);
    int checkAccount(QString name, QString password);
    QVector<QObject*> getAllStudentByTeachId(int teacherId);
    static DatabaseManager *getInstance();


private:
    QSqlDatabase _myDb;
    static DatabaseManager* _connectSql;
};


#endif // DATABASEMANAGER_H
