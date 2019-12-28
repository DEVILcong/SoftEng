#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private:
    Ui::search *ui;
    QSqlTableModel *model;
    QString table = "Book";
    QString CN;
    QString name;
    QString query;
    void initilizeTable(void);

private slots:
    void searchCN(void);
    void searchName(void);
};

#endif // SEARCH_H
