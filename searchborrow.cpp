#include "searchborrow.h"
#include "ui_searchborrow.h"

searchBorrow::searchBorrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchBorrow)
{
    ui->setupUi(this);
    initilizeTable();
    connect(ui->pushButton, &QPushButton::clicked, this, &searchBorrow::searchBook);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &searchBorrow::searchStu);
}

void searchBorrow::initilizeTable(void)
{
    model = new QSqlTableModel(this);
    model->setTable(table);
    model->setHeaderData(0, Qt::Horizontal, QString("CN刊号"));
    model->setHeaderData(1, Qt::Horizontal, QString("年"));
    model->setHeaderData(2, Qt::Horizontal, QString("卷"));
    model->setHeaderData(3, Qt::Horizontal, QString("期"));
    model->setHeaderData(4, Qt::Horizontal, QString("借阅人学号"));
    model->setHeaderData(5, Qt::Horizontal, QString("借阅日期"));
    model->setHeaderData(6, Qt::Horizontal, QString("借阅天数"));
    model->setHeaderData(7, Qt::Horizontal, QString("应归还日期"));
    model->setHeaderData(8, Qt::Horizontal, QString("实际归还日期"));

    model->select();
    ui->tableView->setModel(model);
}

void searchBorrow::searchBook(void)
{
    cnNo = ui->lineEdit->text();
    nian = ui->lineEdit_2->text();
    juan = ui->lineEdit_3->text();
    qi = ui->lineEdit_4->text();
    query = "cnNo=\'"+cnNo+"\' AND nian=\'"+nian+"\' AND juan=\'"+juan+"\' AND qi=\'"+qi+"\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}

void searchBorrow::searchStu(void)
{
    stuNo = ui->lineEdit_5->text();
    if(stuNo == NULL)
    {
        model->setFilter(NULL);
        model->select();
    }
    else
    {
        query = "stuNo = \'"+stuNo+"\'";
        model->setFilter(query);
        model->select();
        ui->tableView->setModel(model);
    }
}

searchBorrow::~searchBorrow()
{
    delete ui;
    delete model;
}
