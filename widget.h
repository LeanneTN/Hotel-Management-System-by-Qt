/*
作用：这里是主界面的头文件
作者：梁田
创建时间：2021/7/8
*/


#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QStyleOption>
#include<QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写paintEvent代码以在widget控件中通过qss显示相应背景，其他地方用此函数起到相同作用
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

private slots:
    void on_checkInBtn_clicked();

    void on_reserveListBtn_clicked();

    void on_checkOutBtn_clicked();

    void on_searchBtn_clicked();


    void on_resetBtn_clicked();

    void on_helpBtn_clicked();

    void on_otherServiceBtn_clicked();

    void on_backStageBtn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
