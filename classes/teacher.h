#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
public:
    Teacher();
    void setTeacherName(QString name);
    void setTeacherPassword(QString pass);
    void setTeacherId(int id);

    int getIdTeacher();
    QString getTeacherName();
    QString getTeacherPass();
private:
    QString _name;
    int _id;
    QString _password;
};

#endif // TEACHER_H
