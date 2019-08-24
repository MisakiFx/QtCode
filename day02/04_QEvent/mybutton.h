#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>


class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYBUTTON_H
