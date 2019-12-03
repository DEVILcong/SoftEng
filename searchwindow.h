#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include <QSqlQuery>
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QRadioButton>

namespace Ui {
class searchWindow;
}

class searchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit searchWindow(QWidget *parent = nullptr);
    ~searchWindow();

private:
    Ui::searchWindow *ui;

public slots:
    void search(void);

};

#endif // SEARCHWINDOW_H
