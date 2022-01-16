/*
作用：作为显示地图的交互界面
作者：梁田
创建日期：2021/7/19
*/
#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include<QPaintEvent>
#include<QStyleOption>
#include<QPainter>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private:
    Ui::Map *ui;

    //重载函数，用于显示背景图片
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // MAP_H
