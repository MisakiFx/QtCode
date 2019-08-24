#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>//滑块类
#include <QBoxLayout>//布局管理器类
SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox* spin = new QSpinBox(this);
    QSlider* slider = new QSlider(Qt::Horizontal, this);//滑块控件

    QHBoxLayout* hLayout = new QHBoxLayout(this);//布局管理器
    //添加控件到布局中
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);
    //setLayout(hLayout);//如果没有指定父对象
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);
}

