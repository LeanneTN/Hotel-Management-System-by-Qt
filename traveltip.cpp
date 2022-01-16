/*
作用：作为旅行助手的实现文件
作者：梁田
创建时间：2021/7/19
*/
#include "traveltip.h"
#include "ui_traveltip.h"

TravelTip::TravelTip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TravelTip)
{
    ui->setupUi(this);
}

TravelTip::~TravelTip()
{
    delete ui;
}
