#ifndef CONTENTIN_H
#define CONTENTIN_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTimer>

namespace Ui {
class ContentIn;
}

class ContentIn : public QWidget
{
    Q_OBJECT

public:
    explicit ContentIn(QWidget *parent = nullptr);
    ~ContentIn();

private:
    Ui::ContentIn *ui;
    QSqlTableModel *table;
    QTimer *timer;

    void initilizeTable(void);

 public slots:
    void isDerty();
};

#endif // CONTENTIN_H
