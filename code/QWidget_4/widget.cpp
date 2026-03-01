#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置随机种子，此处使用时间戳作为随机种子
    srand(time(0)); // C语言中通过time可以获取到一个秒级的时间戳
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("女神女神，快来嘴一个~mua~");
}

void Widget::on_pushButton_reject_clicked() // 鼠标点击（按下 + 回弹），一上一下是点击
{
    // 这个就不要了
}

void Widget::on_pushButton_reject_pressed() // 鼠标按下的时候就触发
{
    //    ui->label->setText("女神女神，再给我一次机会吧~");

        // 如果女神点击了这个按钮，就把这个按钮挪走
        // 可以通过生成随机数的方式，来确定按钮的新位置

        // 先获取到当前程序窗口的尺寸
        int width = this->geometry().width();    // this是Widget，即main函数中的子对象
        int height = this->geometry().height(); // 拿到高度

        // 重新生成按钮的位置 --> rand函数使用之前要设置随机种子，并非是真的随机
        int x = rand() % width;
        int y = rand() % height;
    //     ui->pushButton_reject->setGeometry(rect.x(),rect.y(),rect.width(),rect.height());
        ui->pushButton_reject->move(x,y);
}

// 也可以做到，鼠标不点击，只要挪到按钮上，就会让按钮移动（需要使用到Qt中的事件机制）
