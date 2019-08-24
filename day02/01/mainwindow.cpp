#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("123");
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::close);

    //lineEdit
    QString str = ui->lineEdit->text();//获取内容
    qDebug() << str;
    //设置内容
    ui->lineEdit->setText("12345678");
    //设置内容显示间隙
    ui->lineEdit->setTextMargins(15, 0, 0, 0);
    //设置显示模式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);
    QStringList list;
    list << "hello" << "how are you" << "Misaki";
    QCompleter* com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    //QLabel
    //设置文本内容
    ui->labelEdit->setText("Misaki");
    //设置图片
    ui->labelPicture->setPixmap(QPixmap("://image/1.jpg"));
    //设置让图片自适应label大小
    ui->labelPicture->setScaledContents(true);
    //设置GIF
    QMovie* myMovie = new QMovie("://image/2.gif");
    ui->labelGIF->setMovie(myMovie);
    //启动动画
    myMovie->start();
    //自适应大小
    ui->labelGIF->setScaledContents(true);
    //设置html
    ui->labelUrl->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a><h1>");
    ui->labelUrl->setOpenExternalLinks(true);
    //数码管
    ui->lcdNumber->display(123);
    //进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(200);
    ui->progressBar->setValue(100);
    //微型网页
    ui->webView_2->load(QUrl("http://www.baidu.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 3);
}
