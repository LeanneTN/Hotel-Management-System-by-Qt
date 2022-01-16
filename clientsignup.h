/*
作用：作为顾客申请账号的界面
作者:梁田
创建时间：2021/7/19
*/

#ifndef CLIENTSIGNUP_H
#define CLIENTSIGNUP_H

#include <QWidget>

namespace Ui {
class ClientSignUp;
}

class ClientSignUp : public QWidget
{
    Q_OBJECT

public:
    explicit ClientSignUp(QWidget *parent = nullptr);
    ~ClientSignUp();

private slots:
    void on_create_clicked();

private:
    Ui::ClientSignUp *ui;
};

#endif // CLIENTSIGNUP_H
