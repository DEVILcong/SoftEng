#include "borrow.h"
#include "ui_borrow.h"

borrow::borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &borrow::process);
}

void borrow::process()
{
    cnNo = ui->lineEdit->text();
    nian = ui->lineEdit_2->text();
    juan = ui->lineEdit_3->text();
    qi = ui->lineEdit_4->text();
    stuNo = ui->lineEdit_5->text();
    borrowDate = ui->dateEdit->date();
    borrowDays = ui->lineEdit_6->text();
    returnDate = ui->dateEdit_2->date();
    actulRetDate = ui->dateEdit_3->date();

    QString getAviNum = "SELECT aviNum FROM"+table+" WHERE cnNo=\'"+cnNo+"\' AND nian=\'"+nian+"\' AND juan=\'"+juan+"\' and qi=\'"+qi+"\';";
    QString insert = "INSERT INTO "+table+" VALUES(\'"+cnNo+"\',\'"+nian+"\',\'"+juan+"\',\'"+qi+"\',\'"+stuNo+"\',\'"+borrowDate.toString("yyyyMMdd")+"\',\'"+borrowDays+"\',\'"+returnDate.toString("yyyyMMdd")+"\',\'"+actulRetDate.toString("yyyyMMdd")+"\');";
    QSqlQuery query;

    query.exec(getAviNum);
    query.first();
    int aviNum = query.value('aviNum').toInt();
    if(aviNum == 0)
    {
        QMessageBox::warning(this, "警告", "可借阅书籍数不足");
    }
    else
    {
        if(!query.exec(insert))
        {
            QMessageBox::warning(this, "警告", "操作失败");
        }
        else
        {
            QString num = QString::number(aviNum-1);
            QString update = "UPDATE "+table+" SET aviNum="+num+" WHERE cnNo=\'"+cnNo+"\' AND nian=\'"+nian+"\' AND juan=\'"+juan+"\' and qi=\'"+qi+"\';";
            query.exec(update);
            QString info = "当前图书可借阅数为"+num;
            QMessageBox::information(this, "借阅成功", info);
            this->close();
        }
    }
}

borrow::~borrow()
{
    delete ui;
}
