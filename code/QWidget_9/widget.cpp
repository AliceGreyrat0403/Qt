#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 不需要创建到对象树上，直接挂到栈上就行
    QCursor cursor(Qt::WaitCursor);
//    ui->pushButton->setCursor(cursor);  // 给按钮设置
    this->setCursor(cursor);  // 给窗口设置
}

Widget::~Widget()
{
    delete ui;
}

