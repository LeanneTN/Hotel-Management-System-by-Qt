/*
作用：作为登录界面的实现文件
作者：梁田
创建时间：2021/7/18
*/
#include "register.h"
#include "ui_register.h"
#include"widget.h"
#include<QSql>
#include<QSqlQuery>
#include<QLineEdit>
#include<QMessageBox>
#include<QDebug>
#include"signup.h"
#include"clienthomepage.h"
#include"clientsignup.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowTitle("Sign In");
}

Register::~Register()
{
    delete ui;
}

//完成按下管理员登录后的显示与页面切换
void Register::on_pushButton_clicked()
{
    QSqlQuery query;

    //获取输入的用户名和密码
    QString user = ui->userName->text();
    QString password = ui->passwordLine->text();

    //从数据库中取得对应的用户名的密码
    query.exec(QString("select password from address where user = '%1'").arg(user));
    query.first();
    QString pw = query.value(0).toString();

    //密码不对或为空则报错
    if(pw!=password||pw==nullptr){
        QMessageBox::information(this, tr("warning"), tr("wrong passwoord or account is not exists"));
    }
    else{
        //打开首页
        Widget *w = new Widget;
        w->show();

        close();
    }
}

//打开管理员注册页面
void Register::on_pushButton_2_clicked()
{
    SignUp *s = new SignUp();
    s->show();
}

//完成点击顾客登录后的操作
void Register::on_pushButton_3_clicked()
{
    QSqlQuery query;
    //获取输入的信息
    QString user = ui->userName->text();
    QString password = ui->passwordLine->text();

    //通过用户名找密码
    query.exec(QString("select password from guest where user = '%1'").arg(user));
    query.first();
    QString pw = query.value(0).toString();

    //密码不匹配或为空则报错
    if(pw!=password||pw ==nullptr){
        QMessageBox::information(this, tr("warning"), tr("wrong passwoord or account is not exists"));
    }
    else{
        ClientHomePage *c = new ClientHomePage;
        c->show();

        close();
    }

}

//打开顾客注册界面
void Register::on_pushButton_4_clicked()
{
    ClientSignUp *s =new ClientSignUp;
    s->show();
}
