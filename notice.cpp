/*
作用：作为顾客界面的说明书的实现文件
作者：梁田
创建时间：2021/7/19
*/

#include "notice.h"
#include "ui_notice.h"

Notice::Notice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notice)
{
    ui->setupUi(this);
}

Notice::~Notice()
{
    delete ui;
}
