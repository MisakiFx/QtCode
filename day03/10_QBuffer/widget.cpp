#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QByteArray array;
    QBuffer memFile(&array, this);
    memFile.open(QIODevice::WriteOnly);
    memFile.write("Misaki");
    memFile.write("Misakifx");
    memFile.close();
    qDebug() << memFile.buffer();
    qDebug() << "array = " << array;
    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream << QString("Misaki牛逼") << 250;
    memFile1.close();
    qDebug() << memFile1.buffer();
    memFile1.open(QIODevice::ReadOnly);
    QDataStream stream1;
    stream1.setDevice(&memFile1);
    QString str;
    int a;
    stream1 >> str >> a;
    memFile1.close();
    qDebug() << str.toUtf8().data() << a;
}

Widget::~Widget()
{
    delete ui;
}
