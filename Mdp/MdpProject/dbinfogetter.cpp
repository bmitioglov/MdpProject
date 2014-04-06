#include "dbinfogetter.h"


DBInfoGetter::DBInfoGetter()
{

}

void DBInfoGetter::printAllCountries(){
    DBInfoGetterDAO::getInstance().printAllCountries();
}

QList<QString> DBInfoGetter::getAppropriateCountries(QString property){
    return DBInfoGetterDAO::getInstance().getAppropriateCountriesFromDB(property);
}

Flightmatrix DBInfoGetter::getFlightMatrix(){
    return DBInfoGetterDAO::getInstance().getFlightMatrix();
}

