#ifndef FLIGHTMATRIX_H
#define FLIGHTMATRIX_H
#include <QHash>
#include <QString>
#include <QVector>

class Flightmatrix
{
public:
    Flightmatrix();
    Flightmatrix(QVector< QVector< int > > matrix, QHash<int, QString> map);
    QVector< QVector< int > > matrix;
    QHash<int, QString> map;

    QVector< QVector< int > > getMatrix();
    QHash<int, QString> getMap();

    void setMatrix(QVector< QVector< int > > m);
    void setMap(QHash<int, QString> m);
};

#endif // FLIGHTMATRIX_H
