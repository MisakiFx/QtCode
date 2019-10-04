#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
#include <QImage>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //重写绘图事件
    void paintEvent(QPaintEvent *);
private:
    Ui::Widget *ui;
    QImage _image;
    MyThread* myT;//自定义线程
    QThread* thread;//子线程
    void getImage(QImage image);//槽函数
    void deelClose();
};

#endif // WIDGET_H
