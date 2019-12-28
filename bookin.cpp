#include "bookin.h"
#include "ui_bookin.h"

BookIn::BookIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookIn)
{
    ui->setupUi(this);

    initilizeTable();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BookIn::ifDerty);
    timer->start(2000);

}

void BookIn::initilizeTable()
{
    table = new QSqlTableModel(this);
    table->setTable("tmpBook");
    table->setEditStrategy(QSqlTableModel::OnRowChange);

    table->setHeaderData(0, Qt::Horizontal, QString("CN刊号"));
    table->setHeaderData(1, Qt::Horizontal, QString("期刊名"));
    table->setHeaderData(2, Qt::Horizontal, QString("年"));
    table->setHeaderData(3, Qt::Horizontal, QString("卷"));
    table->setHeaderData(4, Qt::Horizontal, QString("期"));
    table->setHeaderData(5, Qt::Horizontal, QString("持有量"));
    table->setHeaderData(6, Qt::Horizontal, QString("可借阅数"));

    table->select();

    ui->tableView->setModel(table);
}

void BookIn::ifDerty()
{
    if(table->isDirty())
        ui->label->setText("有未保存的数据");
    else
        ui->label->setText("没有未保存的数据");
}

BookIn::~BookIn()
{
    delete ui;
    delete timer;
    delete table;
}
