#ifndef SEARCHBORROW_H
#define SEARCHBORROW_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class searchBorrow;
}

class searchBorrow : public QWidget
{
    Q_OBJECT

public:
    explicit searchBorrow(QWidget *parent = nullptr);
    ~searchBorrow();

private:
    Ui::searchBorrow *ui;
    QString table = "borrowList";
    QString cnNo;
    QString nian;
    QString juan;
    QString qi;
    QString stuNo;
    QString query;
    QSqlTableModel *model;
    void initilizeTable(void);

private slots:
    void searchBook(void);
    void searchStu(void);
};

#endif // SEARCHBORROW_H
