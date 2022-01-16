/*
作用：这里是reserveList的头文件
作者：梁田
创建时间：2021/7/14
*/


#ifndef RESERVELIST_H
#define RESERVELIST_H

#include <QWidget>
#include<QDateEdit>
#include<QPainter>
#include<QStyleOption>


namespace Ui {
class ReserveList;
}

class ReserveList : public QWidget
{
    Q_OBJECT

public:
    explicit ReserveList(QWidget *parent = nullptr);
    ~ReserveList();

private:
    Ui::ReserveList *ui;
    QDateEdit *dateEdit;

    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

private slots:
    void on_roomTypeComboBox_currentIndexChanged(const QString &arg1);
    void on_roomNumberComboBox_currentIndexChanged(const QString &arg1);

    void on_cancel_clicked();
    void on_pushButton_clicked();
};

#endif // RESERVELIST_H
