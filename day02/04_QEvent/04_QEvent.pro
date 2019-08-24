#-------------------------------------------------
#
# Project created by QtCreator 2019-08-05T23:59:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04_QEvent
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += mywidget.h \
    mylabel.h \
    mybutton.h

FORMS    += mywidget.ui

CONFIG += C++11
