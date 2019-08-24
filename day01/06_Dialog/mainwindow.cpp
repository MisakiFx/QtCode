#include "mainwindow.h"
#include <QMenuBar>//菜单栏
#include <QMenu>//菜单
#include <QAction>//动作
#include <QDockWidget>//浮动窗口
#include <QDialog>//对话框
#include <QDebug>
#include <QMessageBox>//信息对话框
#include <QFileDialog>//文件对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* mBar = menuBar();
    setMenuBar(mBar);
    QMenu* menu = mBar->addMenu("对话框");
    QAction* p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();//程序执行至此循环至此等待操作
                qDebug() << "1";
            }
            );
    QAction* p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
            [=]()
            {
//                dlg.show();//程序执行至此循环至此等待操作
//                qDebug() << "1";
//                QDialog* p = new QDialog(this);
//                p->show();
                QDialog* p = new QDialog;
                //非模态对话框让其关闭时自动释放空间，不能指定父对象
                //不然点一次分配一次内存
                p->setAttribute(Qt::WA_DeleteOnClose);
                p->show();
            }
            );
    QAction* p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=]()
            {   //这个也是模态的
                QMessageBox::about(this, "abort", "关于QT");
            }
            );
    QAction* p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=]()
            {   //这个也是模态的
                //问题对话框返回值会返回按下了那个按钮的宏
                //可以自定义按键
                int ret = QMessageBox::question(this, "问题对话框", "Are you ok", QMessageBox::Ok | QMessageBox::Cancel);
                switch(ret)
                {
                    case QMessageBox::Ok:
                        qDebug() << "Yes";
                        break;
                    case QMessageBox::Cancel:
                        qDebug() << "No";
                        break;
                    default:
                        break;
                }
            }
            );
    QAction* p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=]()
            {
                QString path = QFileDialog::getOpenFileName(this, "open",
                                                            "../",
                                            "source(*.cpp *.h);;Text(*.txt *.);;all(*.*)"

                                                            );
                qDebug() << path;

            }
            );
}

MainWindow::~MainWindow()
{

}
