#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariantList>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../info.db");
    if(!db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query;
    query.exec("create table student("
               "id int primary key,"
               "name varchar(255),"
               "age int,"
               "score int"
               ");");
    query.prepare("insert into student(name, age, score) values(:name, :age, :score);");
    QVariantList nameList;
    nameList << "Jack" << "King" << "Que";
    QVariantList ageList;
    ageList << 19 << 20 << 20;
    QVariantList scoreList;
    scoreList << 59 << 69 << 79;
    //给字段绑定
    query.bindValue(":name", nameList);
    query.bindValue(":score", scoreList);
    query.bindValue(":age", ageList);
    //执行预处理命令
    query.execBatch();
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
