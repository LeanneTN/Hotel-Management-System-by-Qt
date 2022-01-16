#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(name, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(IDNumber, 1, 0);
    mainLayout->addWidget(IDNumberLine,1,1);
    mainLayout->addWidget(roomNumber, 2, 0);
    mainLayout->addWidget(roomNumberLine, 2, 1);
    mainLayout->addWidget(checkIn, 3, 0);
    mainLayout->addWidget(checkInLine, 3, 1);
    mainLayout->addWidget(lastDays, 4, 0);
    mainLayout->addWidget(lastDaysLine,4,1);

}

SearchResult::~SearchResult()
{
    delete ui;
}
