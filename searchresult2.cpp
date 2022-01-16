#include "searchresult2.h"
#include "ui_searchresult2.h"

searchresult2::searchresult2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchresult2)
{
    ui->setupUi(this);

    name->setText("name:");
    ID->setText("IDNumber:");
    roomNumber->setText("room number:");
    checkIn->setText("check in date:");
    days->setText("last days:");

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(name,0,0);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(ID, 1, 0);
    mainLayout->addWidget(IDLine, 1, 1);
    mainLayout->addWidget(roomNumber, 2, 0);
    mainLayout->addWidget(roomNumberLine, 2, 1);
    mainLayout->addWidget(checkIn, 3, 0);
    mainLayout->addWidget(checkInDate, 3, 1);
    mainLayout->addWidget(days, 4, 0);
    mainLayout->addWidget(lastDays, 4, 1);
}

searchresult2::~searchresult2()
{
    delete ui;
}
