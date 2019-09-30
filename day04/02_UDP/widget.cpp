#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(8000);
    setWindowTitle("Server port 8000");
    connect(udpSocket, &QUdpSocket::readyRead, this, &deelMessage);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::deelMessage()
{
    char data[1024] = {0};
    QHostAddress addr;//对方地址
    quint16 port;//对方端口
    qint64 len = udpSocket->readDatagram(data, sizeof(data) - 1, &addr, &port);
    if(len > 0)
    {
        //格式化
        QString str = QString("[%1:%2] >> %3").arg(addr.toString()).arg(port).arg(data);
        ui->textEdit->setText(str);
    }
}

void Widget::on_ButtonSend_clicked()
{
    QString ip = ui->lineEditIP->text();
    if(ip == "")
    {
        return;
    }
    quint16 port = ui->lineEditPort->text().toInt();
    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);

}
