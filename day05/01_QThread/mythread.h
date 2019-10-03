#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
protected:
    void run();//线程处理函数
signals:
    void isDone();//自定义信号
public slots:
};

#endif // MYTHREAD_H
