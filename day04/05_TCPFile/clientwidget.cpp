#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QMessageBox>
#include <QDebug>
#include <QHostAddress>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    isStart = true;
    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                //取出接收的内容
                QByteArray buf = tcpSocket->readAll();
                if(isStart == true)//头
                {
                    isStart = false;
                    //解析头部信息
                    //初始化
                    fileName = QString(buf).section("##", 0, 0);
                    fileSize = QString(buf).section("##", 1, 1).toInt();
                    recvSize = 0;

                    //打开文件
                    file.setFileName(fileName);
                    bool isOk = file.open(QIODevice::WriteOnly);
                    if(isOk == false)
                    {
                        qDebug() << "只读打开出错";
                        //isStart = false;
                    }
                }
                else//文件信息
                {
                    qint64 len = file.write(buf);
                    recvSize += len;
                    if(recvSize == fileSize)
                    {
                        file.close();
                        QMessageBox::information(this, "success", "文件接收完成");
                        isStart = false;
                    }
                }
            }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip), port);

}
