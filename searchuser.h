#ifndef SEARCHUSER_H
#define SEARCHUSER_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class searchUser;
}

class searchUser : public QWidget
{
    Q_OBJECT

public:
    explicit searchUser(QWidget *parent = nullptr);
    ~searchUser();

private:
    Ui::searchUser *ui;
    QString table = "userList";
    QString stuNo;
    QString name;
    QString grade;
    QString graduate;
    QSqlTableModel *model;
    QString query;
    void initilizeTable(void);

private slots:
    void searchNo(void);
    void searchName(void);
    void searchGrade(void);
    void searchGraduate(void);
};

#endif // SEARCHUSER_H
