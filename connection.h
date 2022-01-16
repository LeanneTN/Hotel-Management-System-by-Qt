/*
作用：这是系统所用的数据库的创建文件，所有数据库的创建和表的创建在这里完成
作者：梁田
创建时间：2021/7/14
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include<QtSql>
#include<QDebug>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QString>

//返回bool值用于判断是否成功创建数据库，函数则是用于创建数据库和其中的表的
static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("admin");
    db.setDatabaseName("data.db");
    db.setUserName("admin");
    db.setPassword("admin");
    if(!db.open()){
        qDebug()<<"database open failure";
        return false;
    }

    QSqlQuery query;

    //创建账户表
    query.exec("create table address(user varchar primary key, password varchar)");
    query.exec("insert into address values('admin', 'admin')");

    query.exec("create table guest(user varchar primary key, password varchar, roomNumber varchar, name varchar, IDNumber id)");

    //创建每一个房间的订单表以存放客房服务的信息（仅用来结账）
    query.exec("create table room101(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room102(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room103(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room104(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room105(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room106(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room107(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room108(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room201(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room202(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room203(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room204(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room205(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room206(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room207(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room208(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room1001(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room1002(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");
    query.exec("create table room1003(foodService varchar, meetingRoomBooking varchar, entertainment varchar, houseKeeping varchar, price varchar)");

    //创建四个存放订单用的纵横表
    query.exec("create table food(roomNumber varchar, friedRice int, Chinesefood int, stake int, seafood int, breakfast int, fruit int, wine int, iceJuice int)");
    query.exec(QString("insert into food values('101',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('102',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('103',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('104',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('105',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('106',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('107',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('108',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('201',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('202',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('203',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('204',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('205',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('206',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('207',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('208',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('1001',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('1002',0,0,0,0,0,0,0,0)"));
    query.exec(QString("insert into food values('1003',0,0,0,0,0,0,0,0)"));

    query.exec("create table meetingroom(roomNumber varchar, smallMR int, midMR int, largeMR int)");
    query.exec(QString("insert into meetingroom values('101',0,0,0)"));
    query.exec(QString("insert into meetingroom values('102',0,0,0)"));
    query.exec(QString("insert into meetingroom values('103',0,0,0)"));
    query.exec(QString("insert into meetingroom values('104',0,0,0)"));
    query.exec(QString("insert into meetingroom values('105',0,0,0)"));
    query.exec(QString("insert into meetingroom values('106',0,0,0)"));
    query.exec(QString("insert into meetingroom values('107',0,0,0)"));
    query.exec(QString("insert into meetingroom values('108',0,0,0)"));
    query.exec(QString("insert into meetingroom values('201',0,0,0)"));
    query.exec(QString("insert into meetingroom values('202',0,0,0)"));
    query.exec(QString("insert into meetingroom values('203',0,0,0)"));
    query.exec(QString("insert into meetingroom values('204',0,0,0)"));
    query.exec(QString("insert into meetingroom values('205',0,0,0)"));
    query.exec(QString("insert into meetingroom values('206',0,0,0)"));
    query.exec(QString("insert into meetingroom values('207',0,0,0)"));
    query.exec(QString("insert into meetingroom values('208',0,0,0)"));
    query.exec(QString("insert into meetingroom values('1001',0,0,0)"));
    query.exec(QString("insert into meetingroom values('1002',0,0,0)"));
    query.exec(QString("insert into meetingroom values('1003',0,0,0)"));

    query.exec("create table entertainments(roomNumber varchar, pool int, swim int, massage int)");
    query.exec(QString("insert into entertainments values('101',0,0,0)"));
    query.exec(QString("insert into entertainments values('102',0,0,0)"));
    query.exec(QString("insert into entertainments values('103',0,0,0)"));
    query.exec(QString("insert into entertainments values('104',0,0,0)"));
    query.exec(QString("insert into entertainments values('105',0,0,0)"));
    query.exec(QString("insert into entertainments values('106',0,0,0)"));
    query.exec(QString("insert into entertainments values('107',0,0,0)"));
    query.exec(QString("insert into entertainments values('108',0,0,0)"));
    query.exec(QString("insert into entertainments values('201',0,0,0)"));
    query.exec(QString("insert into entertainments values('202',0,0,0)"));
    query.exec(QString("insert into entertainments values('203',0,0,0)"));
    query.exec(QString("insert into entertainments values('204',0,0,0)"));
    query.exec(QString("insert into entertainments values('205',0,0,0)"));
    query.exec(QString("insert into entertainments values('206',0,0,0)"));
    query.exec(QString("insert into entertainments values('207',0,0,0)"));
    query.exec(QString("insert into entertainments values('208',0,0,0)"));
    query.exec(QString("insert into entertainments values('1001',0,0,0)"));
    query.exec(QString("insert into entertainments values('1002',0,0,0)"));
    query.exec(QString("insert into entertainments values('1003',0,0,0)"));


    query.exec(QString("create table housekeep(roomNumber varchar, cleanUp int, hygiene int, makeBed int)"));
    query.exec(QString("insert into housekeep values('101',0,0,0)"));
    query.exec(QString("insert into housekeep values('102',0,0,0)"));
    query.exec(QString("insert into housekeep values('103',0,0,0)"));
    query.exec(QString("insert into housekeep values('104',0,0,0)"));
    query.exec(QString("insert into housekeep values('105',0,0,0)"));
    query.exec(QString("insert into housekeep values('106',0,0,0)"));
    query.exec(QString("insert into housekeep values('107',0,0,0)"));
    query.exec(QString("insert into housekeep values('108',0,0,0)"));
    query.exec(QString("insert into housekeep values('201',0,0,0)"));
    query.exec(QString("insert into housekeep values('202',0,0,0)"));
    query.exec(QString("insert into housekeep values('203',0,0,0)"));
    query.exec(QString("insert into housekeep values('204',0,0,0)"));
    query.exec(QString("insert into housekeep values('205',0,0,0)"));
    query.exec(QString("insert into housekeep values('206',0,0,0)"));
    query.exec(QString("insert into housekeep values('207',0,0,0)"));
    query.exec(QString("insert into housekeep values('208',0,0,0)"));
    query.exec(QString("insert into housekeep values('1001',0,0,0)"));
    query.exec(QString("insert into housekeep values('1002',0,0,0)"));
    query.exec(QString("insert into housekeep values('1003',0,0,0)"));


    //创建房间列表
    query.exec("create table hotelroom(id varchar primary key,name varchar)");
    query.exec(QString("insert into hotelroom values('0',' 房间规格')"));
    query.exec(QString("insert into hotelroom values('01','Suite')"));
    query.exec(QString("insert into hotelroom values('02','Standard')"));
    query.exec(QString("insert into hotelroom values('03','Single')"));


    //创建房间选择表
    query.exec("create table eachroom(id varchar primary key,roomNumber varchar,roomType varchar, price int,sell int,last int, year int, month int, day int, lastDay int, clientName varchar, IDNumber varchar, otherServices int)");

    query.exec(QString("insert into eachroom values('0','房间选项', 0,0,0)"));
    query.exec(QString("insert into eachroom values('01','101','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('02','102','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('03','103','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('04','104','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('05','105','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('06','106','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('07','107','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('08','108','Single',600,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('09','201','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('10','202','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('11','203','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('12','204','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('13','205','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('14','206','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('15','207','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('16','208','Standard',800,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('17','1001','Suite',1200,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('18','1002','Suite',1200,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into eachroom values('19','1003','Suite',1200,0,1,0,0,0,0,'name', 'id',0)"));
    query.exec(QString("insert into each_room values('20','1004','Suite',1200,0,1,0,0,0,0,'name', 'id',0)"));
    qDebug()<<"create success";
    return true;

}



#endif // CONNECTION_H
