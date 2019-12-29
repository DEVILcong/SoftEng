#ifndef STUSEARCHBORROW_H
#define STUSEARCHBORROW_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class stuSearchBorrow;
}

class stuSearchBorrow : public QWidget
{
    Q_OBJECT

public:
    explicit stuSearchBorrow(QWidget *parent = nullptr, QString stuNO = NULL);
    ~stuSearchBorrow();

private:
    Ui::stuSearchBorrow *ui;
    QString table = "borrowList";
    QString stuNo;
    QString query;
    QSqlTableModel *model;
    void initilizeTable(void);

};

#endif // STUSEARCHBORROW_H
