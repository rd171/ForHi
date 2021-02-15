#-------------------------------------------------
#
# Project created by QtCreator 2021-02-13T19:23:24
#
#-------------------------------------------------

QT       += widgets declarative qml quick network opengl sql script scripttools svg webkit webkitwidgets xml xmlpatterns multimedia  testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib


SOURCES += gui.cpp \
    qimagectrl.cpp \
    qresmanager.cpp

HEADERS += gui.h\
        gui_global.h \
    qimagectrl.h \
    qresmanager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG(debug, debug|release){
    DESTDIR =  $$PWD/../../app/bin/debug
    #target.path = /debug
    #INSTALLS += target
}else{
    DESTDIR = $$PWD/../../app/bin/release
}
