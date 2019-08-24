#include <QApplication>
#include <QWidget>//窗口空间基类
#include <QPushButton>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("Misaki");//设置标题
    /*
     * 如果不指定父对象，对象和对象（窗口和按钮）没有关系，独立
     * a指定b为它的父对象，相当于a放在b上
     * 指定父对象，有两种方法：
     *              1)setParent
     *              2)通过构造函数传参
     * 指定父对象，只需要父对象显示，上面的子对象自动显示
     */
    QPushButton b;
    b.setText("^ _ ^");
    //b.show();//显示按钮
    b.setParent(&w);//指定父对象
    b.move(100, 100);//移动按键坐标
    QPushButton b1(&w);
    b1.setText("^_^");
    b1.move(300, 100);
    w.show();//只用显示父对象即可
    /*
     * 指定父对象后就有了父控件和子控件
     */
    app.exec();
    return 0;
}
