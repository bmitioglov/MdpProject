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
    DBInfoGetterDAO* dbInfoGetterDAO;
    void printAllCountries();
    QList<QString> getAppropriateCountries();
};

#endif // MATRIXGETTER_H
