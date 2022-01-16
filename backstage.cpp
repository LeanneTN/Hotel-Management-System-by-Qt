/*
作用：作为前台查看菜单的窗口，显示顾客本轮点单的细节并选择本轮点单是否完成
作者：梁田
创建时间2021/7/17
*/

#include "backstage.h"
#include "ui_backstage.h"
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>

BackStage::BackStage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackStage)
{
    ui->setupUi(this);
}

BackStage::~BackStage()
{
    delete ui;
}

//每个房间一个用于储存订单的表

void BackStage::on_checkOrder_clicked()
{
    QSqlQuery query;

    QString roomNumber = ui->lineEdit->text();

    //记录每一个服务出现的次数，以便在后面进行判断
    //当值大于0的时候，服务会在发票打印的时候出现，并在后面记录数量
    query.exec(QString("select * from food where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int friedRice = query.value(1).toInt();
    int Chinesefood = query.value(2).toInt();
    int stake = query.value(3).toInt();
    int seafood = query.value(4).toInt();
    int breakfast = query.value(5).toInt();
    int fruit = query.value(6).toInt();
    int wine = query.value(7).toInt();
    int juice = query.value(8).toInt();

    query.exec(QString("select * from meetingroom where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int smallMR = query.value(1).toInt();
    int midMR = query.value(2).toInt();
    int largeMR = query.value(3).toInt();

    query.exec(QString("select * from entertainments where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int pool = query.value(1).toInt();
    int swim = query.value(2).toInt();
    int massage = query.value(3).toInt();

    query.exec(QString("select * from housekeep where roomNumber = '%1'").arg(roomNumber));
    query.first();
    int cleanUp = query.value(1).toInt();
    int hygiene = query.value(2).toInt();
    int makeBed = query.value(3).toInt();

    //发票打印之前准备字符串语句
    QString sFriedRice = "fried rice: "+QString::number(friedRice);
    QString sChinesefood = "Chinese food: " +QString::number(Chinesefood);
    QString sStake = "stake: " + QString::number(stake);
    QString sSeafood = "seafood: " + QString::number(seafood);
    QString sBreakfast = "breafast: "+ QString::number(breakfast);
    QString sFruit = "fruit: " + QString::number(fruit);
    QString sWine = "wine: " + QString::number(wine);
    QString sJuice = "juice: " + QString::number(juice);
    QString sSmallMR = "small meeting room: " + QString::number(smallMR);
    QString sMidMR = "middle meeting room: " + QString::number(midMR);
    QString sLargeMR = "largr meeting room: " + QString::number(largeMR);
    QString sPool = "pool: " + QString::number(pool);
    QString sSwim = "swim & SPA: " + QString::number(swim);
    QString sMassage  = "massage: " + QString::number(massage);
    QString sCleanUp = "clean up: "+ QString::number(cleanUp);
    QString sHygiene = "hygiene products: " + QString::number(hygiene);
    QString sMakeBed = "make bed: "+ QString::number(makeBed);

    QString information; //用于打印的字符串
    //判断字符串是否符合打印条件，若符合则接上字符串，同时在每一个字符串后打上换行，方便前台观看
    if(friedRice>0){
        information+=sFriedRice+"\n";
    }
    if(Chinesefood>0){
        information+=sChinesefood+"\n";
    }
    if(stake>0){
        information+=sStake+"\n";
    }
    if(seafood>0){
        information+=sSeafood+ "\n";
    }
    if(breakfast>0){
        information+=sBreakfast+ "\n";
    }
    if(fruit>0){
        information+=sFruit+"\n";
    }
    if(wine>0){
        information+=sWine + "\n";
    }
    if(juice>0){
        information+=sJuice + "\n";
    }
    if(smallMR>0){
        information+=sSmallMR+"\n";
    }
    if(midMR>0){
        information+=sMidMR+"\n";
    }
    if(largeMR>0){
        information+=sLargeMR+"\n";
    }
    if(pool>0){
        information+= sPool + "\n";
    }
    if(swim>0){
        information+= sSwim + "\n";
    }
    if(cleanUp>0){
        information+= sCleanUp + "\n";
    }
    if(hygiene>0){
        information+= sHygiene + "\n";
    }
    if(makeBed){
        information+= sMakeBed + "\n";
    }

    //文本框中打印信息
    ui->menu->setText(information);

}

//实现点击订单完成之后发生的注销本轮订单的操作
void BackStage::on_complete_clicked()
{
    QSqlQuery query;

    QString roomNumber = ui->lineEdit->text();
    //从文本中获取房间号之后把库中对应的数据恢复成最开始的样子

   query.exec(QString("update food set friedRice = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set Chinesefood = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set stake = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set seafood = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set breakfast = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set fruit = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set wine = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update food set iceJuice = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update meetingroom set smallMR = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update meetingroom set midMR = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update meetingroom set largeMR = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update entertainments set pool = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update entertainments set swim = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update entertainments set massage = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update housekeep set cleanUp = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update housekeep set hygiene = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));
   query.exec(QString("update housekeep set makeBed = '%1' where roomNumber = '%2'").arg(0).arg(roomNumber));

   ui->menu->clear();
   ui->lineEdit->clear();

   QMessageBox::information(this, tr("attention"),tr("this order is complete successfully"));

}
