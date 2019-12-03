#include "loginwindow.h"
#include "ui_loginwindow.h"

loginwindow::loginwindow(QSqlDatabase *db, QWidget *parent)
    : QWidget(parent)
    , ui_login(new Ui::loginwindow)
{
    ui_login->setupUi(this);
    dbStar = db;
    connect(ui_login->pushButton_2,&QPushButton::clicked,this,&QWidget::close);
    connect(ui_login->pushButton_1,&QPushButton::clicked,this,&loginwindow::ackClicked);
}

loginwindow::~loginwindow()
{
    delete ui_login;
}

void loginwindow::ackClicked()
{
    name = ui_login->lineEdit_1->text();
    passwd = ui_login->lineEdit_2->text();

    //qDebug()<<name<<","<<passwd;

    if(true == name.isEmpty() || true == passwd.isEmpty())
        QMessageBox::warning(this, tr("警告"), tr("账户名或密码为空"));
    else
    {
        if(name.contains("=") || name.contains(" ") || passwd.contains("=") || passwd.contains(" "))
            QMessageBox::warning(this, tr("警告"), tr("账户名或密码含有非法字符"));
        else
        {
            dbStar->setDatabaseName("test");
            dbStar->setPort(3306);
            dbStar->setHostName("localhost");
            dbStar->setUserName(name);
            dbStar->setPassword(passwd);
            if(!dbStar->open())
            {
                QMessageBox::information(this,tr("失败"), tr("连接失败,请重试"));
                QSqlError errorResult = dbStar->lastError();
                qDebug()<< errorResult.driverText();
             }
            else
            {
                ifOpen = 0;
                this->hide();
            }
        }

    }
}
