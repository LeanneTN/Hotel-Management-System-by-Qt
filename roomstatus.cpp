/*
作用：实现对房间状态的显示
作者：梁田
创建时间：2021/7/17
*/
#include "roomstatus.h"
#include "ui_roomstatus.h"
#include<QSql>
#include<QSqlQuery>
#include<QSqlQueryModel>


RoomStatus::RoomStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomStatus)
{
    ui->setupUi(this);

    //创建一个QSQLQueryModel类的指针实例对象
    static QSqlQueryModel *model = new QSqlQueryModel(ui->roomList);

    model->setQuery(QString("select roomNumber, last, year, month, day, lastDay from eachroom"));

    //设置表格表头
    model->setHeaderData(0, Qt::Horizontal, tr("roomNumber"));
    model->setHeaderData(1, Qt::Horizontal, tr("last"));
    model->setHeaderData(2, Qt::Horizontal, tr("year"));
    model->setHeaderData(3, Qt::Horizontal, tr("month"));
    model->setHeaderData(4, Qt::Horizontal, tr("day"));
    model->setHeaderData(5, Qt::Horizontal, tr("last days"));

    //将数据插入表中并显示
    ui->roomList->setModel(model);
}

RoomStatus::~RoomStatus()
{
    delete ui;
}
