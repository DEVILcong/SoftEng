#include "returnbook.h"
#include "ui_returnbook.h"

returnBook::returnBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &returnBook::process);
}

void returnBook::process(void)
{
    cnNo = ui->lineEdit->text();
    nian = ui->lineEdit_2->text();
    juan = ui->lineEdit_3->text();
    qi = ui->lineEdit_4->text();
    stuNo = ui->lineEdit_5->text();

    QDate currDate = QDate::currentDate();
    QString date = currDate.toString("yyyyMMdd");
    QString update = "UPDATE "+table+" SET actulRetDaye=\'"+date+"\' WHERE cnNo=\'"+cnNo+"\' AND nian=\'"+nian+"\' AND juan=\'"+juan+"\' and qi=\'"+qi+"\';";

    QSqlQuery query;
    if(!query.exec(update))
    {
        QMessageBox::warning(this, "警告", "还书失败");
    }
    else
    {
        QMessageBox::information(this, "提示", "还书成功");
        this->close();
    }

}

returnBook::~returnBook()
{
    delete ui;
}
