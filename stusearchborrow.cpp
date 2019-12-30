#include "stusearchborrow.h"
#include "ui_stusearchborrow.h"

stuSearchBorrow::stuSearchBorrow(QWidget *parent, QString stuNO) :
    QWidget(parent),
    ui(new Ui::stuSearchBorrow)
{
    ui->setupUi(this);
    stuNo = stuNO;
    initilizeTable();
}

void stuSearchBorrow::initilizeTable(void)
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

    query = "stuNo = \'"+stuNo+"\'";
    model->setFilter(query);
    model->select();
    model->select();
    ui->tableView->setModel(model);
}

stuSearchBorrow::~stuSearchBorrow()
{
    delete ui;
    delete model;
}
