#include "mouse_event.h"

void CMouseEvent::event()
{
    // chech mouse button pressed
    if ( GetAsyncKeyState(VK_LBUTTON) != 0 || GetAsyncKeyState(VK_RBUTTON) != 0 )
    {
        GetCursorPos(&cp);
        makeScreen();
        saveToCsvFile(QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss.zzz"),
                      static_cast<short>(cp.x),
                      static_cast<short>(cp.y)
                      );
    }

    // get keypad button pressed
    for(short character = 8; character <= 222; character++)
    {
        if( GetAsyncKeyState(character) == -32767 )
        {
            saveToBinFile(character);
        }
    }
}

void CMouseEvent::saveToBinFile(short ch)
{
    FILE *file = fopen("FileName.csv","a+");

    fputc(ch, file);
//    fputc('\t', file);
    fputc('\n', file);

    fflush(file);
    fclose(file);
}

void CMouseEvent::saveToCsvFile(QString date, short x, short y)
{
    FILE *file = fopen("FileName.csv","a+");

    fprintf(file, "%s", date.toStdString().c_str());
    fprintf(file, "%c", ';');
    fprintf(file, "%d", x );
    fprintf(file, "%c", ';');
    fprintf(file, "%d", y );
    fprintf(file, "%c", ';');
    fprintf(file, "%c", '\n');

    fflush(file);
    fclose(file);
}

void CMouseEvent::makeScreen()
{
    CWorker *worker = new CWorker();
    QThread *thread = new QThread();

    screen->shootScreen();
    worker->setPixmap(screen->getPixmap());

    // Передаем права владения "рабочим" классом, классу QThread.
    worker->moveToThread(thread);

    // Соединяем сигнал started потока, со слотом process "рабочего" класса, т.е. начинается выполнение нужной работы.
    connect(thread, SIGNAL(started()), worker, SLOT(doWork()));

    // По завершению выходим из потока, и удаляем рабочий класс
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(thread, SIGNAL(finished()), worker, SLOT(deleteLater()));

    // Удаляем поток, после выполнения операции
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    QThread::Priority ui_priority = QThread::currentThread()->priority();

    QThread::Priority new_thread_priority;
    if (ui_priority > QThread::LowPriority)
        new_thread_priority = QThread::LowPriority;
    else
    {
        if (ui_priority > QThread::LowestPriority)
            new_thread_priority = QThread::LowestPriority;
        else
        {
            new_thread_priority = QThread::IdlePriority;
        }
    }

    thread->start();
    thread->setPriority(new_thread_priority);
}
