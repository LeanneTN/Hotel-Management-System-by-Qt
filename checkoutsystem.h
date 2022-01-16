/*
作用：这是check out system的头文件
作者：梁田
创建时间：2021/7/12
*/

#ifndef CHECKOUTSYSTEM_H
#define CHECKOUTSYSTEM_H

#include <QWidget>
#include<QStyleOption>
#include<QPainter>

namespace Ui {
class CheckOutSystem;
}

class CheckOutSystem : public QWidget
{
    Q_OBJECT

public:
    explicit CheckOutSystem(QWidget *parent = nullptr);
    ~CheckOutSystem();

private:
    Ui::CheckOutSystem *ui;

    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

private slots:
    //void on_roomNumberGetterComboBox_currentIndexChanged(const QString &arg1);
    //void on_pushButton_clicked();
    void on_checkBtn_clicked();
    void on_cancel_clicked();
    void on_checkOut_clicked();
};

#endif // CHECKOUTSYSTEM_H
