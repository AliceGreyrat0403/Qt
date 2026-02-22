#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
//    void mySignal(const QString& text);
    void mySignal(int text);
//    void mySignal(const QString& text,const QString& text2); // （C++的基础）C++中形参的名字可以不写，写参数类型即可

public:
//public slots:   // slots可以省略
//    void handleMySignal(const QString& text);
//    void handleMySignal(const QString& text,const QString& text2);
    void handleMySignal(const QString& text);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
