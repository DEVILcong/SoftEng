#include "searchwindow.h"
#include "ui_searchwindow.h"

searchWindow::searchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&searchWindow::search);
}

searchWindow::~searchWindow()
{
    delete ui;
}

void searchWindow::search()
{
    QString thing = ui->lineEdit->text();
    QString table;
    QString prkey;
    int caseNo;    //for convenient

    if(ui->radioButton->isChecked())
    {
        table = "building";
        prkey = "builbNo";    //stupid
        caseNo = 0;
    }
    else if(ui->radioButton_2->isChecked())
    {
        table = "room";
        prkey = "roomNo";
        caseNo = 1;
    }
    else if(ui->radioButton_3->isChecked())
    {
        table = "people";
        prkey = "roomNo";
        caseNo = 2;
    }
    else if(ui->radioButton_4->isChecked())
    {
        table = "worker";
        prkey = "workId";
        caseNo = 3;
    }
    else
    {
        table = "charge";
        prkey = "roomNo";
        caseNo = 4;
    }

    QString query_prkey = "SELECT * FROM " + table +" where " + prkey + "=" + "\"" + thing +"\"";
    //search by primary key like A0304
    QString query_name = "SELECT * FROM " + table + " where name like \"%" + thing +"%\"";
    //search by name like 'Tom'

    QSqlQuery sqlquery;

    if(thing[0] > 57 and (table == "people" or table == "worker"))
        sqlquery.prepare(query_name);
    else
        sqlquery.prepare(query_prkey);

    sqlquery.exec();
    
    int columns[5] = {5, 3, 6, 5, 5};

    ui->textEdit->clear();
    ui->textEdit->setReadOnly(true);
     while(sqlquery.next())
    {
        for(int i = 0; i < columns[caseNo]; ++i)
        {
             ui->textEdit->insertPlainText(sqlquery.value(i).toString());
             ui->textEdit->insertPlainText("\t");
        }
        ui->textEdit->insertPlainText("\n");
    }

}
