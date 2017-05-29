QT += core gui qml quick

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Screen grab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shoot_screen.cpp \
    worker.cpp \
    mouse_event.cpp \

HEADERS  += mainwindow.h \
    screenshot.h \
    mouse_event.h \
    worker.h \

FORMS    += mainwindow.ui

RESOURCES += \
    login.qrc
