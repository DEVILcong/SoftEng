#include "form.h"
#include "ui_form.h"

Form::Form(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mainDB = db;
    connect(ui->pushButton_8, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->pushButton, &QPushButton::clicked, this, &Form::searchWinShow);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Form::alterWinShow_build);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Form::alterWinShow_room);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Form::alterWindow_people);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &Form::alterWindow_charge);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &Form::alterWindow_quest);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &Form::alterWindow_worker);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &Form::messageBox_me);
}

void Form::searchWinShow()
{
    if(!isLogin())
        return;
    seWin.show();
}

void Form::alterWinShow_build()
{
    if(!isLogin())
        return;
    alWin = new alterWindow("building");
    alWin->setWindowTitle("修改楼栋信息");
    alWin->show();
}

void Form::alterWinShow_room()
{
    if(!isLogin())
        return;

    alWin = new alterWindow("room");
    alWin->setWindowTitle("修改房屋信息");
    alWin->show();
}

void Form::alterWindow_people()
{
    if(!isLogin())
        return;

    alWin = new alterWindow("people");
    alWin->setWindowTitle("修改业主信息");
    alWin->show();
}

void Form::alterWindow_worker()
{
    if(!isLogin())
        return;

    alWin = new alterWindow("worker");
     alWin->setWindowTitle("修改管理员信息");
     alWin->show();
}

void Form::alterWindow_charge()
{
    if(!isLogin())
        return;

    alWin = new alterWindow("charge");
    alWin->setWindowTitle("修改物业费信息");
    alWin->show();
}

void Form::alterWindow_quest()
{
    if(!isLogin())
        return;

    alWin = new alterWindow("questions");
    alWin->setWindowTitle("修改业主需求");
    alWin->show();
}

void Form::messageBox_me()
{
    QString title = "制作者信息";
    QString info = "2019.10,安徽大学数据库课程设计某小组";

    QMessageBox::information(this, title, info);
}

bool Form::isLogin()
{
    if(!mainDB->isOpen())
    {
        QMessageBox::critical(this,"警告","请先登录");
        return false;
    }
    return true;
}

Form::~Form()
{
    delete alWin;
    mainDB->close();
    delete ui;
}
