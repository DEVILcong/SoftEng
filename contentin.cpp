#include "contentin.h"
#include "ui_contentin.h"

ContentIn::ContentIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContentIn)
{
    ui->setupUi(this);
    initilizeTable();
    timer = new QTimer(this);
    connect(ui->pushButton, &QPushButton::click, this, this->close());
    connect(timer, &QTimer::timeout, this, &ContentIn::isDerty);
    timer->start(2000);
}

void ContentIn::initilizeTable(void)
{
    table = new QSqlTableModel(this);
    table->setTable("content");
    table->setEditStrategy(QSqlTableModel::OnRowChange);

    table->setHeaderData(0, Qt::Horizontal, QString("序号"));
    table->setHeaderData(1, Qt::Horizontal, QString("文章名称"));
    table->setHeaderData(2, Qt::Horizontal, QString("作者"));
    table->setHeaderData(3, Qt::Horizontal, QString("关键词信息"));
    table->setHeaderData(4, Qt::Horizontal, QString("所在期刊名称"));
    table->setHeaderData(5, Qt::Horizontal, QString("所在期刊CN号"));
    table->setHeaderData(6, Qt::Horizontal, QString("所在期刊年信息"));
    table->setHeaderData(7, Qt::Horizontal, QString("所在期刊卷信息"));
    table->setHeaderData(8, Qt::Horizontal, QString("所在期刊期信息"));
    table->setHeaderData(9, Qt::Horizontal, QString("所在期刊起页数"));
    table->setHeaderData(10, Qt::Horizontal, QString("所在期刊止页数"));

    table->select();
    ui->tableView->setModel(table);
}

void ContentIn::isDerty()
{
    if(table->isDirty())
        ui->label->setText("有未保存的数据");
    else
        ui->label->setText("没有未保存的数据");
}

ContentIn::~ContentIn()
{
    delete ui;
    delete table;
    delete timer;
}
