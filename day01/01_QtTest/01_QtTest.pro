#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T01:48:26
#
#-------------------------------------------------

#模块
#包含头文件还需要在工程文件加指定的模块，类上按f1打开帮助文档
QT       += core gui
#常用模块(widgets:基本模块gui界面, webkit:浏览器引擎,
#Test测试单元, SQL数据库, network:网络通信, nulitmedia:多媒体)

#高于4版本，添加QT += widgets为了兼容QT4以前的版本
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#应用程序的名字
TARGET = Misaki
#指定makefile的类型,app （lib）
TEMPLATE = app

#源文件 .cpp文件
SOURCES += main.cpp\
        mywidget.cpp
#头文件 .h文件
HEADERS  += mywidget.h
