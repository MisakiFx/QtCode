#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QSqlError>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印支持的数据库
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("182.92.67.216");//数据库服务器IP
    db.setUserName("root");//数据库用户名
    db.setPassword("1");
    db.setPort(3306);
    db.setDatabaseName("info");//使用哪个数据库
    //打开数据库
    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
}

Widget::~Widget()
{
    delete ui;
}
