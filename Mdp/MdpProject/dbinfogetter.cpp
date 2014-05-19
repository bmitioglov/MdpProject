#include "dbinfogetter.h"

using namespace DB;

DBInfoGetter::DBInfoGetter()
{

}

void DBInfoGetter::printAllCountries(){
    DBInfoGetterDAO::getInstance().printAllCountries();
}

QList<QString> DBInfoGetter::getAppropriateCountries(QString property, QString site_type){
    return DBInfoGetterDAO::getInstance().getAppropriateCountriesFromDB(property, site_type);
}

Flightmatrix DBInfoGetter::getFlightMatrix(QString site_type){
    return DBInfoGetterDAO::getInstance().getFlightMatrix(site_type);
}

