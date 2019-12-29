#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "bookin.h"
#include "borrow.h"
#include "contentin.h"
#include "returnbook.h"
#include "search.h"
#include "searchborrow.h"
#include "searchcontent.h"
#include "searchuser.h"

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
    BookIn *bookIn;
    ContentIn *contentIn;
    borrow *borrowWin;
    returnBook *returnB;
    search *searchB;
    searchContent *searchC;
    searchBorrow *searchBo;
    searchUser *searchU;

private slots:
    void winBookIn(void);
    void winContentIn(void);
    void winBorrow(void);
    void winReturn(void);
    void winSearchB(void);
    void winSearchC(void);
    void winSearchBo(void);
    void winSearchU(void);
};

#endif // FORM_H
