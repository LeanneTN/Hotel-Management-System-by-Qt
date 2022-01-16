/*
作用：顾客的账号申请界面
作者：梁田
创建时间:2021/7/19
*/

#include "clientsignup.h"
#include "ui_clientsignup.h"
#include"connection.h"
#include<QSqlQuery>
#include<QString>
#include<QMessageBox>

ClientSignUp::ClientSignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientSignUp)
{
    ui->setupUi(this);
}

ClientSignUp::~ClientSignUp()
{
    delete ui;
}

//实现点击创建账户按钮之后的操作
void ClientSignUp::on_create_clicked()
{
    //从对应的文本框中获取信息
    QString name = ui->name->text();
    QString IDNumber = ui->IDNumber->text();
    QString roomNumber = ui->roomNumber->text();
    QString user = ui->username->text();
    QString pwd = ui->password->text();

    QSqlQuery query;
    //从数据库中获取对应房号的信息
    query.exec(QString("select * from guest where roomNumber = '%1'").arg(roomNumber));
    query.first();
    QString CName = query.value(3).toString();
    QString CIDNumber = query.value(4).toString();

    //检测房间是否已有账号
    if(CName!=nullptr){
        QMessageBox::information(this, tr("warning"), tr("this room owns an account"));
        return;
    }

    //核对输入的身份证号和姓名是否与系统中对应
    query.exec(QString("select * from eachroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    QString AName = query.value(10).toString();
    QString AID = query.value(11).toString();

    //不对应后报错
    if(AName != name|| AID != IDNumber){
        QMessageBox::information(this, tr("warning"), tr("information you write is not properate"));
        return;
    }

    //检测用户名是否被占用
    query.exec(QString("select pwd from guest where user = '%1'").arg(user));
    query.first();
    QString ptemp = query.value(0).toString();
    if(ptemp!=nullptr){
        QMessageBox::information(this, tr("warning"),tr("user name is occupied"));
        return;
    }

    query.exec(QString("insert into guest values('%1','%2','%3','%4','%5')").arg(user).arg(pwd).arg(roomNumber).arg(name).arg(IDNumber));

    query.exec(QString("select password from guest where user = '%1'").arg(user));
    query.first();
    ptemp = query.value(0).toString();
    if(ptemp!=nullptr&&ptemp==pwd){
        QMessageBox::information(this, tr("attention"),tr("account create successfully"));
        ui->name->clear();
        ui->password->clear();
        ui->IDNumber->clear();
        ui->username->clear();
        ui->roomNumber->clear();
    }
    //创建不成功则报错
    else {
        QMessageBox::information(this, tr("warning"), tr("account create fail"));
    }

}
