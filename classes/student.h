#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>
#include <QDate>

class Student : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString studentName READ studentName WRITE setStudentName NOTIFY studentNameChanged)
public:
    //explicit Student(QObject *parent = nullptr);
    Student();
    Student(int index, QString name, QDate date, QString graduate);

public:
    void setNameStudent(QString name);
    void setDate(QDate date);
    void setGraduate(QString granduate);
    void setStudentId(int studentId);
    void setTeacherId(int teacherid);    QString getStudentName();
    QDate getDate();
    QString getGraduate();
    int getStudentId();
    Q_INVOKABLE QString studentName() const;

public slots:
    void setStudentName(const QString& studentName);

signals:
    void studentNameChanged(QString studentName);
private:
    int _studentId;
    QString _studentName;
    QString _graduate;
    QDate _date;
    int _teacherId;

};

#endif // STUDENT_H
