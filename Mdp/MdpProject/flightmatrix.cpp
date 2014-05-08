#include "flightmatrix.h"

Flightmatrix::Flightmatrix(QVector< QVector< int > > matrix, QHash<int, QString> map)
{
    this->map = map;
    this->matrix = matrix;
}

Flightmatrix::Flightmatrix(){

}


QVector< QVector< int > > Flightmatrix::getMatrix(){
    return matrix;
}

QHash<int, QString> Flightmatrix::getMap(){
    return map;
}

void Flightmatrix::setMatrix(QVector< QVector< int > > m){
    matrix = m;
}

void Flightmatrix::setMap(QHash<int, QString> m){
    map = m;
}
