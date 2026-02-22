#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    // 此时按钮就处于禁用状态
    button->setEnabled(false);

    // 关联一个槽函数，证明按钮确实被禁用了
    connect(button,&QPushButton::clicked,this,&Widget::handle); // 和连不连接槽函数无关，按钮确实被禁用了
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    qDebug() << "handle";
}

