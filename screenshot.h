#ifndef CSCREENSHOT
#define CSCREENSHOT

#include <QWindow>
#include <QWidget>
#include <QImageWriter>
#include <QScreen>
#include <QPixmap>
#include <QGuiApplication>

class CScreenshot: public QWidget
{
    Q_OBJECT
public:
    CScreenshot(QWidget *parent = Q_NULLPTR): QWidget(parent){}

    QPixmap& getPixmap()
    {
        return originalPixmap;
    }

signals:
    void finished();


public slots:
    void shootScreen();

private:
    QPixmap originalPixmap;
};


#endif // CSCREENSHOT

