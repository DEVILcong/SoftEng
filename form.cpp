#include "form.h"
#include "ui_form.h"

Form::Form(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mainDB = db;

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
    mainDB->close();
    delete ui;
}
