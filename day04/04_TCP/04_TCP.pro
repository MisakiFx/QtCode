#-------------------------------------------------
#
# Project created by QtCreator 2019-09-18T00:57:30
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04_TCP
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp

HEADERS  += serverwidget.h

FORMS    += serverwidget.ui
CONFIG += C++11
