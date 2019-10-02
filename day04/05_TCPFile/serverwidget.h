#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private slots:
    void on_buttonFile_clicked();

    void on_buttonSend_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer* tcpServer;//监听套接字
    QTcpSocket* tcpSocket;//通信套接字
    QFile file;//文件对象
    QString fileName;//文件名字
    quint64 fileSize;//文件大小
    quint64 sendSize;//已发送文件大小
    QTimer timer;
private:
    //发送文件数据
    void sendData();

};

#endif // SERVERWIDGET_H
