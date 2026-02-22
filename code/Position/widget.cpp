#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200,300);    // 坐标背后的单位：像素

    // 窗口所在位置也可以move
    this->move(100,0);
}

Widget::~Widget()
{
    delete ui;
}

