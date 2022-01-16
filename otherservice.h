/*
作用：实现菜单栏中各项功能的otherServices的头文件
作者：梁田
创建时间：2021/7/17
*/

#ifndef OTHERSERVICE_H
#define OTHERSERVICE_H

#include <QWidget>

namespace Ui {
class OtherService;
}

class OtherService : public QWidget
{
    Q_OBJECT

public:
    explicit OtherService(QWidget *parent = nullptr);
    ~OtherService();

private slots:


    void on_pushButton_clicked();

private:
    Ui::OtherService *ui;
};

#endif // OTHERSERVICE_H
