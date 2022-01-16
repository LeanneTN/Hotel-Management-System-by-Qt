/*
作用：本源码用于实现用户注册功能
作者：梁田
创建时间：2021/7/17
*/
#include "signup.h"
#include "ui_signup.h"
#include<QSqlQuery>
#include<QLineEdit>
#include<QString>
#include<QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    setWindowTitle("Sign Up");
}

SignUp::~SignUp()
{
    delete ui;
}


//实现当按下注册按钮之后对数据表的遍历查找是否此账户之前注册过
//对未注册过的账号将其插入数据库
void SignUp::on_signBtn_clicked()
{
    QSqlQuery query;

    QString user = ui->userName->text();
    query.exec(QString("select password from address where user = '%1'").arg(user));
    query.first();

    QString pw = query.value(0).toString();
    //检测账户是否存在
    if(pw!=nullptr){
        QMessageBox::information(this, tr("Attention"), tr("account exists"));
    }
    else {
        QString pass = ui->password->text();
        //插入用户名和密码的操作
        query.exec(QString("insert into address values('%1', '%2')").arg(user).arg(pass));

        QMessageBox::information(this, tr("Attention"), tr("account sign up successfully"));
    }

}

//实现点击取消按钮之后对表单的清空
void SignUp::on_cancelBtn_clicked()
{
    ui->userName->clear();
    ui->password->clear();
}


