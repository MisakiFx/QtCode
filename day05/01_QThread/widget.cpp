#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &dealTimeout);
    thread = new MyThread(this);
    connect(thread, &MyThread::isDone, this, &deelDone);
    connect(this, &Widget::destroyed, this, &stopThread);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealTimeout()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_pushButton_clicked()
{
    if(timer->isActive() == false)
    {
        timer->start(100);
    }
    thread->start();
}
//线程执行结束
void Widget::deelDone()
{
    timer->stop();

}
//停止线程
void Widget::stopThread()
{
    thread->quit();
    thread->wait();
}
