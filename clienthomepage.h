/*
作用：作为顾客登录后的首页，作为其他功能的入口
作者：梁田
创建时间：2021/7/19
*/

#ifndef CLIENTHOMEPAGE_H
#define CLIENTHOMEPAGE_H

#include <QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QStyleOption>
#include<QMediaPlayer>
#include<QMediaPlaylist>

namespace Ui {
class ClientHomePage;
}

class ClientHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit ClientHomePage(QWidget *parent = nullptr);
    ~ClientHomePage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ClientHomePage *ui;

    QMediaPlayer *player;

    //重载paintEvent函数，用于显示背景图片
    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // CLIENTHOMEPAGE_H
