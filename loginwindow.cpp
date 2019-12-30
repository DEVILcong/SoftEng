#include "loginwindow.h"
#include "ui_loginwindow.h"

loginwindow::loginwindow(Form *mainWin, MenuUser *user, QSqlDatabase *db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);
    mainWindow = mainWin;
    menuUser = user;
    maindb = db;
    connect(ui->pushButton_2,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&loginwindow::ackClicked);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::ackClicked()
{
    name = ui->lineEdit_1->text();
    passwd = ui->lineEdit_2->text();

    //qDebug()<<name<<","<<passwd;

    if(true == name.isEmpty() || true == passwd.isEmpty())
        QMessageBox::warning(this, tr("警告"), tr("账户名或密码为空"));
    else
    {
        if(name.contains("=") || name.contains(" ") || passwd.contains("=") || passwd.contains(" "))
            QMessageBox::warning(this, tr("警告"), tr("账户名或密码含有非法字符"));
        else
        {
            maindb->setDatabaseName("test");
            maindb->setPort(3306);
            maindb->setHostName("localhost");
            maindb->setUserName(name);
            maindb->setPassword(passwd);
            if(!maindb->open())
            {
                QMessageBox::information(this,tr("失败"), tr("连接失败,请重试"));
//                QSqlError errorResult = maindb->lastError();
//                qDebug()<< errorResult.driverText();
             }
            else
            {
                if(ui->radioButton->isChecked())
                {
                    if(ui->lineEdit->text() == "3.1415926")
                        mainWindow->show();
                    else
                        QMessageBox::warning(this, "warning", "管理员密码错误");
                }
                else if(ui->radioButton_2->isChecked())
                    menuUser->show();

                this->close();
            }
        }

    }
}
