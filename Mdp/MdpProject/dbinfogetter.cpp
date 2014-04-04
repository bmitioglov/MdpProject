#include "dbinfogetter.h"


DBInfoGetter::DBInfoGetter()
{
    dbInfoGetterDAO = &DBInfoGetterDAO();
}

void DBInfoGetter::printAllCountries(){
    dbInfoGetterDAO->printAllCountries();
}

QList<QString> DBInfoGetter::getAppropriateCountries(){
    return dbInfoGetterDAO->getAppropriateCountriesFromDB();
}

