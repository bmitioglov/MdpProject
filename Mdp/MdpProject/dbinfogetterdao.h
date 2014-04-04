#ifndef MATRIXGETTERDAO_H
#define MATRIXGETTERDAO_H
#include <QtSql/QSqlDatabase>

namespace Ui{
    class MatrixGetterDAO;
}

class MatrixGetterDAO
{
public:
    MatrixGetterDAO();
    void getAllCountries();
};

#endif // MATRIXGETTERDAO_H
