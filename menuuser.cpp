#include "menuuser.h"
#include "ui_menuuser.h"

MenuUser::MenuUser(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuUser)
{
    ui->setupUi(this);
    maindb = db;
    connect(ui->pushButton, &QPushButton::clicked, this, &MenuUser::winSearchB);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MenuUser::winSearchC);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MenuUser::winSearchBo);
}

void MenuUser::winSearchB(void)
{
    if(!isLogin())
        return;

    searchB = new search(1);
    searchB->show();
}
void MenuUser::winSearchC(void)
{
    if(!isLogin())
        return;

    searchC = new searchContent(1);
    searchC->show();
}
void MenuUser::winSearchBo(void)
{
    if(!isLogin())
        return;
    ssb = new stuSearchBorrow(nullptr, maindb->userName());
    ssb->show();
}

bool MenuUser::isLogin()
{
    if(!maindb->isOpen())
    {
        QMessageBox::critical(this,"警告","请先登录");
        return false;
    }
    return true;
}

MenuUser::~MenuUser()
{
    delete ui;
    maindb->close();
    delete searchB;
    delete  searchC;
    delete ssb;
    delete maindb;
}
