#include "matrixgetterdao.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



MatrixGetterDAO::MatrixGetterDAO()
{
}


void MatrixGetterDAO::getAllCountries(){
    setbuf(stdout, NULL);
    qDebug() << "wtf";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");

    db.setDatabaseName("mdpschema");

    db.setUserName("root");
    db.setPassword("password");
    bool ok = db.open();
    printf(ok ? "true" : "false");
    qDebug() << "wtf2 + = "+ok;
    QSqlError error = db.lastError();
    printf("connection port = ");
    printf("n: %d:",db.port());
    qDebug() << "error text = " + error.text();
    printf(error.text().toLocal8Bit().data());
    //std::cout << "lalala\n";
    QSqlQuery query;
       query.exec("SELECT * FROM properties");
       while (query.next()) {
            QString name = query.value(0).toString();
            QString name2 = query.value(1).toString();
            qDebug() << name << name2;
          }
}
