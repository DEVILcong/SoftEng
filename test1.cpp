//#include <QApplication>
//#include <QSqlTableModel>
//#include <QSqlDatabase>
//#include <QSqlError>
//#include <QTableView>
//#include  <QDebug>

//#include <stdlib.h>

//void initializeModel(QSqlTableModel *model)
//{
//    model->setTable("person");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();

//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
//}

//QTableView *createView(QSqlTableModel *model, const QString &title = "")
//{
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->setWindowTitle(title);
//    return view;
//}

//int main(int argc, char *argv[])
//{
//    //qDebug()<<QCoreApplication::libraryPaths ();
//    QApplication app(argc, argv);

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setDatabaseName("test");
//    db.setPort(3306);
//    db.setHostName("127.0.0.1");
//    db.setUserName("liang");
//    db.setPassword("77777777");
//    if(!db.open())
//    {
//        QSqlError error = db.lastError();
//        qDebug()<< error.driverText();
//    }

//    QSqlTableModel model;

//    initializeModel(&model);

//    QTableView *view1 = createView(&model, QObject::tr("Table Model (View 1)"));
//    QTableView *view2 = createView(&model, QObject::tr("Table Model (View 2)"));

//    view1->show();
//    view2->move(view1->x() + view1->width() + 20, view1->y());
//    view2->show();

//    return app.exec();
//}
