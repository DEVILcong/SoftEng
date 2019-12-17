#include "bookin.h"
#include "ui_bookin.h"

BookIn::BookIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookIn)
{
    ui->setupUi(this);
}

BookIn::~BookIn()
{
    delete ui;
}
