#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>


QT_BEGIN_NAMESPACE
namespace Ui { class loginwindow; }
QT_END_NAMESPACE

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    loginwindow(QSqlDatabase *db, QWidget *parent = nullptr);
    ~loginwindow();
    int ifOpen = 1;  //to 0 if this closed

private:
    Ui::loginwindow *ui_login;
    QString name;
    QString passwd;
    QSqlDatabase *dbStar;

private slots:
    void ackClicked();
};
#endif // LOGINWINDOW_H
