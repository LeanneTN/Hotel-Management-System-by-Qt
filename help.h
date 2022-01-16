/*
作用：这里是帮助文档的头文件
作者：梁田
创建时间：2021/7/16
*/

#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QStyleOption>

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;

    //作为显示背景图片的重载函数
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // HELP_H
