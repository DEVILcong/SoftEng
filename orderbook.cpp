#include "orderbook.h"
#include "ui_orderbook.h"

orderBook::orderBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderBook)
{
    ui->setupUi(this);
    initilizeTable();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &orderBook::ifDerty);
    connect(ui->pushButton, &QPushButton::clicked, this, &orderBook::close);
    timer->start(2000);
}

void orderBook::initilizeTable()
{
    table = new QSqlTableModel(this);
    table->setTable(tableName);
    table->setEditStrategy(QSqlTableModel::OnRowChange);

    table->setHeaderData(0, Qt::Horizontal, tr("序号"));
    table->setHeaderData(1, Qt::Horizontal, tr("书名"));
    table->setHeaderData(2, Qt::Horizontal, tr("数量"));
    table->setHeaderData(3, Qt::Horizontal, tr("订阅阶段"));

    table->select();

    ui->tableView->setModel(table);
}

void orderBook::ifDerty()
{
    if(table->isDirty())
        ui->label->setText("有未保存的数据");
    else
        ui->label->setText("没有未保存的数据");
}
orderBook::~orderBook()
{
    delete ui;
}
