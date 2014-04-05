#ifndef FLIGHTMATRIX_H
#define FLIGHTMATRIX_H
#include <QHash>

class Flightmatrix
{
public:
    Flightmatrix();
    int* matrix;
    QHash<int, QString> map;

    int* getMatrix();
    QHash<int, QString> getMap();

    void setMatrix(int* m);
    void setMap(QHash<int, QString> m);
};

#endif // FLIGHTMATRIX_H
