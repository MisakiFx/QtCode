#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    //QPixMap
    p.drawPixmap(0, 0, 300, 200, QPixmap("../image/1.jpg"));
    //QBitMap
    QBitmap qBitmap;
    qBitmap.load("../image/1.jpg");
    p.drawPixmap(300, 0, 300, 200, qBitmap);
}
