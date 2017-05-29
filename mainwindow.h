#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QTimer>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

signals:
    void start_mouse_event();
    void  stop_mouse_event();

public slots:
    void showFromQml();
    void hideOrShow();

private slots:
    void on_startBtn_clicked();
    void on_pauseBtn_clicked();
    void on_stopBtn_clicked();
    void on_exitBtn_clicked();

    void updateLcdTime();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime  *watch;
    qint64 allTime;
    const QString Title = "Screen grab";

    QPoint position;

    void mousePressEvent(QMouseEvent *event)
    {
        position = event->pos();
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        move(event->globalPos() - position);
    }

};

#endif // MAINWINDOW_H
