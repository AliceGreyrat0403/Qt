#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("关闭");  // 设置文本
    button->move(200,200);  // 设置按钮位置

    connect(button,&QPushButton::clicked,this,&Widget::close);   // 继承自QWidget，QWidget继承自QObject
}

Widget::~Widget()
{
    delete ui;
}

