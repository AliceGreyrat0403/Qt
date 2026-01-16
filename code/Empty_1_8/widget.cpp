#include "widget.h"     // 创建项目生成的头文件
#include "ui_widget.h"  // form file被qmake生成的头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)    // 把form file生成的界面和当前widget关联起来
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

