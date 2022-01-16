/*
作用：本源码实现的是对顾客退房后的房间状态改变以及删除顾客相关信息的操作
作者：梁田
创建时间：2021/7/12
*/

#include "checkoutsystem.h"
#include "ui_checkoutsystem.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include<QComboBox>

//构造函数，实现对界面的创建以及下拉框数据的导入
CheckOutSystem::CheckOutSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckOutSystem)
{
    ui->setupUi(this);


}

CheckOutSystem::~CheckOutSystem()
{
    delete ui;
}

//实现按下check键之后对房间相关信息的检索
void CheckOutSystem::on_checkBtn_clicked()
{
    ui->nameLine->setEnabled(true);
    ui->nameLine->setReadOnly(false);
    ui->dayLine->setEnabled(true);
    ui->dayLine->setReadOnly(false);
    ui->moneyLine->setEnabled(true);
    ui->moneyLine->setReadOnly(false);

    QSqlQuery query;
    QString roomNumber = ui->roomNumber->text();
    qDebug()<<roomNumber;

    //取出名字、房间号、住宿天数等信息
    query.exec(QString("select * from eachroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int lastDay = query.value(9).toInt();
    QString day = query.value(9).toString();
    int pricePerDay = query.value(3).toInt();
    QString name = query.value(10).toString();

    //获取其他服务的费用
    query.exec(QString("select otherServices from eachroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int otherServices = query.value(0).toInt();

    int money = lastDay*pricePerDay + otherServices;
    QString totalMoney = QString::number(money);

    //在相应的位置显示上面获得的信息
    ui->dayLine->setText(day);
    ui->nameLine->setText(name);
    ui->moneyLine->setText(totalMoney);
    ui->moneyLine_2->setText(QString::number(otherServices));
}

//实现按下取消按钮之后对表单内容以及房间的清空与归位
void CheckOutSystem::on_cancel_clicked()
{
    ui->roomNumber->clear();
    ui->nameLine->clear();
    ui->moneyLine->clear();
    ui->moneyLine_2->clear();
    ui->dayLine->clear();

}

//实现在按下check out按钮之后程序对相应房间信息的初始化
void CheckOutSystem::on_checkOut_clicked()
{
    QSqlQuery query;

    QString roomNumber = ui->roomNumber->text();

    //实现在按下checkout按钮之后程序对eachroom表的初始化
    query.exec(QString("update eachroom set sell = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
    query.exec(QString("update eachroom set last = '%1' where roomNumber ='%2'").arg(1).arg(roomNumber));
    query.exec(QString("update eachroom set year = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
    query.exec(QString("update eachroom set month = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
    query.exec(QString("update eachroom set day = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
    query.exec(QString("update eachroom set clientName = '%1' where roomNumber = '%2'").arg("name").arg(roomNumber));
    query.exec(QString("update eachroom set IDNumber = '%1' where roomNumber = '%2'").arg("id").arg(roomNumber));
    query.exec(QString("update eachroom set lastDay = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
    query.exec(QString("update eachroom set otherServices = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));

    //删除住户创建的账户
    query.exec(QString("delete from guest where roomNumber = '%1'").arg(roomNumber));

    //检测是否成功退房并显示相应消息框
    query.exec(QString("select last from eachroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int last = query.value(0).toInt();
    if(last==1){
        QMessageBox::information(this, tr("tip"),tr("room is checked out successfully"));
    }
    else {
        QMessageBox::information(this, tr("warning"), tr("Error! please check the information again"));
    }
}
