#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
class Teacher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> studentList READ studentList WRITE setStudentList NOTIFY studentListChanged)
    Q_PROPERTY(QString messPopup READ messPopup WRITE setMessPopup NOTIFY messPopupChanged)
public: 
    Teacher();
    ~Teacher();
    void setTeacherName(QString name);
    void setTeacherPassword(QString pass);
    void setTeacherId(int id);
    void getStudentsFromDataBase();
    void setStudentList1(QVector<QObject*> studentList);
    void deleteAllStudent();
    bool isValidForNewStudent(QString studentId);
    bool isValidGraduate(QString graduate);
    bool isValidDateInput(QString date);

    int getIdTeacher();
    QString getTeacherName();
    QString getTeacherPass();
    QList<QObject*> studentList() const;
    QString messCreateStudentBox() const;
    QString messPopup() const;

    Q_INVOKABLE void createNewStudent(QString index, QString name, QString date, QString graduate);
    Q_INVOKABLE void deleteStudentByPos(int pos);
    Q_INVOKABLE void deleteAllStudents();
public slots:
    void setStudentList(QList<QObject*> studentList);
    void setMessPopup(QString mess);

signals:
    void studentListChanged(QList<QObject*> studentList);
    void messPopupChanged(QString messPopup);

private:
    QString _name;
    int _id;
    QString _password;
    QString _messagePopup;
    QVector<QObject*> _studentList;
};

#endif // TEACHER_H
