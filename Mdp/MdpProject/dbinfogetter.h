#ifndef MATRIXGETTER_H
#define MATRIXGETTER_H

#include "dbinfogetterdao.h"
#include <QList>

namespace Ui {
    class DBInfoGetter;
}

class DBInfoGetter
{
public:
    DBInfoGetter();
    void printAllCountries();
    QList<QString> getAppropriateCountries(QString property);
    Flightmatrix getFlightMatrix();
};

#endif // MATRIXGETTER_H
