#include "mywidget.h"
#include "ui_mywidget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //开启定时器
    timerId = this->startTimer(1000);
    timerId2 = this->startTimer(500);
    connect(ui->pushButton, &MyButton::clicked,
            [=]()
            {
                qDebug() << "按钮被按下";
            }
            );
    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);
}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();
    if(e->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == timerId)
    {
        static int sec = 0;
        ui->label->setText(QString("<center><h1>time out: %1</h1></center>").arg(sec++));
        if(5 == sec)
        {
            this->killTimer(timerId);
        }
    }
    else if(e->timerId() == timerId2)
    {
        static int sec = 0;
        ui->label_2->setText(QString("<center><h1>time out: %1</h1></center>").arg(sec++));
    }
}
void MyWidget::mousePressEvent(QMouseEvent* e)
{
    qDebug() << "+++++++++++++++";
}
void MyWidget::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, "question", "关是不关");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接收事件，事件就不会再往下传递
        e->accept();
    }
    else
    {
        //不关闭窗口
        //忽略事件，事件继续给父组件传递
        e->ignore();
    }
}
bool MyWidget::event(QEvent *e)
{
    //事件分发
//    switch(e->type())
//    {
//        case QEvent::Close:
//            closeEvent(e);
//            break;
//        case QEvent::MouseMove:
//            mouseMoveEvent(e);
//            break;
//    }
    if(e->type() == QEvent::Timer)
    {
        //干掉定时器
        //如果返回true，事件停止传播
        //QTimerEvent* env = static_cast<QTimerEvent*>(e);
        //timerEvent(env);
        return true;
    }
    else if(e->type() == QEvent::KeyPress)
    {
        QKeyEvent* env = static_cast<QKeyEvent*>(e);
        if(env->key() == Qt::Key_B)
        {
            return QWidget::event(e);
        }
        return true;
    }
    else
    {
        return QWidget::event(e);
        //return true;
        //return false;
    }
}
//obj表示处理事件的对象，e是事件
bool MyWidget::eventFilter(QObject* obj, QEvent* e)
{
    if(obj == ui->label_2)
    {
        QMouseEvent* env = static_cast<QMouseEvent*>(e);
        //判断事件;
        if(e->type() == QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Mouse Move:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonPress)
        {
            ui->label_2->setText(QString("Mouse Move:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonRelease)
        {
            ui->label_2->setText(QString("Mouse Move:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
    }
    return QWidget::eventFilter(obj, e);
}
