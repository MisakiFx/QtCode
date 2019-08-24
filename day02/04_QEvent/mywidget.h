#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *);
    //定时器事件
    void timerEvent(QTimerEvent *);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *);
    //关闭事件
    void closeEvent(QCloseEvent *);
    //冲写event事件
    //event()是类下面一层的事件分发函数，
    //经过event才会将不同的信号分发给
    //下面的事件处理函数
    bool event(QEvent *);
    //事件过滤器
    bool eventFilter(QObject *, QEvent *);
private:
    Ui::MyWidget *ui;
    int timerId;
    int timerId2;
};

#endif // MYWIDGET_H
