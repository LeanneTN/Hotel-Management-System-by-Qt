/*
作用：本源代码实现的是管理系统的主界面，用于连接其他的四个窗口以及帮助文档
          同时有RESET按键，可以在需要的时候重新初始化数据库
作者：梁田
创建时间：2021/7/8
*/

#include "widget.h"
#include "ui_widget.h"
#include<QPalette>
#include<QWidget>
#include<QApplication>
#include<QDesktopWidget>
#include"checkinsystem.h"
#include"checkoutsystem.h"
#include"reservelist.h"
#include"searchlist.h"
#include"help.h"
#include<QSql>
#include<QSqlQuery>
#include<QMessageBox>
#include<roomstatus.h>
#include<otherservice.h>
#include<backstage.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //改变主界面欢迎字体的颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::blue);
    ui->label->setPalette(pa);

}

Widget::~Widget()
{
    delete ui;
}

//实现在点击check in按钮之后打开前台界面的功能
void Widget::on_checkInBtn_clicked()
{
    //使前台界面出现
    CheckInSystem *checkInSystem = new CheckInSystem();
    checkInSystem->show();

    //使当前房间状态的表格界面出现并改变roomStatus表格的位置
    RoomStatus *roomStatus = new RoomStatus();
    roomStatus->show();
    move((QApplication::desktop()->width() - checkInSystem->width())/3, (QApplication::desktop()->height() - checkInSystem->height())/3);
}

//实现在点击reserve按钮之后打开预订界面的功能
void Widget::on_reserveListBtn_clicked()
{
    //使预订界面出现
    ReserveList *reserveList = new ReserveList();
    reserveList->show();

    //使roomStatus表格出现并改变其位置
    RoomStatus *roomStatus = new RoomStatus();
    roomStatus->show();
    move((QApplication::desktop()->width()- reserveList->width())/3, (QApplication::desktop()->height() - reserveList->height())/3);
}

//实现在点击check out按钮之后打开退房界面的功能
void Widget::on_checkOutBtn_clicked()
{
    CheckOutSystem *checkOutSystem = new CheckOutSystem();
    checkOutSystem->show();
    move((QApplication::desktop()->width() - checkOutSystem->width())/3, (QApplication::desktop()->height() - checkOutSystem->height())/3);
}

//实现在点击search按钮之后打开搜索页面的功能
void Widget::on_searchBtn_clicked()
{
     SearchList *searchList = new SearchList();
     searchList->show();
     move((QApplication::desktop()->width() - searchList->width())/3, (QApplication::desktop()->height() - searchList->height())/3);
}


//实现在点击reset按钮后的对数据库的初始化
void Widget::on_resetBtn_clicked()
{
    QSqlQuery query;
    //将eachroom、food、meetingroom等表恢复到初始状态

    query.exec(QString("update eachroom set sell = '%1'").arg(0));
    query.exec(QString("update eachroom set last = '%1'").arg(1));
    query.exec(QString("update eachroom set year = '%1'").arg(0));
    query.exec(QString("update eachroom set month = '%1'").arg(0));
    query.exec(QString("update eachroom set day = '%1'").arg(0));
    query.exec(QString("update eachroom set clientName = '%1'").arg("name"));
    query.exec(QString("update eachroom set IDNumber = '%1'").arg("id"));
    query.exec(QString("update eachroom set lastDay = '%1'").arg(0));
    query.exec(QString("update eachroom set otherServices = '%1'").arg(0));

    query.exec(QString("update food set friedRice = '%1'").arg(0));
    query.exec(QString("update food set Chinesefood = '%1'").arg(0));
    query.exec(QString("update food set stake = '%1'").arg(0));
    query.exec(QString("update food set seafood = '%1'").arg(0));
    query.exec(QString("update food set breakfast = '%1'").arg(0));
    query.exec(QString("update food set fruit = '%1'").arg(0));
    query.exec(QString("update food set wine = '%1'").arg(0));
    query.exec(QString("update food set iceJuice = '%1'").arg(0));
    query.exec(QString("update meetingroom set smallMR = '%1'").arg(0));
    query.exec(QString("update meetingroom set midMR = '%1'").arg(0));
    query.exec(QString("update meetingroom set largeMR = '%1'").arg(0));
    query.exec(QString("update entertainments set pool = '%1'").arg(0));
    query.exec(QString("update entertainments set swim = '%1'").arg(0));
    query.exec(QString("update entertainments set massage = '%1'").arg(0));
    query.exec(QString("update housekeep set hygiene = '%1'").arg(0));
    query.exec(QString("update housekeep set makeBed = '%1'").arg(0));
    query.exec(QString("update housekeep set cleanUp = '%1'").arg(0));


    query.exec("delete from room101");
    query.exec("delete from room102");
    query.exec("delete from room103");
    query.exec("delete from room104");
    query.exec("delete from room105");
    query.exec("delete from room106");
    query.exec("delete from room107");
    query.exec("delete from room108");
    query.exec("delete from room201");
    query.exec("delete from room202");
    query.exec("delete from room203");
    query.exec("delete from room204");
    query.exec("delete from room205");
    query.exec("delete from room206");
    query.exec("delete from room207");
    query.exec("delete from room208");
    query.exec("delete from room1001");
    query.exec("delete from room1002");
    query.exec("delete from room1003");

    query.exec(("delete from guest"));

    //选取其中一个指标year，若有year初始化失败即大于0，则报错
    int year = query.exec(QString("select year from eachroom where year > '0'"));
    if(query.value(0).toInt()!=0){
        QMessageBox::information(this, tr("Error"), tr("reset failed"));
    }
    else {
        QMessageBox::information(this, tr("Attention"), tr("reset success!"));
    }

}

//实现点击按钮之后打开帮助界面的功能
void Widget::on_helpBtn_clicked()
{
    Help *help = new Help();
    help->setWindowTitle("Help");
    help->show();
}

//实现点击other service按钮之后打开界面进行点单的功能
void Widget::on_otherServiceBtn_clicked()
{
     OtherService *otherservice = new OtherService();
     otherservice->setWindowTitle("other services");
     otherservice->show();
}


//实现点击back on stage按钮之后打开后台查看所有订单的功能
void Widget::on_backStageBtn_clicked()
{
    BackStage *backStage = new BackStage();
    backStage->setWindowTitle("Back Stage");
    backStage->show();
}
