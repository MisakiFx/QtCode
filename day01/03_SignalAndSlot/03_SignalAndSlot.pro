#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T23:18:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03_SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    subwidget.cpp

HEADERS  += mainwidget.h \
    subwidget.h
#使用C++11特性
CONFIG += C++11
