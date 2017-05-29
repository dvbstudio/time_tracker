#ifndef WORKER
#define WORKER

#include <QObject>
#include <QPixmap>
#include <QDebug>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>

class CWorker: public QObject{
    Q_OBJECT
public:
    explicit CWorker(QObject *parent = Q_NULLPTR):QObject(parent){}
    virtual ~CWorker(){}

    void setPixmap(QPixmap &t)
    {
        p.swap(t);
    }

signals:
    void finished();
    void error(int);

public slots:
    void doWork();

private:
    QPixmap p;
};

#endif // WORKER
