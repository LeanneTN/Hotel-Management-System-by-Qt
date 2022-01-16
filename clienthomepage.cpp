/*
作用：作为顾客登录后的首页，顾客从本页面进入顾客系统中的各个功能
作者：梁田
创建时间：2021/7/19
*/

#include "clienthomepage.h"
#include "ui_clienthomepage.h"
#include"connection.h"
#include"otherservice.h"
#include"traveltip.h"
#include"map.h"
#include"notice.h"
#include<QMediaPlayer>


ClientHomePage::ClientHomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientHomePage)
{
    ui->setupUi(this);
    //声明一个播放器类进行音乐播放
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromEncoded("qrc:/new/prefix1/Eagles - Hotel California.mp3"));
    //调节音量大小为30%
    player->setVolume(30);
    player->play();
}

ClientHomePage::~ClientHomePage()
{
    delete ui;
}

//点击点单按钮之后弹出菜单界面
void ClientHomePage::on_pushButton_clicked()
{
    OtherService *o = new OtherService;
    o->show();
}

//点击说明之后弹出说明界面
void ClientHomePage::on_pushButton_2_clicked()
{
    Notice *n = new Notice;
    n->show();
}

//点击疏散地图之后弹出地图界面
void ClientHomePage::on_pushButton_3_clicked()
{
    Map *m = new Map;
    m->show();
}

//点击旅行助手按钮后跳出旅行助手界面
void ClientHomePage::on_pushButton_4_clicked()
{
    TravelTip *t = new TravelTip;
    t->show();
}
