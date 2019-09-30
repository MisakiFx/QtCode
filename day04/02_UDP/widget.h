#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>//Udp套接字
#include <QHostAddress>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_ButtonSend_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket* udpSocket;
    //槽函数，处理对方发送的数据
    void deelMessage();
};

#endif // WIDGET_H
