#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QDebug>
#include <QFileInfo>
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    fileName(),
    fileSize(0),
    sendSize(0),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    //服务端口8888
    tcpServer->listen(QHostAddress::Any, 8888);
    setWindowTitle("服务器端口:8888");
    //两个按钮都不能按
    ui->buttonFile->setEnabled(false);
    ui->buttonSend->setEnabled(false);
    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
            {
                //取出建立好链接的套接字
                tcpSocket = tcpServer->nextPendingConnection();
                //获取对方IP和端口
                QString ip = tcpSocket->peerAddress().toString();
                quint16 port = tcpSocket->peerPort();
                QString str = QString("[%1:%2] >> 成功连接").arg(ip).arg(port);
                ui->textEdit->setText(str);
                //成功连接后才能按
                ui->buttonFile->setEnabled(true);

            }

            );
    connect(&timer, &QTimer::timeout,
            [=]()
            {
                timer.stop();
                sendData();
            }
            );
}

ServerWidget::~ServerWidget()
{
    delete ui;
}
//选择文件按钮
void ServerWidget::on_buttonFile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "open", "../", "*.*(*.*)");
    if(filePath.isEmpty() == false)//如果选择的文件有效
    {
        fileName.clear();
        fileSize = 0;
        //获取文件信息
        QFileInfo info(filePath);
        fileName = info.fileName();
        fileSize = info.size();
        sendSize = 0;
        //只读方式打开文件
        file.close();
        file.setFileName(filePath);
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == false)
        {
            ui->textEdit->append("只读方式打开文件失败");
            return;
        }
        ui->textEdit->append(filePath);
        ui->buttonSend->setEnabled(true);

    }
    else
    {
        ui->textEdit->append("选择文件路径出错");
    }
}
//发送文件按钮
void ServerWidget::on_buttonSend_clicked()
{
    //先发送文件头信息
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    quint64 len = tcpSocket->write(head.toUtf8());
    if(len > 0)//头部信息发送成功
    {
        //防止TCP粘包问题
        timer.start(20);
    }
    else
    {
        ui->textEdit->append("头部信息发送失败");
    }
    //发送文件信息
}
//发送文件数据
void ServerWidget::sendData()
{
    quint64 len = 0;
    do
    {
        char buf[4 * 1024] = {0};
        //从文件中读数据
        len = file.read(buf, 4 * 1024);
        //读多少发多少
        len = tcpSocket->write(buf, len);
        sendSize += len;
    }while(len > 0);
    //是否发送文件完毕
    if(sendSize == fileSize)
    {
        ui->textEdit->append("文件发送完毕");

    }
    else
    {
        ui->textEdit->append("文件发送失败");
    }
}
