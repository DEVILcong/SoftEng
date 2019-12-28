#ifndef MENUUSER_H
#define MENUUSER_H

#include <QWidget>

namespace Ui {
class MenuUser;
}

class MenuUser : public QWidget
{
    Q_OBJECT

public:
    explicit MenuUser(QWidget *parent = nullptr);
    ~MenuUser();

private:
    Ui::MenuUser *ui;
};

#endif // MENUUSER_H
