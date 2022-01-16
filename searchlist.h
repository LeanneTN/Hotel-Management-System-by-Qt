/*
作用：这里是searchList的头文件
作者：梁田
创建时间：2021/7/15
*/

#ifndef SEARCHLIST_H
#define SEARCHLIST_H

#include <QWidget>
#include<QDateEdit>
#include<QPainter>
#include<QStyleOption>

namespace Ui {
class SearchList;
}

class SearchList : public QWidget
{
    Q_OBJECT

public:
    explicit SearchList(QWidget *parent = nullptr);
    ~SearchList();

private slots:
    void on_searchByNameBtn_clicked();

    void on_searchByIDBtn_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SearchList *ui;

    void paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);

        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
};

#endif // SEARCHLIST_H
