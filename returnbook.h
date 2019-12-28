#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class returnBook;
}

class returnBook : public QWidget
{
    Q_OBJECT

public:
    explicit returnBook(QWidget *parent = nullptr);
    ~returnBook();

private:
    Ui::returnBook *ui;
    QString table = "borrowList";
    QString cnNo;
    QString nian;
    QString juan;
    QString qi;
    QString stuNo;

private slots:
    void process(void);
};

#endif // RETURNBOOK_H
