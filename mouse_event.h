#ifndef MOUSE_EVENT
#define MOUSE_EVENT

#include <QDateTime>
#include <QTimer>
#include <QDesktopWidget>
#include <QObject>
#include <QThread>
#include <QList>
#include <QDebug>

#include <windows.h>
#include <stdio.h>

#include "screenshot.h"
#include "worker.h"

class CMouseEvent: public QObject
{
    Q_OBJECT
public:
    CMouseEvent(QObject *parent = Q_NULLPTR): QObject(parent)
    {
        connect(&event_timer, SIGNAL(timeout()), this, SLOT(event()));

        screen = new CScreenshot();
    }
    virtual ~CMouseEvent(){ delete screen; }

    void saveMouseEvent();
    void saveToBinFile(short ch);
    void saveToCsvFile(QString date, short x, short y);

private:
    CScreenshot *screen;
    QTimer event_timer;
    POINT cp;
    int interval_event  = 20;
    int interval_screen = 20;

    void makeScreen();

private slots:
    void event();
    void start(){ event_timer.start( interval_event ); }
    void stop() { event_timer.stop(); }

private:

    class myThread: public QThread{
    public:
        virtual ~myThread(){ qDebug() << "~myThread "; }
    };
};


#endif // MOUSE_EVENT
