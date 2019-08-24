#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //自动追踪鼠标
    this->setMouseTracking(true);
}
//ev鼠标事件控制类
void MyLabel::mousePressEvent(QMouseEvent* ev)
{
    int i = ev->x();
    int j = ev->y();
    if(ev->button() == Qt::LeftButton)
    {
        QString text = QString("<center><h1>MouseLeft Press: (%1, %2)</h1></center>").arg(i).arg(j);
        this->setText(text);
    }
    else if(ev->button() == Qt::RightButton)
    {
        QString text = QString("<center><h1>MouseRight Press: (%1, %2)</h1></center>").arg(i).arg(j);
        this->setText(text);
    }
    else
    {
        QString text = QString("<center><h1>MouseOther Press: (%1, %2)</h1></center>").arg(i).arg(j);
        this->setText(text);
    }
//    QString text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>").arg(i).arg(j);
//    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent* ev)
{
    QString text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(text);
}
void MyLabel::enterEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse Enter</h1></center>");
    this->setText(text);
}
void MyLabel::leaveEvent(QEvent *e)
{
    QString text = QString("<center><h1>Mouse Leave</h1></center>");
    this->setText(text);
}
