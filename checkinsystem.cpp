/*
作用：本源代码是对前台的顾客信息进行录入并开房的界面实现
作者：梁田
创建日期：2021/7/12
*/


#include "checkinsystem.h"
#include "ui_checkinsystem.h"
#include<QSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QSplitter>
#include<QTimer>
#include<QDateEdit>
#include<QCalendarWidget>
#include<QListView>
#include<QMessageBox>
#include<QDebug>
#include<QStringList>

CheckInSystem::CheckInSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckInSystem)
{
    ui->setupUi(this);

    //定义好相应的model，以便于后面对选择相应的房间规格后，在后面的下拉列表中展示相应房间的操作
    QSqlQueryModel *roomTypeModel = new QSqlQueryModel(this);
    roomTypeModel->setQuery("select name from hotelroom");
    ui->roomTypeComboBox->setModel(roomTypeModel);

    QSqlQueryModel *roomNumberModel = new QSqlQueryModel(this);
    roomNumberModel->setQuery("select roomNumber from eachroom");

    ui->roomNumberComboBox->setModel(roomNumberModel);


}

//析构函数
CheckInSystem::~CheckInSystem()
{
    delete ui;
}

//实现在check in按钮按下之后程序对相关信息的提交
void CheckInSystem::on_pushButton_clicked()
{
    QString IDNumber = ui->lineEdit_2->text();
    QString name = ui->lineEdit->text();

    //    qDebug()<<IDNumber<<" "<<name; 用于测试读入是否正常的一段语句
    QSqlQuery query;

    int a = ui->checkInDays->text().toInt();

    QString st = ui->roomNumberComboBox->currentText();


    //    query.exec(QString("update eachroom set year = '%1' where roomNumber = '%2'").arg(100).arg(ui->roomNumberComboBox->currentText()));

    //读取当前的时间，并将时间分割为年、月、日的字符串并存入表中，以便于后面的与预订房间之间的时间进行运算
    ui->dateEdit = new QDateEdit(QDate::currentDate());
    QDate date = ui->dateEdit->date();
    QString s = date.toString("yyyy-MM-dd");
    QStringList dateList = s.split("-");


    int year = dateList[0].toInt();
    int month = dateList[1].toInt();
    int day = dateList[2].toInt();

    query.exec(QString("select last from eachroom where roomNumber = '%1'").arg(ui->roomNumberComboBox->currentText()));
    query.first();
    int ifLast = query.value(0).toInt();

    //如果房间确实是处于空闲状态的，就会将当日的日期实时上传到数据库中，并上传其他信息，完成开房
    if(ifLast!=0){
        query.exec(QString("update eachroom set name ='%1' , IDNumber = '%2' where roomNumber = '%3'").
                   arg(name).arg(IDNumber).
                   arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set sell = '1', last='0' where roomNumber = '%1'").
                   arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set lastDay='%1' where roomNumber= '%2'").arg(a).arg(st));

        query.exec(QString("update eachroom set year = '%1' where roomNumber = '%2'").arg(year).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set month = '%1' where roomNumber = '%2'").arg(month).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set day = '%1' where roomNumber = '%2'").arg(day).arg(ui->roomNumberComboBox->currentText()));

        query.exec(QString("update eachroom set clientName = '%1' where roomNumber ='%2'").arg(name).arg(ui->roomNumberComboBox->currentText()));
        query.exec(QString("update eachroom set IDNumber = '%1' where roomNumber ='%2'").arg(IDNumber).arg(ui->roomNumberComboBox->currentText()));

        //    query.exec(QString("update eachroom set day='%1', month='%2', day = '%3 where roomNumber = '%4'").arg(day).arg(month).arg(year)
        //               .arg(ui->roomNumberComboBox->currentText()));

        int lastDay = ui->checkInDays->text().toInt();

        query.exec(QString("update eachroom set lastDay ='%1' where roomNumber = '%2'").arg(lastDay).arg(ui->roomNumberComboBox->currentText()));
        ui->roomTypeComboBox->setCurrentIndex(0);
        ui->roomNumberComboBox->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        //设置对应情况下的消息弹出
        QMessageBox::information(this, tr("success"), tr("room is checked in successfully!"));
    }
    //房间不为空的情况下弹出消息，并清空房间下拉框中的当前消息
    else {
        QMessageBox::information(this, tr("warning"), tr("this room is not avaliable"));
        ui->roomTypeComboBox->setCurrentIndex(0);
        ui->roomNumberComboBox->clear();
    }
}


//实现对房间种类的选择并使得下面的房间号做出对应的显示
void CheckInSystem::on_roomTypeComboBox_currentIndexChanged(const QString &arg1){
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

//实现在点击取消键之后对表单的清空
void CheckInSystem::on_cancel_clicked()
{
    ui->roomTypeComboBox->setCurrentIndex(0);
    ui->roomNumberComboBox->clear();
}

//用以在选择到相应房间时显示是否被占用以及后续的创建
void CheckInSystem::on_roomNumberComboBox_currentIndexChanged(const QString &arg1){
    ui->checkInDays->setValue(0);

    QSqlQuery query;
    query.first();
    //query.exec(QString("select last from eachroom='%1' and roomType= '%2'").arg(arg1).arg(ui->roomNumberComboBox->currentText()));
    query.exec("select * from eachroom");
    query.next();
    int ifLast = query.value(5).toInt();
    if(ifLast == 0){
        //QMessageBox::information(this, tr("Attention"), tr("this room is occupied"), QMessageBox::Ok);
    }
    else {
        ui->checkInDays->setEnabled(true);
        ui->pushButton->setEnabled(true);
    }

}
