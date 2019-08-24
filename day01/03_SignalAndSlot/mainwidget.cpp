#include "mainwidget.h"
#include <QDebug>//打印
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("信号与槽");
    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);
    //b2是指针要给空间
    b2 = new QPushButton(this);
    b2->setText("ABC");
    /**
     * @brief connect
     * &b1:信号发出者
     * &QPushButton::pressed:处理的信号， &发送者的类名::信号名字
     * this:信号接收者
     * &MainWidget::close:槽函数，信号处理函数    &接收者的类名::槽函数名字
     */
    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /*自定义槽：普通函数的用法
     * QT5:任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数和返回值）
     * 由于信号都是没有返回值的，所以，槽函数一定没有返回值
    */
    //release表示抬起发送信号
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);
    /*
     *  信号:短信
     *  槽函数：接收信号的手机
     */
    setWindowTitle("老大");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);
    //w.show();
    connect(&b3, &QPushButton::released, this, &MainWidget::changeMain);
    //处理子窗口的信号（比较麻烦）
    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
    connect(&subWin, funSignal, this, &MainWidget::dealSub);
    //用对应参数的槽函数接收对应参数的信号
    //如果信号出现重载会出现二义性
    void (SubWidget::*testSignal) (int, QString) = &SubWidget::mySignal;
    connect(&subWin, testSignal, this, &MainWidget::dealSlot);
    //QT4信号连接
    //QT4槽函数必须有slots关键字修饰
//  connect(&subWin, SIGNAL(mySignal(), this, SLOT(dealSub()));
//  connect(&subWin, SIGNAL(mySignal(int,QString)), this, SLOT(dealSlot(int,QString)));
    //Lambda表达式：匿名函数对象
    //C++11增加的新特性   项目文件：config += C++11
    //配合信号一起使用非常方便
    QPushButton* b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150, 150);
    int a = 10, b = 100;
    connect(b4, &QPushButton::clicked,
            //=：把外部所有局部变量以及类中所有成员以值传递方式传入
            //this：把类中所有成员以值传递方式
            //&：把外部所有局部变量不包括类中成员以引用方式传入
            //注意，当发送信号的对象为指针且在外部作用域时不要传外部局部变量的引用
//            [=](bool isCheck) mutable//mutable：传入变量只读，加此关键字可改
//            {
//                b4->setText("Misaki");
//                qDebug() << "Misaki";
//                a = 11;
//                qDebug() << a << " " << b;
//            }
            [=](bool isCheck)
            {
                qDebug() << isCheck;
            }

            );
    resize(400, 300);
}
void MainWidget::dealSlot(int a, QString str)
{
    //打印中文需要转换
    //QByteArray QString::toUtf8() const
    qDebug() << a << str.toUtf8().data();
}

void MainWidget::mySlot()
{
    if(b2)
    {
        b2->setText("123");
    }
    //b1.hide();
}
void MainWidget::changeMain()
{
    //子窗口显示
    subWin.show();
    //本窗口隐藏
    hide();
}
void MainWidget::dealSub()
{
    subWin.hide();
    show();
}

MainWidget::~MainWidget()
{

}
