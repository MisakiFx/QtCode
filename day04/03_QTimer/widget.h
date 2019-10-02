#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>//定时器对象

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_ButtonStart_clicked();

    void on_ButtonStop_clicked();

private:
    Ui::Widget *ui;
    QTimer* myTimer;
};

#endif // WIDGET_H