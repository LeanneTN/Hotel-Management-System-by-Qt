/*
作用：这是check in system的头文件
作者：梁田
创建时间：2021/7/12
*/

#ifndef CHECKINSYSTEM_H
#define CHECKINSYSTEM_H

#include <QWidget>
#include<QMap>
#include<QDateEdit>
#include<QStyleOption>
#include<QPainter>

namespace Ui {
class CheckInSystem;
}

class CheckInSystem : public QWidget
{
    Q_OBJECT

public:
    explicit CheckInSystem(QWidget *parent = nullptr);
    ~CheckInSystem();


private slots:
    //void on_pushButton_clicked(bool checked);
    void on_roomTypeComboBox_currentIndexChanged(const QString &arg1);
    void on_roomNumberComboBox_currentIndexChanged(const QString &arg1);

    void on_cancel_clicked();

    //void on_resetBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::CheckInSystem *ui;
    //声明日期的调节框
    QDateEdit *dateEdit;

    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // CHECKINSYSTEM_H
