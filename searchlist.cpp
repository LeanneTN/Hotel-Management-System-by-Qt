/*
作用：实现在只使用名字、房间号或身份证号的情况下对顾客的信息搜索
作者：梁田
创建时间：2021/7/15
*/
#include "searchlist.h"
#include "ui_searchlist.h"
#include<QApplication>
#include<QDesktopWidget>
#include<QSqlQuery>
#include<QMessageBox>

SearchList::SearchList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchList)
{
    ui->setupUi(this);
}

SearchList::~SearchList()
{
    delete ui;
}

//实现在前面的文本框中输入名字之后，在按下按钮时按名字对顾客进行检索（当前暂未对同名顾客查找情况进行测试）
void SearchList::on_searchByNameBtn_clicked()
{
    QSqlQuery query;
    //获取输入的名字
    QString name = ui->nameSearching->text();

    //将相应的信息储存
    query.exec(QString("select * from eachroom where clientName = '%1'").arg(name));
    query.first();
    QString roomNumber = query.value(1).toString();
    QString year = query.value(6).toString();
    QString month = query.value(7).toString();
    QString day = query.value(8).toString();
    QString lastDay = query.value(9).toString();
    QString IDNumber = query.value(11).toString();
    query.exec();

    //利用查看其中的关键字是否存在来显示相应的查找是否存在，在这里选择的是使用year这一较为稳定的变量，下面的槽函数相同
    //若没有相应的检索结果，程序会给出错误窗口
    //查询到相应结果之后，程序会在后面文本框中展示出除名字外的顾客其他信息
    if(year ==""){
        QMessageBox::information(this, tr("Error"), tr("this name is not checked in before"));
    }

    //创建一个储存相关信息的字符串
    QString information = "IDNumber: "+ IDNumber + " room number: "+
            roomNumber + " check in date: " + year + "/" + month +
            "/" + day + "/" + " check in days: " + lastDay;

    //打印字符串
    ui->searchByName->setText(information);

}



//实现只按身份证进行的查找，作用方式与上同
void SearchList::on_searchByIDBtn_clicked()
{
    QSqlQuery query;
    QString IDNumber = ui->lineEdit->text();

    query.exec(QString("select * from eachroom where IDNumber = '%1'").arg(IDNumber));
    query.first();
    QString roomNumber = query.value(1).toString();
    QString year = query.value(6).toString();
    QString month = query.value(7).toString();
    QString day = query.value(8).toString();
    QString lastDay = query.value(9).toString();
    QString name = query.value(10).toString();

    if(year ==""){
        QMessageBox::information(this, tr("Error"), tr("this IDNumber is not checked in before"));
    }


    QString information = "name: "+ name + " room number: "+
            roomNumber + " check in date: " + year + "/" + month +
            "/" + day + "/" + " check in days: " + lastDay;

    ui->searchByID->setText(information);
}

//实现只按房间号的顾客查找，作用方式与上同
void SearchList::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString roomNumber = ui->lineEdit_2->text();

    query.exec(QString("select * from eachroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    QString name = query.value(10).toString();
    QString year = query.value(6).toString();
    QString month = query.value(7).toString();
    QString day = query.value(8).toString();
    QString lastDay = query.value(9).toString();
    QString IDNumber = query.value(11).toString();

    if(year ==""){
        QMessageBox::information(this, tr("Error"), tr("this room hasn't been occupied"));
    }


    QString information = "name: "+ name + " IDNumber: "+
            IDNumber + " check in date: " + year + "/" + month +
            "/" + day + "/" + " check in days: " + lastDay;

    ui->searchByRoomNumber->setText(information);
}
