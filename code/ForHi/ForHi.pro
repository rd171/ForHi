#-------------------------------------------------
#
# Project created by QtCreator 2021-02-13T19:22:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ForHi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L$$PWD/../../app/bin/debug/ -lGUI

INCLUDEPATH += $$PWD/../../app/bin/debug
DEPENDPATH += $$PWD/../../app/bin/debug

CONFIG(debug, debug|release){
    DESTDIR =  $$PWD/../../app/bin/debug
}else{
    DESTDIR =  $$PWD/../../app/bin/release
}




