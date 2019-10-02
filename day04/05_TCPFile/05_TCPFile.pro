#-------------------------------------------------
#
# Project created by QtCreator 2019-10-02T15:49:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 05_TCPFile
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp \
    clientwidget.cpp

HEADERS  += serverwidget.h \
    clientwidget.h

FORMS    += serverwidget.ui \
    clientwidget.ui

CONFIG += C++11
