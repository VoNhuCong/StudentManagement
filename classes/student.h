#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

public:
    void setStudentName(QString name);
    void setDate(QString date);
    void setGraduate(QString granduate);
    void setStudentId(int studentId);
    QString getStudentName();
    QString getDate();
    QString getGraduate();
    int getStudentId();


signals:

private:
    int _studentId;
    QString _studentName;
    QString _date;
    QString _graduate;

};

#endif // STUDENT_H
