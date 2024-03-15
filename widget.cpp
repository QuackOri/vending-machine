#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#define P_COFFEE    100
#define P_TEA       200
#define P_TANG      300

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeEnable();
}

void Widget::changeEnable(){
    ui->pbReset->setEnabled(money>0);
    ui->pbCoffee->setEnabled(money >= P_COFFEE);
    ui->pbTea->setEnabled(money >= P_TEA);
    ui->pbTang->setEnabled(money >= P_TANG);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-P_COFFEE);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-P_TEA);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-P_TANG);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int stand[4] = {500,100,50,10};
    int charge[4] = {0,0,0,0};
    int r = money;
    for (int i=0;i<4;i++){
        charge[i] = r / stand[i];
        r %= stand[i];
    }

    QString text = QString("500:%1 100:%2 50:%3 10:%4")
                       .arg(charge[0])
                       .arg(charge[1])
                       .arg(charge[2])
                       .arg(charge[3]);

    mb.information(nullptr, "It's your charge", text);

    changeMoney(-money);
}

