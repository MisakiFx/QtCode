#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#define cout qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}:"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::writeData()
{
    QFile file;
    file.setFileName("../test.txt");
    bool isOk = file.open(QIODevice::WriteOnly);
    if(isOk == true)
    {
        QTextStream stream(&file);
        //默认以平台编码写入
        //可以指定编码
        stream.setCodec("UTF-8");
        stream << QString("Misaki Nice牛逼") << 250;
        file.close();
    }
}
void Widget::readData()
{
    QFile file;
    file.setFileName("../test.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk == true)
    {
        QTextStream stream(&file);
        //默认以平台编码写入
        //可以指定编码
        stream.setCodec("UTF-8");

        file.close();
    }
}
void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt);;ALL(*.*)");
    if(path.isEmpty() == false)
    {
        QFile file;
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == true)
        {
            QTextStream stream(&file);
            //默认以平台编码读入
            //可以指定编码
            stream.setCodec("UTF-8");
            QString str = stream.readAll();
            ui->textEdit->setText(str);
        }
    }
}
