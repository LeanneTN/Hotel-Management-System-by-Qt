/*
作用：作为旅行助手的交互界面
作者：梁田
创建时间：2021/7/19
*/

#ifndef TRAVELTIP_H
#define TRAVELTIP_H

#include <QWidget>
#include<QStyleOption>
#include<QPaintEvent>
#include<QPainter>

namespace Ui {
class TravelTip;
}

class TravelTip : public QWidget
{
    Q_OBJECT

public:
    explicit TravelTip(QWidget *parent = nullptr);
    ~TravelTip();

private:
    Ui::TravelTip *ui;
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // TRAVELTIP_H
