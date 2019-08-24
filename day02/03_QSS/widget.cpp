#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setStyleSheet("QLabel"
                        "{"
                        "color:rgb(0, 255, 255);"
                        "background-color:red;"
                        "}");
    ui->label->setStyleSheet("QLabel"
                             "{"
                             "color:rgb(0, 255, 255);"
                             "background-color:green;"
                             "border-image:url(://image/1.jpg)"
                             "}");
    //设置为状态，QPushButton:hover，鼠标移动到上面就将样式表换成以下样子
    ui->pushButton->setStyleSheet("QPushButton"
                                  "{"
                                  "border: 2px outset green;"
                                  "border-image:url(://image/1.jpg);"
                                  "}"
                                  "QPushButton:hover"
                                  "{"
                                  "border-image:url(://image/2.jpg);"
                                  "}"
                                  "QPushButton:pressed"
                                  "{"
                                  "border-image:url(://image/3.jpg);"
                                  "}"
                                  );
}

Widget::~Widget()
{
    delete ui;
}
