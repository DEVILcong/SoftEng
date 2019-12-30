#ifndef MENUUSER_H
#define MENUUSER_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include "search.h"
#include "searchcontent.h"
#include "stusearchborrow.h"
#include "orderbook.h"

namespace Ui {
class MenuUser;
}

class MenuUser : public QWidget
{
    Q_OBJECT

public:
    explicit MenuUser(QSqlDatabase *db, QWidget *parent = nullptr);
    ~MenuUser();

private:
    Ui::MenuUser *ui;
    search *searchB;
    searchContent *searchC;
    stuSearchBorrow *ssb;
    orderBook *order;
    QSqlDatabase *maindb;

    bool isLogin(void);

private slots:
    void winSearchB(void);
    void winSearchC(void);
    void winSearchBo(void);
    void winOrder(void);
};

#endif // MENUUSER_H
