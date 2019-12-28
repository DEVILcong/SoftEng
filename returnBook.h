#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>

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
};

#endif // RETURNBOOK_H
