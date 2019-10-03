#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
signals:
    void startThread();//启动子线程的信号
private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();
    void deelClose();
private:
    Ui::MyWidget *ui;
    MyThread* myT;
    //创建子线程
    QThread* thread;
    void deelSiganl();
};

#endif // MYWIDGET_H
