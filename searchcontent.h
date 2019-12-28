#ifndef SEARCHCONTENT_H
#define SEARCHCONTENT_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class searchContent;
}

class searchContent : public QWidget
{
    Q_OBJECT

public:
    explicit searchContent(QWidget *parent = nullptr);
    ~searchContent();

private:
    Ui::searchContent *ui;
    QSqlTableModel *model;
    QString table = "content";
    QString contentName;
    QString contentAuthor;
    QString contentKwd;
    QString query;
    void initilizeTable(void);

private slots:
    void searchName(void);
    void searchAuthor(void);
    void searchKwd(void);
};

#endif // SEARCHCONTENT_H
