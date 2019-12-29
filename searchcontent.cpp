#include "searchcontent.h"
#include "ui_searchcontent.h"

searchContent::searchContent(int readOnly, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchContent)
{
    ui->setupUi(this);
    initilizeTable();
    connect(ui->pushButton, &QPushButton::clicked, this, &searchContent::searchName);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &searchContent::searchAuthor);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &searchContent::searchKwd);

    if(readOnly == 1)
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void searchContent::initilizeTable(void)
{
    model = new QSqlTableModel(this);
    model->setTable(table);

    model->setHeaderData(0, Qt::Horizontal, QString("序号"));
    model->setHeaderData(1, Qt::Horizontal, QString("文章名称"));
    model->setHeaderData(2, Qt::Horizontal, QString("作者"));
    model->setHeaderData(3, Qt::Horizontal, QString("关键词信息"));
    model->setHeaderData(4, Qt::Horizontal, QString("所在期刊名称"));
    model->setHeaderData(5, Qt::Horizontal, QString("所在期刊CN号"));
    model->setHeaderData(6, Qt::Horizontal, QString("所在期刊年信息"));
    model->setHeaderData(7, Qt::Horizontal, QString("所在期刊卷信息"));
    model->setHeaderData(8, Qt::Horizontal, QString("所在期刊期信息"));
    model->setHeaderData(9, Qt::Horizontal, QString("所在期刊起页数"));
    model->setHeaderData(10, Qt::Horizontal, QString("所在期刊止页数"));

    model->select();
    ui->tableView->setModel(model);
}

void searchContent::searchName()
{
    contentName = ui->lineEdit->text();
    query = "name LIKE \'%"+contentName+"%\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}
void searchContent::searchAuthor()
{
    contentAuthor = ui->lineEdit_2->text();
    query = "author LIKE \'%"+contentAuthor+"%\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}
void searchContent::searchKwd()
{
    contentKwd = ui->lineEdit_3->text();
    query = "kwd LIKE \'%"+contentKwd+"%\'";
    model->setFilter(query);
    model->select();
    ui->tableView->setModel(model);
}

searchContent::~searchContent()
{
    delete ui;
    delete model;
}
