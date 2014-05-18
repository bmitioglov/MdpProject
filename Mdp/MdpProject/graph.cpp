#include "graph.h"
#include "dbinfogetter.h"
#include <QDebug>

template <class Location>
graph<Location>::graph()
{
    this->location = new Location();
    DBInfoGetter* dbinfogetter = new DBInfoGetter();
    this->fmatrix = dbinfogetter->getFlightMatrix(location->getType());
    qDebug() << "location type = " << location->getType();

}

template <class Location>
Flightmatrix graph<Location>::getFlightMatrix(){
    return fmatrix;
}

template <class Location>
Location* graph<Location>::getCurrentLocation(){
    return location;
}

template class graph<City>;
template class graph<Village>;
template class graph<Country>;


