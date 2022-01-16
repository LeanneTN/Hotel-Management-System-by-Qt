/*
 作用：本源代码用于实现help窗口
 作者：梁田
 创建时间：2021/7/16
*/

#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
}

Help::~Help()
{
    delete ui;
}
