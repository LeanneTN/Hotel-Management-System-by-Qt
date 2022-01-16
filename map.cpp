/*
作用：作为疏散地图的设置文件
作者：梁田
创建时间：2021/7/19
*/
#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

    //固定地图的大小
    this->setMinimumSize(813,635);
}

Map::~Map()
{
    delete ui;
}
