#ifndef SEARCHRESULT3_H
#define SEARCHRESULT3_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QGridLayout>

namespace Ui {
class searchresult3;
}

class searchresult3 : public QWidget
{
    Q_OBJECT

public:
    explicit searchresult3(QWidget *parent = nullptr);
    ~searchresult3();

private:
    Ui::searchresult3 *ui;

    QLineEdit *nameLine;
    QLineEdit *IDLine;
    QLineEdit *roomNumberLine;
    QLineEdit *checkInDate;
    QLineEdit *lastDays;
    QLabel *name;
    QLabel *ID;
    QLabel *roomNumber;
    QLabel *checkIn;
    QLabel *days;
};

#endif // SEARCHRESULT3_H
