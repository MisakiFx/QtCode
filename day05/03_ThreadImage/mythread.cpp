#include "mythread.h"
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}
void MyThread::drawImage()
{
    //定义绘图设备
    QImage image(500, 500, QImage::Format_ARGB32);
    //定义画家，指定绘图设备
    QPainter p(&image);
    //定义画笔对象
    QPen pen;//画笔
    pen.setWidth(5);//设置宽度
    p.setPen(pen);
    QBrush brush;//画刷
    brush.setStyle(Qt::SolidPattern);//设定样式
    brush.setColor(Qt::red);//设定颜色
    p.setBrush(brush);

    //定义五个点
    QPoint a[5] =
    {
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
    };

    p.drawPolygon(a, 5);
    //通过信号发送图片
    emit updateImage(image);
}

