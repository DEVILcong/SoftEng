#include "menuuser.h"
#include "ui_menuuser.h"

MenuUser::MenuUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuUser)
{
    ui->setupUi(this);
}

MenuUser::~MenuUser()
{
    delete ui;
}
