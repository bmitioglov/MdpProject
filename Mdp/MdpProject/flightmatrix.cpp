#include "flightmatrix.h"

Flightmatrix::Flightmatrix(int* matrix, QHash<int, QString> map)
{
    this->map = map;
    this->matrix = matrix;
}

int* Flightmatrix::getMatrix(){
    return matrix;
}

QHash<int, QString> Flightmatrix::getMap(){
    return map;
}

void Flightmatrix::setMatrix(int* m){
    matrix = m;
}

void Flightmatrix::setMap(QHash<int, QString> m){
    map = m;
}
