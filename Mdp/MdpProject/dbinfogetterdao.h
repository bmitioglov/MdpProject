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
        QList<QString> getAppropriateCountriesFromDB(QString property, QString site_type);
        Flightmatrix getFlightMatrix(QString site_type);
        static void printFlightMatrix(QVector< QVector< int > > matrix);
    private:
        DBInfoGetterDAO();
        DBInfoGetterDAO(DBInfoGetterDAO const&);
        void operator=(DBInfoGetterDAO const&);
        int getIndexByName(QHash<int, QString> map, QString name);

};

#endif // MATRIXGETTERDAO_H
