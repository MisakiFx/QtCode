#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //动态分配空间不能指定父对象
    myT = new MyThread;
    //新建子线程
    thread = new QThread(this);
    //把自定义线程加入到子线程中
    myT->moveToThread(thread);
    connect(myT, &MyThread::mySignal, this, &deelSiganl);
    qDebug() << "主线程:" << QThread::currentThread();
    connect(this, &startThread, myT, &MyThread::myTimeout);
    connect(this, &MyWidget::destroyed, this, &deelClose);
    //connect第五个参数在多线程时才有意义
    //连接方式：默认，队列，直接
    //多线程默认使用队列
    //单线程。默认使用直接
    //队列，槽函数所在线程和接收者一样
    //直接，槽函数所在线程和发送者一样
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::deelSiganl()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void MyWidget::on_buttonStart_clicked()
{
    if(thread->isRunning() == false)
    {
        //启动线程，但没有启动线程处理函数
        thread->start();
        myT->setFlag(false);
        //不能直接调用线程处理函数
        //通过信号和槽的方式调用
        emit startThread();
    }
}

void MyWidget::on_buttonStop_clicked()
{
    if(thread->isRunning() == true)
    {
        myT->setFlag();
        thread->quit();
        thread->wait();
    }
}

void MyWidget::deelClose()
{
    on_buttonStop_clicked();
    delete myT;
}
