#include "mouse_event.h"
#include "screenshot.h"

#include "mainwindow.h"
#include <QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QQmlContext>
#include <QQuickWindow>
#include <QQuickView>
#include <QUrl>

Q_DECLARE_METATYPE(QSystemTrayIcon::ActivationReason)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<QSystemTrayIcon>("QSystemTrayIcon", 1, 0, "QSystemTrayIcon");
    qRegisterMetaType<QSystemTrayIcon::ActivationReason>("ActivationReason");
    engine.rootContext()->setContextProperty("iconTray", QIcon(":/icons/time-left.png"));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MainWindow w;
    QIcon icon("./Apps-Qt-icon.png");
    w.setWindowIcon(icon);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setStyleSheet("MainWindow#w {background-color: #37474f} ");
    engine.rootContext()->setContextProperty("mainWindow", &w);

    CMouseEvent mouse_event;

    QObject::connect(&w, SIGNAL(start_mouse_event()), &mouse_event, SLOT(start()), Qt::DirectConnection);
    QObject::connect(&w, SIGNAL( stop_mouse_event()), &mouse_event, SLOT( stop()), Qt::DirectConnection);

    return app.exec();
}

void login() {}
