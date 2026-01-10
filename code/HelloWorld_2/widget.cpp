#include "widget.h"
#include "ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Qt中更加推荐这种在堆上创建的方式
    QLabel* label = new QLabel(this);   // 给当前这个label对象指定一个“父对象”
    //QLabel label;   // 在栈上创建
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}

