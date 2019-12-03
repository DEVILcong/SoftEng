#include "form.h"
#include "loginwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase mainDB = QSqlDatabase::addDatabase("QMYSQL");
    Form mainWin(&mainDB);
    loginwindow login(&mainWin, &mainDB);
    login.show();

    return a.exec();
}
