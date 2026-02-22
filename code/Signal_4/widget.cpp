#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this,&Widget::mySignal,this,&Widget::handleMySignal);
}

Widget::~Widget()
{
    delete ui;
}

// 一个槽函数，有可能绑定多个信号
// 如果我们严格要求参数个数一致，就意味着信号绑定到槽的要求就变高了
// 换言之，当下这样的规则，就允许信号和槽之间的绑定更灵活了，更多的信号可以绑定到这个槽函数上了
// 个数不一致，槽函数就会按照参数顺序拿到信号的前N个参数
// 至少需要确保槽函数的每个参数都是有值的，要求信号给槽的参数，可以有富裕，但是不能少（比如生活费，所谓“穷家富路”）
void Widget::handleMySignal(const QString& text)
//void Widget::handleMySignal(const QString& text,const QString& text2)
//void Widget::handleMySignal(const QString& text)
{
//    this->setWindowTitle("处理自定义信号！");
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    // 发送出自定义的信号
    // 发送信号的操作，也可以在任意合适的代码中，不一定非得在构造函数里

    // 此时就是点击按钮的时候，发送自定义信号了
//    emit mySignal();    // 发射mysignal信号 // emit是关键字

    // Qt发展到Qt5，其实这个emit啥也没干
    /*mySignal();*/ // 即使不写emit，信号也能发出去！
    // 即使如此还是建议把emit加上，加上之后代码可读性更高，很明显地标识出这里是发射自定义的信号了

//    emit mySignal("带参数的信号！");
//    emit mySignal("把标题设置为标题1！");
//    emit mySignal("把标题设置为标题1！","");
    emit mySignal(10);  // 10这个整数是不能直接传给QString的，类型就不匹配
}

void Widget::on_pushButton_2_clicked()  // 槽还是同一个信号槽，搭配了不同的参数，参数类型要一致
{
    emit mySignal(20);
//    emit mySignal("把标题设置为标题2！");
//    emit mySignal("把标题设置为标题2！","");
}

void Widget::on_pushButton_3_clicked()
{
    emit mySignal(30);
//    emit mySignal("把标题设置为标题3！");
//    emit mySignal("把标题设置为标题3！","");
}
