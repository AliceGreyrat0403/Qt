#include "mylabel.h"
#include <iostream>

#include <QDebug>

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    // std::cout << "MyLabel被销毁！" << std::endl;
    qDebug() << "MyLabel被销毁！";
}
