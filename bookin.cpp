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
    connect(ui->pushButton, &QPushButton::clicked, this, &BookIn::close);
    timer->start(2000);

}
void BookIn::initilizeTable()
{
    table = new QSqlTableModel(this);
    table->setTable("Book");
    table->setEditStrategy(QSqlTableModel::OnRowChange);

    table->setHeaderData(0, Qt::Horizontal, tr("序号"));
    table->setHeaderData(1, Qt::Horizontal, tr("CN刊号"));
    table->setHeaderData(2, Qt::Horizontal, tr("期刊名"));
    table->setHeaderData(3, Qt::Horizontal, tr("年"));
    table->setHeaderData(4, Qt::Horizontal, tr("卷"));
    table->setHeaderData(5, Qt::Horizontal, tr("期"));
    table->setHeaderData(6, Qt::Horizontal, tr("持有量"));
    table->setHeaderData(7, Qt::Horizontal, tr("可借阅数"));

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
