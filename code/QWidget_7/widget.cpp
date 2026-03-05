#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置图标
    // 通过绝对路径的方式引入图片是不科学的
//    QIcon icon("D:/Alice.png");   // 要么/要么使用\\（原始的\  ），否则就是转义字符
//    QIcon icon("D:/tutu.jpg");   // 要么/要么使用\\（原始的\  ），否则就是转义字符

    // 间接路径的方式引入图片
    QIcon icon(":/tutu.jpg");   // :是前缀，前缀 + 文件名
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

// 因此，相比于使用绝对路径的方式，使用相对路径是更好的
// 相对路径，是以给定目录为基准，以.或者..的方式开头
