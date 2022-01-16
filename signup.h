/*
作用：作为管理员账户的注册界面的头文件
作者：梁田
创建时间：2021/7/17
*/

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_signBtn_clicked();

    void on_cancelBtn_clicked();


private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
