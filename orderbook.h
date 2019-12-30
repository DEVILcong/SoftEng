#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTimer>

namespace Ui {
class orderBook;
}

class orderBook : public QWidget
{
    Q_OBJECT

public:
    explicit orderBook(QWidget *parent = nullptr);
    ~orderBook();

private:
    Ui::orderBook *ui;
    QSqlTableModel *table;
    QTimer *timer;
    QString tableName = "Next_magazine_subscription";
    void initilizeTable();
    void ifDerty(void);
};

#endif // ORDERBOOK_H
