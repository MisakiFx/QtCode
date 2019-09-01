#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>//文件打开对话框
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonRead_clicked()
{

    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt);;"
                                                                     "*.*(*.*)");
    if(!path.isEmpty())
    {
        //文件操作，读到文本框中，默认只识别UTF8
        //创建文件对象
        QFile file(path);
        //以只读方式打开
        bool isOk = file.open(QIODevice::ReadOnly);
        if(isOk == true)
        {
            //读文件到文本框
            //1、一次性读完（不靠谱）
//            QByteArray array = file.readAll();
//            //显示编辑区
//            ui->textEdit->setText(QString(array));
            //2、一行一行读
            QByteArray array;
            //atEnd()来判断是否读到尾了
            while(file.atEnd() == false)
            {
                array += file.readLine();
            }
            //读完显示
            ui->textEdit->setText(QString(array));
        }
        //别忘关闭文件
        file.close();
    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    if(!path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        //打开文件
        bool isOk = file.open(QIODevice::WriteOnly);
        if(isOk == true)
        {
            //获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            //写文件
            //默认都是UTF8
            //file.write(str.toUtf8());
            //file.write(str.toStdString().c_str());
            //转换本地平台编码，windows是ansi编码
            file.write(str.toLocal8Bit());
        }
        //关闭
        file.close();
    }
}
