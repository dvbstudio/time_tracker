#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouse_event.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    allTime(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Screen grab");

    ui->pauseBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);

    QGraphicsDropShadowEffect *t1 = new QGraphicsDropShadowEffect(this);
    t1->setBlurRadius(20);
    ui->startBtn->setGraphicsEffect( t1 );

    QGraphicsDropShadowEffect *t2 = new QGraphicsDropShadowEffect(this);
    t2->setBlurRadius(20);
    ui->pauseBtn->setGraphicsEffect( t2 );

    QGraphicsDropShadowEffect *t3 = new QGraphicsDropShadowEffect(this);
    t3->setBlurRadius(20);
    ui->stopBtn->setGraphicsEffect ( t3 );

    QGraphicsDropShadowEffect *t4 = new QGraphicsDropShadowEffect(this);
    t4->setBlurRadius(20);
    ui->exitBtn->setGraphicsEffect ( t4 );

    QGraphicsDropShadowEffect *t5 = new QGraphicsDropShadowEffect(this);
    t5->setBlurRadius(20);
    ui->lcdNumber->setGraphicsEffect ( t5 );

    ui->lcdNumber->display( "00:00:00" );

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLcdTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    emit start_mouse_event();

    this->setWindowTitle(Title + " - Start");
    ui->startBtn->setEnabled(false);
    ui->pauseBtn->setEnabled(true);
    ui->stopBtn->setEnabled(true);

    timer->start(1000);

    watch = new QTime();
    watch->start();

}

void MainWindow::on_pauseBtn_clicked()
{
    emit stop_mouse_event();

    this->setWindowTitle(Title + " - Pause");
    ui->startBtn->setEnabled(true);
    ui->pauseBtn->setEnabled(false);

    timer->stop();
    allTime += watch->elapsed();
    delete watch;


}

void MainWindow::on_stopBtn_clicked()
{
    if ( ui->pauseBtn->isEnabled() )
        emit stop_mouse_event();

    this->setWindowTitle(Title + " - Stop");
    ui->startBtn->setEnabled(true);
    ui->pauseBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);

    timer->stop();
    allTime = 0;
    delete watch;
}

void MainWindow::on_exitBtn_clicked()
{
    if ( ui->stopBtn->isEnabled() )
        on_stopBtn_clicked();

    exit(0);
}

void MainWindow::updateLcdTime()
{
    if ( timer->isActive() )
        ui->lcdNumber->display( QTime::fromMSecsSinceStartOfDay( allTime + watch->elapsed() ).toString("hh:mm:ss") );
}

void MainWindow::showFromQml()
{
    this->show();
}

void MainWindow::hideOrShow()
{;
    this->isVisible() ? this->hide() : this->show();
}
