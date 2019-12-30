#ifndef BORROW_H
#define BORROW_H

#include <QWidget>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class borrow;
}

class borrow : public QWidget
{
    Q_OBJECT

public:
    explicit borrow(QWidget *parent = nullptr);
    ~borrow();

private:
    Ui::borrow *ui;
    QString table = "borrowList";
    QString bookTable = "Book";
    QString cnNo;
    QString nian;
    QString juan;
    QString qi;
    QString stuNo;
    QDate borrowDate;
    QString borrowDays;
    QDate returnDate;
    QDate actulRetDate;

private slots:
    void process(void);
};

#endif // BORROW_H
