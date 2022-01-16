/*
作用：作为顾客界面说明书的交互界面
作者：梁田
创建时间：2021/7/19
*/

#ifndef NOTICE_H
#define NOTICE_H

#include <QWidget>
#include<QPainter>
#include<QPaintEvent>
#include<QStyleOption>

namespace Ui {
class Notice;
}

class Notice : public QWidget
{
    Q_OBJECT

public:
    explicit Notice(QWidget *parent = nullptr);
    ~Notice();

private:
    Ui::Notice *ui;

    //作为重载函数显示背景图片
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // NOTICE_H
