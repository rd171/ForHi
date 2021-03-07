#-------------------------------------------------
#
# Project created by QtCreator 2021-02-13T19:23:24
#
#-------------------------------------------------

QT       += widgets network  sql script scripttools svg xml xmlpatterns multimedia  testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib


SOURCES += gui.cpp \
    qresmanager.cpp \
    qimagegrid.cpp \
    qimagedraw.cpp \
    Exif.cpp

HEADERS += gui.h\
        gui_global.h \
    qresmanager.h \
    qimagegrid.h \
    qimagedraw.h \
    Exif.h

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
