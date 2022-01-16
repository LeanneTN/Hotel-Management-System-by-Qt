/*
描述：本源码用于对订单页面的控制，实现对酒店房间的提前预定
作者：梁田
创建时间：2021/7/14
*/

#include "reservelist.h"
#include "ui_reservelist.h"
#include<QSqlQuery>
#include<QSql>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QDebug>


//构造函数，实现对ReserveList类的初始化
ReserveList::ReserveList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReserveList)
{
    ui->setupUi(this);

    //实现选择酒店房间类型种类后，之后的下拉框显示对应的房间号
    QSqlQueryModel *roomTypeModel = new QSqlQueryModel(this);
    roomTypeModel->setQuery("select name from hotelroom");
    ui->roomTypeComboBox->setModel(roomTypeModel);

    QSqlQueryModel *roomNumberModel = new QSqlQueryModel(this);
    roomNumberModel->setQuery("select roomNumber from eachroom");

    ui->roomNumberComboBox->setModel(roomNumberModel);
}

//析构函数
ReserveList::~ReserveList()
{
    delete ui;
}

//用于实现程序在点击book按钮之后进行的对录入数据的上传操作
void ReserveList::on_pushButton_clicked()
{
    QString IDNumber = ui->lineEdit_2->text();
    QString name = ui->lineEdit->text();

    qDebug()<<IDNumber<<" "<<name;
    QSqlQuery query;

    ui->checkInDays->setEnabled(true);
    ui->pushButton->setEnabled(true);

    //判断是否房间是否被占用，有则不提交，无则提交
    query.exec(QString("select * from eachroom where roomNumber = '%1'").arg(ui->roomNumberComboBox->currentText()));
    query.first();
    int dayForCheck = query.value(8).toInt();
    int monthForCheck = query.value(7).toInt();
    int ifLast = query.value(5).toInt();

    //将时间控件中的时间信息分为字符数组
    QDate date = ui->dateEdit->date();
    QString s = date.toString("yyyy-MM-dd");
    QStringList dateList = s.split("-");

    //提取数组中的信息
    int year = dateList[0].toInt();
    int month = dateList[1].toInt();
    int day = dateList[2].toInt();
    int lastDay = query.value(9).toInt();

    //检测预定期间内房间是否会被占用，会则报错，不会则将时间按年月日分开存放，将其他数据一并录取
    if(ifLast==0){
        if(day - lastDay < dayForCheck){
            QMessageBox::information(this, tr("warning"),tr("this room is not avaliable"));
            return;
        }
    }

    else{

        //将相关信息录入数据库
        query.exec(QString("update eachroom set name ='%1' , IDNumber = '%2' where roomNumber = '%3'").
                   arg(name).arg(IDNumber).
                   arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set sell = '1', last='0' where roomNumber = '%1'").
                   arg(ui->roomNumberComboBox->currentText()));

        int a = ui->checkInDays->text().toInt();

        QString st = ui->roomNumberComboBox->currentText();

        query.exec(QString("update eachroom set lastDay='%1' where roomNumber= '%2'").arg(a).arg(st));

        query.exec(QString("update eachroom set year = '%1' where roomNumber = '%2'").arg(year).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set month = '%1' where roomNumber = '%2'").arg(month).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set day = '%1' where roomNumber = '%2'").arg(day).arg(ui->roomNumberComboBox->currentText()));

        query.exec(QString("update eachroom set clientName = '%1' where roomNumber ='%2'").arg(name).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set IDNumber = '%1' where roomNumber ='%2'").arg(IDNumber).arg(ui->roomNumberComboBox->currentText()));

        //给出录入成功的反馈
        QMessageBox::information(this, tr("success"), tr("room is checked in successfully!"));
    }
}

//实现在改变房间规格之后获得参数并改变后面的下拉列表中的选项
void ReserveList::on_roomTypeComboBox_currentIndexChanged(const QString &arg1){
    if(arg1=="房间规格"){
        on_cancel_clicked();
    }
    else{
        ui->roomNumberComboBox->setEnabled(true);
        QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(QString("select roomNumber from eachroom where roomType='%1'").arg(arg1));
        ui->roomNumberComboBox->setModel(model);
        ui->cancel->setEnabled(true);
    }
}

//实现在点击取消键之后对表单内容的清空
void ReserveList::on_cancel_clicked()
{
    ui->roomTypeComboBox->setCurrentIndex(0);
    ui->roomNumberComboBox->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

//实现选择所要的房间并将房号准备提交，同时改变房间的状态
void ReserveList::on_roomNumberComboBox_currentIndexChanged(const QString &arg1){
    ui->checkInDays->setValue(0);

    QSqlQuery query;
    query.first();
    query.exec("select * from eachroom");
    query.next();
    int ifLast = query.value(5).toInt();

    int day = query.value(8).toInt();
}
