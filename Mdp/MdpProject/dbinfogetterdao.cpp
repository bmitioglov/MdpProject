#include "dbinfogetterdao.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>


DBInfoGetterDAO& DBInfoGetterDAO::getInstance()
{
    static DBInfoGetterDAO instance;
    return instance;
}

DBInfoGetterDAO::DBInfoGetterDAO()
{
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
}


void DBInfoGetterDAO::printAllCountries(){

    QSqlQuery query;
    query.exec("SELECT * FROM countries");
    while (query.next()) {
        QString name = query.value(0).toString();
        qDebug() << name;
    }
}

QList<QString> DBInfoGetterDAO::getAppropriateCountriesFromDB(QString property){
    QList<QString>* list = new QList<QString>();
    QSqlQuery query;
    query.prepare(QString("select Country_Name from country_properties where Property_ID in (")+
               QString("select Property_ID from properties where Property_Name = :property)"));
    query.bindValue(":property", property);
    query.exec();
    while (query.next()) {
        QString name = query.value(0).toString();
        list->push_back(name);
    }
    QList<QString>::iterator it = list->begin();
    qDebug() << "Подходящие страны: ";
    if (list->size() == 0){
        qDebug() << "Подходящие страны не найдены";
    }
    while (it != list->end()) {
         qDebug() << "Element:" << *it;
         ++it;
    }
    return *list;
}

//Flightmatrix DBInfoGetterDAO::getFlightMatrix(){
//    QList<QString>* list = new QList<QString>();
//    QSqlQuery query;
//    query.prepare(QString("select Country_Name from country_properties where Property_ID in (")+
//               QString("select Property_ID from properties where Property_Name = :property)"));
//    query.bindValue(":property", property);
//    query.exec();
//    while (query.next()) {
//        QString name = query.value(0).toString();
//        list->push_back(name);
//    }
//}
