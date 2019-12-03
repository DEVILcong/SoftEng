#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include "loginwindow.h"
#include "searchwindow.h"
#include "alterwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    bool isLogin();
    loginwindow *login = nullptr;

public slots:
    void searchWinShow();
    void alterWinShow_build();
    void alterWinShow_room();
    void alterWindow_people();
    void alterWindow_worker();
    void alterWindow_charge();
    void alterWindow_quest();
    void messageBox_me();

private:
    Ui::Form *ui;
    searchWindow seWin;
    alterWindow *alWin;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");    //main database
};

#endif // FORM_H
