/*
作用：实现顾客对客房服务的点单、娱乐设施的付费等项目，并将开销传入房费的数据库中，同时
          将相关信息放在新的一个表中，后续可以在前台进行确认
创建时间：2021/7/17
作者：梁田
*/
#include "otherservice.h"
#include "ui_otherservice.h"
#include<QSqlQuery>
#include<QString>
#include<QMessageBox>

OtherService::OtherService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtherService)
{
    ui->setupUi(this);
}

OtherService::~OtherService()
{
    delete ui;
}

//实现当按下confirm键确认点单之后对数据的上传
//函数会将所有点单的信息传入对应房间的表中，同时将费用传到库中，在后续添加在房费上
void OtherService::on_pushButton_clicked()
{
    //获取菜单上每一个spinBox的数字并计算费用
    int friedRice = ui->friedRice->text().toInt();
    int Chinesefood = ui->CHineseFood->text().toInt();
    int stake = ui->stake->text().toInt();
    int seafood = ui->seaFood->text().toInt();
    int breakfast = ui->breakfast->text().toInt();
    int fruit = ui->fruit->text().toInt();
    int wine = ui->rum->text().toInt();
    int iceJuice = ui->juice->text().toInt();
    int foodTotal = friedRice+Chinesefood+stake+seafood+breakfast+
            fruit+wine+iceJuice;
    int foodPrice = friedRice*20+Chinesefood*40+stake*50+seafood*70+
            breakfast*30+fruit*40+wine*60+iceJuice*15;

    int small = ui->smallMr->text().toInt();
    int middle = ui->middleMr->text().toInt();
    int large =ui->largeMid->text().toInt();

    int meetingRooms = small+middle+large;
    int meetingRoomsPrice = small*800+middle*1500+large*3000;

    int pool = ui->pool->text().toInt();
    int swim = ui->swim->text().toInt();
    int massage = ui->massage->text().toInt();

    int entertainment = pool + swim + massage;
    int entertainmentPrice = pool*120+swim*300+massage*180;

    int clean = ui->cleanUp->text().toInt();
    int hygiene = ui->hygiene->text().toInt();
    int makeBed = ui->makeBed->text().toInt();

    int housekeep = clean + hygiene + makeBed;
    int housekeepPrice = clean*15+hygiene*15+makeBed*8;

    QString roomNumber = "room"+ui->roomNumber->text();
    QString roomNumerWithNoRoom = ui->roomNumber->text();

    QSqlQuery query;

    //将所有费用相加并与数据库之前的数据相加，以计算重复点单的顾客的消费
    query.exec(QString("select otherServices from eachroom where roomNumber = '%1'").arg(roomNumerWithNoRoom));
    query.first();
    int formerMoney = query.value(0).toInt();

    QString totalMoney = QString::number(foodPrice+meetingRoomsPrice+entertainmentPrice+housekeepPrice + formerMoney);

    //将各数字转为字符串
    QString food = QString::number(foodTotal);
    QString meetingRoom = QString::number(meetingRooms);
    QString entertainments = QString::number(entertainment);
    QString houseKeep = QString::number(housekeep);


    //将信息传入对应的数据库中
    query.exec(QString("update eachroom set otherServices = '%1' where roomNumber = '%2'").arg(totalMoney).arg(roomNumerWithNoRoom));

    query.exec(QString("insert into '%1'(foodService) values('%2')").arg(roomNumber).arg(food));
    query.exec(QString("update '%1' set meetingRoomBooking ='%2' where foodService = '%3'").arg(roomNumber).arg(meetingRoom).arg(food));
    query.exec(QString("update '%1' set entertainment = '%2' where foodService = '%3'").arg(roomNumber).arg(entertainments).arg(food));
    query.exec(QString("update '%1' set houseKeeping= '%2' where foodService = '%3'").arg(roomNumber).arg(houseKeep).arg(food));
    query.exec(QString("update '%1' set price ='%2' where foodService = '%3'").arg(roomNumber).arg(totalMoney).arg(food));


    query.exec(QString("update food set friedRice = '%1' where roomNumber = '%2'").arg(ui->friedRice->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set Chinesefood = '%1' where roomNumber = '%2'").arg(ui->CHineseFood->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set stake = '%1' where roomNumber = '%2'").arg(ui->stake->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set seafood = '%1' where roomNumber = '%2'").arg(ui->seaFood->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set breakfast = '%1' where roomNumber = '%2'").arg(ui->breakfast->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set fruit = '%1' where roomNumber = '%2'").arg(ui->fruit->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set wine = '%1' where roomNumber = '%2'").arg(ui->rum->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update food set iceJuice = '%1' where roomNumber = '%2'").arg(ui->juice->text().toInt()).arg(roomNumerWithNoRoom));

    query.exec(QString("update meetingroom set smallMR = '%1' where roomNumber = '%2'").arg(ui->smallMr->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update meetingroom set midMR = '%1' where roomNumber = '%2'").arg(ui->middleMr->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update meetingroom set largeMR = '%1' where roomNumber = '%2'").arg(ui->largeMid->text().toInt()).arg(roomNumerWithNoRoom));

    query.exec(QString("update entertainments set pool = '%1' where roomNumber = '%2'").arg(ui->pool->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update entertainments set swim = '%1' where roomNumber = '%2'").arg(ui->swim->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update entertainments set massage = '%1' where roomNumber = '%2'").arg(ui->massage->text().toInt()).arg(roomNumerWithNoRoom));

    query.exec(QString("update housekeep set cleanUp = '%1' where roomNumber ='%2'").arg(ui->cleanUp->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update housekeep set hygiene = '%1' where roomNumber ='%2'").arg(ui->hygiene->text().toInt()).arg(roomNumerWithNoRoom));
    query.exec(QString("update housekeep set makeBed = '%1' where roomNumber ='%2'").arg(ui->makeBed->text().toInt()).arg(roomNumerWithNoRoom));


    //提交菜单后给予提示
    QMessageBox::information(this, tr("Attention"), tr("your order is submitted"));

    //对菜单进行初始化
    ui->roomNumber->clear();
    ui->friedRice->setValue(0);
    ui->CHineseFood->setValue(0);
    ui->stake->setValue(0);
    ui->seaFood->setValue(0);
    ui->fruit->setValue(0);
    ui->breakfast->setValue(0);
    ui->rum->setValue(0);
    ui->juice->setValue(0);
    ui->smallMr->setValue(0);
    ui->middleMr->setValue(0);
    ui->largeMid->setValue(0);
    ui->pool->setValue(0);
    ui->massage->setValue(0);
    ui->cleanUp->setValue(0);
    ui->hygiene->setValue(0);
    ui->makeBed->setValue(0);

}
