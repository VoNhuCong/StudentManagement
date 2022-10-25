#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "classes/connectsql.h"
#include "classes/appcontroller.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    ConnectSQL* mydb = ConnectSQL::getInstance();
    QGuiApplication app(argc, argv);
    AppController appControl;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("AppControl", &appControl);
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
