#include "searchuser.h"
#include "ui_searchuser.h"

searchUser::searchUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchUser)
{
    ui->setupUi(this);
    initilizeTable();
    connect(ui->pushButton, &QPushButton::clicked, this, &searchUser::searchNo);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &searchUser::searchName);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &searchUser::searchGrade);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &searchUser::searchGraduate);

}

void searchUser::initilizeTable(void)
{
    model = new QSqlTableModel(this);
    model->setTable(table);

    model->setHeaderData(0, Qt::Horizontal, QString("序号"));
    model->setHeaderData(1, Qt::Horizontal, QString("用户号"));
    model->setHeaderData(2, Qt::Horizontal, QString("姓名"));
    model->setHeaderData(3, Qt::Horizontal, QString("年级"));
    model->setHeaderData(4, Qt::Horizontal, QString("专业"));

    model->select();
    ui->tableView->setModel(model);
}

void searchUser::searchNo(void)
{
    stuNo = ui->lineEdit->text();
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

void searchUser::searchName(void)
{
    name = ui->lineEdit_2->text();
    if(name == NULL)
    {
        model->setFilter(NULL);
        model->select();
    }
    else
    {
        query = "name LIKE \'%"+stuNo+"%\'";
        model->setFilter(query);
        model->select();
        ui->tableView->setModel(model);
    }
}

void searchUser::searchGrade(void)
{
    grade = ui->lineEdit_3->text();
    if(grade == NULL)
    {
        model->setFilter(NULL);
        model->select();
    }
    else
    {
        query = "grade = \'"+grade+"\'";
        model->setFilter(query);
        model->select();
        ui->tableView->setModel(model);
    }
}

void searchUser::searchGraduate(void)
{
    graduate = ui->lineEdit_4->text();
    if(graduate == NULL)
    {
        model->setFilter(NULL);
        model->select();
    }
    else
    {
        query = "graduate LIKE \'%"+graduate+"%\'";
        model->setFilter(query);
        model->select();
        ui->tableView->setModel(model);
    }
}

searchUser::~searchUser()
{
    delete ui;
    delete model;
}
