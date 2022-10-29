#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>
#include <QDate>

class Student : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString studentName READ studentName WRITE setStudentName NOTIFY studentNameChanged)
    Q_PROPERTY(QString studentDate READ studentDate WRITE setStudentDate NOTIFY studentDateChanged)
    Q_PROPERTY(QString studentId READ studentId WRITE setStudentId NOTIFY studentIdChanged)
    Q_PROPERTY(QString studentGraduate READ studentGraduate WRITE setStudentGraduate NOTIFY studentGraduateChanged)
public:
    //explicit Student(QObject *parent = nullptr);
    Student();
    ~Student();
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
    Q_INVOKABLE QString studentDate() const;
    Q_INVOKABLE QString studentId() const;
    Q_INVOKABLE QString studentGraduate() const;

public slots:
    void setStudentName(const QString& studentName);
    void setStudentDate(const QString& studentDate);
    void setStudentId(const QString& studentId);
    void setStudentGraduate(const QString& studentGraduate);

signals:
    void studentNameChanged(QString studentName);
    void studentDateChanged(QString studentDate);
    void studentIdChanged(QString studentId);
    void studentGraduateChanged(QString studentGraduate);

private:
    int _studentId;
    QString _studentName;
    QString _graduate;
    QDate _date;
    int _teacherId;

};

#endif // STUDENT_H
