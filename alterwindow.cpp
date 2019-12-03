#include "alterwindow.h"
#include "ui_alterwindow.h"

alterWindow::alterWindow(QString table, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::alterWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->select();   //initilize model

    QString tableDetail[6][6];
    tableDetail[0][0] = "楼号";       tableDetail[3][0] = "工号";
    tableDetail[0][1] = "户数";       tableDetail[3][1] = "姓名";
    tableDetail[0][2] = "楼层数";     tableDetail[3][2] = "性别";
    tableDetail[0][3] = "物业费标准";  tableDetail[3][3] = "年龄";
    tableDetail[0][4] = "管理员工号";  tableDetail[3][4] = "电话";
    tableDetail[0][5] = "\0";        tableDetail[3][5] = "身份证号";
    tableDetail[1][0] = "房号";       tableDetail[4][0] = "房号";
    tableDetail[1][1] = "面积";       tableDetail[4][1] = "上一次缴费日期";
    tableDetail[1][2] = "所有者姓名";   tableDetail[4][2] = "应交金额";
    tableDetail[1][3] = "\0";         tableDetail[4][3] = "本月缴纳情况";
    tableDetail[1][4] = "\0";         tableDetail[4][4] = "欠费情况";
    tableDetail[1][5] = "\0";         tableDetail[4][5] = "\0";
    tableDetail[2][0] = "房号";       tableDetail[5][0] = "编号";
    tableDetail[2][1] = "身份证号";    tableDetail[5][1] = "房号";
    tableDetail[2][2] = "姓名";       tableDetail[5][2] = "日期";
    tableDetail[2][3] = "性别";       tableDetail[5][3] = "业主要求";
    tableDetail[2][4] = "电话";       tableDetail[5][4] = "处理情况";
    tableDetail[2][5] = "家庭人口数";  tableDetail[5][5] = "负责人工号";

    if(table == "building")
        for(int i = 0; i < 5; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[0][i]);
    else if(table == "charge")
        for(int i = 0; i < 5; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[4][i]);
    else if(table == "room")
        for(int i = 0; i < 3; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[1][i]);
    else if(table == "worker")
        for(int i = 0; i < 6; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[3][i]);
    else if(table == "people")
        for(int i = 0; i < 6; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[2][i]);
    else if(table == "questions")
        for(int i = 0; i < 6; ++i)
            model->setHeaderData(i, Qt::Horizontal, tableDetail[5][i]);

    ui->tableView->setModel(model);
    ui->tableView->show();
}



alterWindow::~alterWindow()
{
    delete ui;
    delete model;
}
