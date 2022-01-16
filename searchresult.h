#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QLineEdit>

namespace Ui {
class SearchResult;
}

class SearchResult : public QWidget
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();

private:
    Ui::SearchResult *ui;
    QLabel* name;
    QLabel* IDNumber;
    QLabel* roomNumber;
    QLabel* checkIn;
    QLabel* lastDays;

    QLineEdit* nameLine;
    QLineEdit* IDNumberLine;
    QLineEdit* roomNumberLine;
    QLineEdit* checkInLine;
    QLineEdit* lastDaysLine;
};

#endif // SEARCHRESULT_H
