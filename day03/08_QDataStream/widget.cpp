#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    WriteData();
    ReadData();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::WriteData()
{
    //创建文件对象
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::WriteOnly);
    if(isOk == true)
    {
        //创建数据流，和file文件关联
        //往数据流中输入数据相当于往文件中写数据
        QDataStream stream(&file);
        //以二进制方式写入，最终保存方式为二进制
        stream << QString("Misaki牛逼") << 200;
        file.close();
    }
}
void Widget::ReadData()
{
    QFile file("../test.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk == true)
    {
        QDataStream stream(&file);
        //读数据
        QString string;
        int a;
        stream >> string;
        stream >> a;
        cout << (string.toUtf8().data()) << a;
        file.close();
    }
}
