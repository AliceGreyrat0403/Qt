#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_add_clicked()
{
    // 在这里完成不透明度的修改
    float opacity = this->windowOpacity();
    if(opacity >= 1.0)
    {
        return;
    }
    qDebug() << opacity;
    opacity += 0.1; // 数值变大意味着不透明度增加了
    // 把修改之后的值重新设置进去
    this->setWindowOpacity(opacity);
}

void Widget::on_pushButton_sub_clicked()
{
    // 先获取到当前的opacity的值
    float opacity = this->windowOpacity();
    if(opacity <= 0.0)
    {
        return;
    }
    qDebug() << opacity;
    opacity -= 0.1;
    this->setWindowOpacity(opacity);
}
