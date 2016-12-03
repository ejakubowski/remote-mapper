#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T05:01:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = remote_mapper
TEMPLATE = app

LIBS += -lUser32

SOURCES += main.cpp\
        mainwindow.cpp \
    shortcuts.cpp

HEADERS  += mainwindow.h \
    shortcuts.h

FORMS    += mainwindow.ui
