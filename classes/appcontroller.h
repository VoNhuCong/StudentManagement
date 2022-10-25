#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include "teacher.h"
#include "connectsql.h"

class AppController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int appScreenId READ appScreenId WRITE setAppScreenId NOTIFY appScreenIdChanged)
    Q_PROPERTY(QString messBox READ messBox WRITE setMessBox NOTIFY messBoxChanged)
public:
    AppController();
    Teacher* getCurTeacher();
    int appScreenId();
    void setAppScreenId(int screenId);
    void setMessBox(QString message);
    QString messBox();


    Q_INVOKABLE void checkLogin(QString name, QString password);
    Q_INVOKABLE QString checkMessBox();
    Q_INVOKABLE void checkCreateAccout(QString accout, QString password);


signals:
    void appScreenIdChanged();
    void messBoxChanged();
private:
   int _appScreenId = 0;
   Teacher* _teacher;
   QString _messBox = "Ready";
};

#endif // APPCONTROLLER_H
