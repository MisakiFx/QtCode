#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去窗口边框
    //windowFlags()获取原来窗口属性
    //这个函数可以改变窗口属性
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}
//绘制一个不规则窗口
void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, 300, 200, QPixmap("../image/1.jpg"));

}
void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        close();
    }
    else if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        //globalPos()可以获取当前鼠标点击相对整个屏幕的坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    //鼠标移动并且鼠标左键按下
    if(e->buttons() & Qt::LeftButton)
    {
        //p = e->globalPos() - this->frameGeometry().topLeft();
        move(e->globalPos() - p);
    }
}
