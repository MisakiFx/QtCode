#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    resize(500, 500);
    ui->setupUi(this);
    myT = new MyThread;
    //子线程
    thread = new QThread(this);
    //把自定义模块添加到子线程
    myT->moveToThread(thread);
    thread->start();
    connect(ui->pushButton, &QPushButton::clicked, myT, &MyThread::drawImage);
    connect(myT, &MyThread::updateImage, this, &Widget::getImage);
    connect(this, &Widget::destroyed, this, &Widget::deelClose);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0, 0, _image);
}
void Widget::getImage(QImage image)
{
    _image = image;
    update();
}
void Widget::deelClose()
{
    thread->quit();
    thread->wait();
    delete myT;
}
