#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPen>//画笔类
#include <QBrush>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    //这里参数需要指定一个绘图设备
    //QWidget继承于QPainteDevice所以它也是一个绘图设备
    //绘图设备就是我们要准备往上绘图的组件
    //我们可以直接传QWidget
    //QPainter p(this);
    QPainter p;//创建画家对象
    //画家对象等同于操纵画东西的句柄，一个画家对象同时只能绘图一个组件
    //此时画家对象将会往this这个组件上绘图
    p.begin(this);//指定当前窗口为绘图设备
    //绘图操作
    //画背景图
    //p.drawPixmap(0, 0, width(), height(), QPixmap("../image/1.jpg"));
    //先画背景再画线不然会被盖住
    p.drawPixmap(rect(), QPixmap("../image/1.jpg"));
    //定义画笔
    QPen pen;
    pen.setWidth(5);//设置线宽
    //pen.setColor(Qt::red);
    pen.setColor(QColor(14, 9, 234));//rgb设置颜色
    pen.setStyle(Qt::DashLine);//设置线条风格
    //把画笔交给画家
    p.setPen(pen);
    //画直线
    p.drawLine(50, 50, 150, 50);//给起点终点坐标
    p.drawLine(50, 50, 50, 150);
    //创建画刷对象
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::Dense1Pattern);
    //将画刷交给画家
    p.setBrush(brush);
    //画矩形
    p.drawRect(150, 150, 100, 50);//起点坐标，宽度，高度
    //改变一次画刷或者笔就要把它重新交给画家一次(十分不智能十分垃圾)
    brush.setColor(Qt::red);
    p.setBrush(brush);
    //画圆/椭圆
    p.drawEllipse(QPoint(150, 150), 50, 50);//圆心坐标，水平半径，垂直半径
    //画图片
    p.drawPixmap(x, 180, 100, 80, QPixmap("../image/1.jpg"));
    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width())
    {
        x = 0;
    }
    //调用绘图事件函数刷新，让整个窗口重绘
    //手动调用paintEvent()函数
    //这个玩意不要放到paintEvent()中会无限递归
    update();//相当于间接调用paintEvent()函数

}
