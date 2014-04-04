#include "dbinfogetterdao.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



MatrixGetterDAO::MatrixGetterDAO()
{
}


void MatrixGetterDAO::getAllCountries(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mdpschema");
    db.setUserName("root");
    db.setPassword("password");
    bool ok = db.open();
    qDebug() << "db connection status = " << ok;
    QSqlError error = db.lastError();
    if (ok == false){
        qDebug() << "error text = " + error.text();
    }
    printf(error.text().toLocal8Bit().data());
    QSqlQuery query;
       query.exec("SELECT * FROM countries");
       while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << name;
          }
}
