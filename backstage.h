/*
作用：前台查看菜单所用的backStage的头文件
作者：梁田
创建时间：2021/7/17
*/
#ifndef BACKSTAGE_H
#define BACKSTAGE_H

#include <QWidget>

namespace Ui {
class BackStage;
}

class BackStage : public QWidget
{
    Q_OBJECT

public:
    explicit BackStage(QWidget *parent = nullptr);
    ~BackStage();

private slots:
    void on_checkOrder_clicked();

    void on_complete_clicked();

private:
    Ui::BackStage *ui;
};

#endif // BACKSTAGE_H
