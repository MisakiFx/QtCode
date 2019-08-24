#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //接收事件，事件不会继续往下传递
        qDebug() << "按下的是左键";
        //忽略事件，让其继续向下传递
        e->accept();//它会将这个事件传递给父组件
        //父组件就是它的父窗口，在这里就是MyWidget
        //e->accept();
    }
    else
    {
        //忽略事件，事件会继续往下传递
        QPushButton::mousePressEvent(e);
    }
    //QPushButton::mousePressEvent(e);
}

