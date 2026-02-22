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
    button->move(200,200);

    // 如果你在这里自己创建一些对象，被lambda捕获
    // 关于对象生命周期管理，也是C++程序员的必修课！

//    connect(button,&QPushButton::clicked,this,[button,this](){
    connect(button,&QPushButton::clicked,this,[=](){    // 获取所有的变量
        qDebug() << "lambda被执行了！";
        button->move(300,300);
        this->move(100,100);
    }); // 此时的lambda就被认为是一个槽函数，和信号相关联
}

Widget::~Widget()
{
    delete ui;
}

