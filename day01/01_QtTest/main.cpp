 #include "mywidget.h"
//QApplication:应用程序类
//QT头文件特点：
//1、没有.h
//2、头文件名和类名一样
//3、都是Q开头，前两个字母大写
#include <QApplication>

int main(int argc, char *argv[])
{
    //规定有且只有一个应用程序类的对象
    QApplication a(argc, argv);
    //MyWidget继承于QWidget，QWidget是一个窗口基类
    //MyWidGet也是窗口类
    //w就是一个窗口
    MyWidget w;
    //窗口创建默认是隐藏的，需要人为显示
    w.show();
    //a.exec()让程序一直执行等待用户操作
    //等待事件的发生
    return a.exec();
}
