#ifndef BOOKIN_H
#define BOOKIN_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTimer>

namespace Ui {
class BookIn;
}

class BookIn : public QWidget
{
    Q_OBJECT

public:
    explicit BookIn(QWidget *parent = nullptr);
    ~BookIn();

public slots:
    //void insertRow();
    void ifDerty();

private:
    Ui::BookIn *ui;
    QSqlTableModel *table;
    QTimer *timer;
    void initilizeTable();
};

#endif // BOOKIN_H
