#include "mythread.h"
#include <QThread>
#include <QDebug>
MyThread::MyThread(QObject *parent)
    : QObject(parent)
    , isStop(false)
{

}

void MyThread::myTimeout()
{
    //线程处理函数内部不允许操作图形界面
    qDebug() << isStop;
    while(isStop == false)
    {
        QThread::sleep(1);
        emit mySignal();
        qDebug() << "子线程:" << QThread::currentThread();
        if(isStop == true)
        {
            break;
        }
    }
}
void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
