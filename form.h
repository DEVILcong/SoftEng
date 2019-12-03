#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "searchwindow.h"
#include "alterwindow.h"

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
    QSqlDatabase *mainDB;
};

#endif // FORM_H
