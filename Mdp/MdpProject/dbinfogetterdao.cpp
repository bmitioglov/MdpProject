#include "dbinfogetterdao.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>


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

QList<QString> DBInfoGetterDAO::getAppropriateCountriesFromDB(QString property, QString site_type){
    QList<QString>* list = new QList<QString>();
    QList<QString>* list2 = new QList<QString>();
    QSqlQuery query;
    query.prepare(QString("select Country_Name from country_properties where Property_ID in  ")+
                  QString("(select Property_ID from properties where Property_Name = :property )")+
                  QString("and Country_Name in (select Country_Name from countries where site_type= :site_type)"));
    qDebug() << "BIND1 = " <<property;
    qDebug() << "BIND2 = " <<site_type;
    query.bindValue(":property", property);
    query.bindValue(":site_type", site_type);
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

Flightmatrix DBInfoGetterDAO::getFlightMatrix(QString site_type){
    QHash<int, QString>* hashmap = new QHash<int, QString>();

    QSqlQuery query1;
    QSqlQuery query2;
    int i = 0;
    int countriessize;

    query1.exec("select * from countries");
    while (query1.next()) {
        QString name = query1.value(0).toString();
        hashmap->insert(i, name);
        i++;
    }
    countriessize = i++;
    QVector< QVector< int > > twoDArray(countriessize); // Contains countriessize int arrays.

    int k = 0;
    int j = 0;
    while (k < countriessize){
        twoDArray[k].resize(countriessize);
        while (j < countriessize){
            twoDArray[k][j] = 0;
            if (k==j){
                qDebug() << "1 SETTED!";
                twoDArray[k][j] = 1;
            }
            j++;
        }
        j = 0;
        k++;
    }

    query2.exec("select * from flights");
    while (query2.next()) {
        QString flightid = query2.value(0).toString();
        QString countryto = query2.value(1).toString();
        QString countryfrom = query2.value(2).toString();
        QString flighttime = query2.value(3).toString();
        int indexFrom = getIndexByName(*hashmap, countryfrom);
        int indexTo = getIndexByName(*hashmap, countryto);
        int flightTime = flighttime.toInt();
        qDebug() << "index from = " <<indexFrom << "index to = " <<indexTo << "flighttime = "<<flightTime;
        twoDArray[indexFrom][indexTo] = flightTime;
        //qDebug() << flightid << countryfrom << countryto << flighttime;

    }
    qDebug() << "index = " << getIndexByName(*hashmap, "Россия");
//    printFlightMatrix(twoDArray);
    return  *new Flightmatrix(twoDArray, *hashmap);
}


void DBInfoGetterDAO::printFlightMatrix(QVector<QVector<int> > matrix){
    setbuf(stdout, NULL);
    int i = 0;
    int j = 0;
    while (i < matrix.size()){
        QString str;
        while (j < matrix.size()){
            str += str.setNum(matrix[i][j])+" ";

//          qDebug() << "index i = " << i << "indexj = "<<j << "element = "<<matrix[i][j];
            QTextStream(stdout) << matrix[i][j] << " ";
            j++;
        }
        QTextStream(stdout) << "\n";
        j = 0;
        i++;
    }
    qDebug() << "element!!! 1 - 1 = " << matrix[1][1];
    qDebug() << "element!!! 0 - 0 = " << matrix[0][0];
    qDebug() << "element!!! 0 - 2 = " << matrix[0][2];
}


int DBInfoGetterDAO::getIndexByName(QHash<int, QString> map, QString name){
    QList<int> keyslist = map.keys();
    QList<int>::iterator keysIt = keyslist.begin();

    while (keysIt != keyslist.end()) {
        if (map.value(*keysIt)==name){
            return *keysIt;
        }
        ++keysIt;
    }
    return -1;
}

