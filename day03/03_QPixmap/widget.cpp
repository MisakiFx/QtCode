#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //常用绘图设备除窗口外有三种绘制图片的
    //1、Pixmap，与平台相关，针对屏幕进行优化
    //2、Image，与平台无关，支持线程绘图，并且可以对图片进行修改
    //3、Picture，主要用来保存状态，保存为二进制，其他都是保存成图片
    ui->setupUi(this);
    //绘图设备,400 * 300
    QPixmap pixmap(400, 300);
    //创建画家
    QPainter p(&pixmap);
    //填充背景
    p.fillRect(0, 0, 400, 300, QBrush(Qt::white));
    //放张图片进去
    p.drawPixmap(0, 0, 300, 200, QPixmap("../image/1.jpg"));
    //保存为图片
    pixmap.save("../image/3.jpg");
}

Widget::~Widget()
{
    delete ui;
}
