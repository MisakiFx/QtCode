#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout,
            [=]()
            {
                static int i = 0;
                i++;
                ui->lcdNumber->display((i));
            }
            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonStart_clicked()
{
    //启动定时器，事件间隔100毫秒
    //每隔100毫秒定时器内部自动触发timeout信号
    //不活动才启动
    if(!myTimer->isActive())
    {
        myTimer->start(100);
    }
}

void Widget::on_ButtonStop_clicked()
{
    //活动的才关闭
    if(myTimer->isActive())
    {
        myTimer->stop();
    }
}
