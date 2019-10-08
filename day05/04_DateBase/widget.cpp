#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印支持的数据库
    qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");//数据库服务器IP
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

    QSqlQuery query(db);
//    query.exec("create table student("
//               "id int primary key auto_increment,"
//               "name varchar(255),"
//               "age int,"
//               "score int"
//               ");");
    //query.exec("insert into student(id, name, age, score) values(1, 'Misaki', 20, 90);");
    //批量插入odbc风格
    //?相当于占位符
//    query.prepare("insert into student(name, age, score) values(?, ?, ?);");
//    //给字段设置内容 list
//    QVariantList nameList;
//    nameList << "Mike" << "Lisa" << "Aida";
//    QVariantList ageList;
//    ageList << 19 << 20 << 20;
//    QVariantList scoreList;
//    scoreList << 59 << 69 << 79;
//    //给字段绑定相应的值,按顺序
//    query.addBindValue(nameList);
//    query.addBindValue(ageList);
//    query.addBindValue(scoreList);
//    //执行预处理命令
//    query.execBatch();
    //oracle风格批量插入
//    query.prepare("insert into student(name, age, score) values(:name, :age, :score);");
//    QVariantList nameList;
//    nameList << "Jack" << "King" << "Que";
//    QVariantList ageList;
//    ageList << 19 << 20 << 20;
//    QVariantList scoreList;
//    scoreList << 59 << 69 << 79;
//    //给字段绑定
//    query.bindValue(":name", nameList);
//    query.bindValue(":score", scoreList);
//    query.bindValue(":age", ageList);
//    //执行预处理命令
//    query.execBatch();
    query.exec("select * from student;");
    while(query.next())//遍历
    {
        //取出当前行的内容
        qDebug() << query.value(0).toInt()
                 << query.value("name").toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
    //获取行编辑内容
    QString name = ui->lineEdit->text();
    QString sql = QString("delete from student where name = '%1'").arg(name);
    //开启一个事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);
}

void Widget::on_buttonSure_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_buttonCancel_clicked()
{
    //回滚
    QSqlDatabase::database().rollback();
}
