#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
class Teacher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> studentList READ studentList WRITE setStudentList NOTIFY studentListChanged)
public: 
    Teacher();
    void setTeacherName(QString name);
    void setTeacherPassword(QString pass);
    void setTeacherId(int id);
    void getStudentsFromDataBase();
    void setStudentList1(QVector<QObject*> studentList);

    int getIdTeacher();
    QString getTeacherName();
    QString getTeacherPass();
    QList<QObject*> studentList() const;

    Q_INVOKABLE void createNewStudent(QString index, QString name, QString date, QString graduate);

public slots:
    void setStudentList(QList<QObject*> studentList);

signals:
    void studentListChanged(QList<QObject*> studentList);

private:
    QString _name;
    int _id;
    QString _password;
    QVector<QObject*> _studentList;
};

#endif // TEACHER_H
