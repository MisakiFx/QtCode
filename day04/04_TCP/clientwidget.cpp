#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget),
    tcpSocket(nullptr)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEditRead->setText("成功和服务器建立好连接");

            }
            );
    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                //获取对方发送的内容
                QByteArray array = tcpSocket->readAll();
                ui->textEditRead->append(array);
            }

            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    //获取服务器ip和端口
    QString ip = ui->lineEditIp->text();
    quint16 port = ui->lineEditPort->text().toInt();
    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void ClientWidget::on_buttonSend_clicked()
{
    if(tcpSocket->state() != 3)
    {
        return;
    }
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->clear();
}

void ClientWidget::on_buttonClose_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
