#include "search.h"
#include "ui_search.h"

search::search(int readOnly, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    initilizeTable();
    connect(ui->pushButton, &QPushButton::clicked, this, &search::searchCN);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &search::searchName);

    if(readOnly == 1)
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void search::initilizeTable(void)
{
    model = new QSqlTableModel(this);
    model->setTable(table);
    model->setHeaderData(0, Qt::Horizontal, QString("序号"));
    model->setHeaderData(1, Qt::Horizontal, QString("CN刊号"));
    model->setHeaderData(2, Qt::Horizontal, QString("期刊名"));
    model->setHeaderData(3, Qt::Horizontal, QString("年"));
    model->setHeaderData(4, Qt::Horizontal, QString("卷"));
    model->setHeaderData(5, Qt::Horizontal, QString("期"));
    model->setHeaderData(6, Qt::Horizontal, QString("持有量"));
    model->setHeaderData(7, Qt::Horizontal, QString("可借阅数"));
    model->select();

    ui->tableView->setModel(model);
}

void search::searchCN()
{
    CN = ui->lineEdit->text();
    query = "cnNo=\'"+CN+"\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}

void search::searchName()
{
    name = ui->lineEdit_2->text();
    query = "bookName LIKE \'%"+name+"%\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}

search::~search()
{
    delete ui;
    delete model;
}
