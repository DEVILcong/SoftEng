#ifndef BOOKIN_H
#define BOOKIN_H

#include <QWidget>

namespace Ui {
class BookIn;
}

class BookIn : public QWidget
{
    Q_OBJECT

public:
    explicit BookIn(QWidget *parent = nullptr);
    ~BookIn();

private:
    Ui::BookIn *ui;
};

#endif // BOOKIN_H
