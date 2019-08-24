#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //对于主窗口（父窗口），坐标系统相对于屏幕
    //原点：相对于屏幕左上角
    //x：往右递增
    //y：往下递增
    move(100, 100);
    //子窗口：坐标系统相对于父窗口
    //原点：相对于窗口空白区域左上角（不包括边框）
    //x：往右递增
    //y：往下递增
    QPushButton* b1 = new QPushButton(this);
    b1->move(200, 200);
    b1->setText("Misaki");
    b1->resize(100, 100);
    resize(500, 500);
    QPushButton* b2 = new QPushButton(b1);
    b2->move(25, 25);
    b2->setText("Misaki");
    b2->resize(50, 50);
    //QT内存回收机制
    //QT内部实现对象树，只要指定父对象，就会建立对象树，
    //在生命周期结束后会自动释放所有控件的内存和资源（大大减少内存泄漏的几率）
    //但是要求控件不惜直接或间接继承于QObject

    MyButton* b3 = new MyButton(this);
    b3->setText("123");

}

MyWidget::~MyWidget()
{

}
