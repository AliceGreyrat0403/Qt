#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 不建议放到对象树上，那样new出来还要手动释放，因为无法挂到对象树上，因此我们和前面的QCursor一样直接定义到栈上

    // 访问到图片文件
    QPixmap pixmap(":/Alice.png");
    // 图片如果比较大或者比较小，我们可以针对图片进行一个缩放————pixmap通过了scaled这样一个方法
    // 可以针对图片进行一个缩放
    pixmap = pixmap.scaled(100,100); // 基于图片本体又生成了一个副本，要获取到这个新的副本
    // 构造光标对象
//    QCursor cursor(pixmap);
    QCursor cursor(pixmap,10,10);
    // 把光标设置进去
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

