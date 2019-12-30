#include "form.h"
#include "ui_form.h"

Form::Form(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    mainDB = db;

    connect(ui->pushButton, &QPushButton::clicked, this, &Form::winBookIn);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Form::winContentIn);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Form::winBorrow);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Form::winReturn);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &Form::winOrder);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &Form::winSearchBo);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &Form::winSearchB);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &Form::winSearchC);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &Form::winSearchU);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &Form::close);

}

void Form::winBookIn(void)
{
    if(!isLogin())
        return;

    bookIn = new BookIn;
    bookIn->show();
}

void Form::winContentIn(void)
{
    if(!isLogin())
        return;

    contentIn = new ContentIn;
    contentIn->show();
}
void Form::winBorrow(void)
{
    if(!isLogin())
        return;

    borrowWin = new borrow;
    borrowWin->show();
}
void Form::winReturn(void)
{
    if(!isLogin())
        return;

    returnB = new returnBook;
    returnB->show();
}
void Form::winSearchB(void)
{
    if(!isLogin())
        return;

    searchB = new search(0);
    searchB->show();
}
void Form::winSearchC(void)
{
    if(!isLogin())
        return;

    searchC = new searchContent(0);
    searchC->show();
}
void Form::winSearchBo(void)
{
    if(!isLogin())
        return;

    searchBo = new searchBorrow;
    searchBo->show();
}
void Form::winSearchU(void)
{
    if(!isLogin())
        return;

    searchU = new searchUser;
    searchU->show();
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

void Form::winOrder(void)
{
    if(!isLogin())
        return;

    order = new orderBook;
    order->show();
}

Form::~Form()
{
    mainDB->close();
    delete ui;
    delete bookIn;
    delete contentIn;
    delete borrowWin;
    delete returnB;
    delete searchB;
    delete searchC;
    delete searchBo;
    delete searchU;
    delete order;
}
