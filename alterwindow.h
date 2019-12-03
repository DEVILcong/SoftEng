#ifndef ALTERWINDOW_H
#define ALTERWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QString>

namespace Ui {
class alterWindow;
}

class alterWindow : public QWidget
{
    Q_OBJECT

public:
    alterWindow(QString table, QWidget *parent = nullptr);
    ~alterWindow();

private:
    Ui::alterWindow *ui;
    QSqlTableModel *model;
};

#endif // ALTERWINDOW_H
