#include "mainwindow.h"
#include <QMenuBar>//菜单栏
#include <QMenu>//菜单
#include <QAction>//菜单项/动作
#include <QDebug>
#include <QToolBar>//工具栏
#include <QPushButton>
#include <QStatusBar>//状态栏
#include <QLabel>//标签
#include <QTextEdit>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar* mBar = menuBar();//获取菜单栏对象
    setMenuBar(mBar);

    //添加菜单对象
    QMenu* pFile = mBar->addMenu("文件");//在菜单栏中添加菜单

    //添加菜单项/动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            [=]()
            {
                qDebug() << "新建被按下";
            }
            );
    pFile->addSeparator();//添加分割线
    QAction *pOpen = pFile->addAction("打开");
    //工具栏:菜单项的快捷方式
    QToolBar* toolBar = addToolBar("toolBar");

    //工具栏添加快捷键
    toolBar->addAction(pNew);
    //添加按钮到工具栏中
    QPushButton* b = new QPushButton(this);
    b->setText("^_^");
    //添加小控件
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=]()
            {
                b->setText("123");
            }
            );
    //状态栏
    QStatusBar* sBar = statusBar();//获取状态栏
    QLabel* labal = new QLabel(this);//创建标签
    labal->setText("Normal text file");
    //从左往右依次添加
    sBar->addWidget(labal);
    sBar->addWidget(new QLabel("2", this));
    //从右往左添加
    sBar->addPermanentWidget(new QLabel("3", this));
    //核心控件，文本编辑器
    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);//设置核心控件
    //浮动窗口
    QDockWidget* dock = new QDockWidget(this);
    //添加浮动窗口到主窗口
    addDockWidget(Qt::RightDockWidgetArea, dock);
    //给浮动窗口添加控件
    QTextEdit* textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);
}

MainWindow::~MainWindow()
{

}
