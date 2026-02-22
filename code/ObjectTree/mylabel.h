#ifndef MYLABEL_H
#define MYLABEL_H

#include<QLabel>

class MyLabel : public QLabel
{
public:
    // 构造函数使用带QWidget*版本的
    // 这样才能确保我们的对象可以加到对象树上。
    MyLabel(QWidget* parent);
    ~MyLabel();
};

#endif // MYLABEL_H
