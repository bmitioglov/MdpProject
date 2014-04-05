#ifndef MATRIXGETTERDAO_H
#define MATRIXGETTERDAO_H
#include <QtSql/QSqlDatabase>
#include "flightmatrix.h"

namespace Ui{
    class DBInfoGetterDAO;
}

class DBInfoGetterDAO
{
    public:
        static DBInfoGetterDAO& getInstance();
        void printAllCountries();
        QList<QString> getAppropriateCountriesFromDB(QString property);
        Flightmatrix getFlightMatrix();
    private:
        DBInfoGetterDAO();
        DBInfoGetterDAO(DBInfoGetterDAO const&);
        void operator=(DBInfoGetterDAO const&);
};

#endif // MATRIXGETTERDAO_H
