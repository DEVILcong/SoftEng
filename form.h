#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QSqlDatabase *db, QWidget *parent = nullptr);
    ~Form();
    bool isLogin();

public slots:

private:
    Ui::Form *ui;
    QSqlDatabase *mainDB;
};

#endif // FORM_H
