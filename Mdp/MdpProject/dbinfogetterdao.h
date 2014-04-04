#ifndef MATRIXGETTERDAO_H
#define MATRIXGETTERDAO_H
#include <QtSql/QSqlDatabase>

namespace Ui{
    class DBInfoGetterDAO;
}

class DBInfoGetterDAO
{
public:
    DBInfoGetterDAO();
    void printAllCountries();
    QList<QString> getAppropriateCountriesFromDB();
};

#endif // MATRIXGETTERDAO_H
