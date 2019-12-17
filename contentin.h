#ifndef CONTENTIN_H
#define CONTENTIN_H

#include <QWidget>

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
};

#endif // CONTENTIN_H
