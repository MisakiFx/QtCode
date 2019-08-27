#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
#include <QImage>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);
    p.drawPixmap(0, 0, 300, 200, QPixmap("../image/1.jpg"));
    p.drawLine(50, 50, 150, 50);
    p.end();
    //保存的是二进制文件
    picture.save("../image/pic.png");
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
//    QPicture pic;
//    //加载文件
//    pic.load("../image/pic.png");
//    QPainter p;
//    p.begin(this);
//    p.drawPicture(0, 0, pic);
//    p.end();
    QPixmap pixmap("../image/1.jpg");
    //QPixmap转换为QImage
    QImage tempImage = pixmap.toImage();
    QPainter p(this);
    p.drawImage(0, 0, tempImage, 500, 500, 200, 200);
    QImage image("../image/1.jpg");
    //QImage转换为QPixmap
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(200, 0, 300, 200, tempPixmap);
}
