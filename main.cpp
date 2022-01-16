/*
作用：程序入口，打开首页
作者：梁田
创建时间：2021/7/8
*/
#include "widget.h"
#include <QApplication>
#include"connection.h"
#include"register.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //检测数据库是否成功打开
    if(!createConnection()){
        qDebug()<<"open failure";
        return 0;}
    Register *r = new Register();
    r->show();

    return a.exec();
}
