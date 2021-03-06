#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>

#include "form.h"
#include "menuuser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginwindow; }
QT_END_NAMESPACE

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    loginwindow(Form *mainWin, MenuUser *user, QSqlDatabase *db, QWidget *parent = nullptr);
    ~loginwindow();

private:
    Ui::loginwindow *ui;
    Form *mainWindow;
    MenuUser *menuUser;
    QSqlDatabase *maindb;
    QString name;
    QString passwd;

private slots:
    void ackClicked();
};
#endif // LOGINWINDOW_H
