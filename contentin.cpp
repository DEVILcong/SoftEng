#include "contentin.h"
#include "ui_contentin.h"

ContentIn::ContentIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContentIn)
{
    ui->setupUi(this);
}

ContentIn::~ContentIn()
{
    delete ui;
}
