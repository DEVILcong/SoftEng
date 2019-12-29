#include "form.h"
#include "menuuser.h"
#include "loginwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase mainDB = QSqlDatabase::addDatabase("QMYSQL");
    Form mainWin(&mainDB);
    MenuUser user(&mainDB);
    loginwindow login(&mainWin, &user, &mainDB);
    login.show();
    return a.exec();
}
