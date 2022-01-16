/*
作用：作为显示当前房间预订状态的界面
作者：梁田
创建时间：2021/7/17
*/

#ifndef ROOMSTATUS_H
#define ROOMSTATUS_H

#include <QWidget>

namespace Ui {
class RoomStatus;
}

class RoomStatus : public QWidget
{
    Q_OBJECT

public:
    explicit RoomStatus(QWidget *parent = nullptr);
    ~RoomStatus();

private:
    Ui::RoomStatus *ui;
};

#endif // ROOMSTATUS_H
