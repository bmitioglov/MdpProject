#ifndef GRAPH_H
#define GRAPH_H
#include "flightmatrix.h"
#include "city.h"
#include "village.h"
#include "country.h"

template <class Location>
class graph
{
public:
    graph();
    Flightmatrix fmatrix;
    Location* location;
    Flightmatrix getFlightMatrix();
    Location* getCurrentLocation();
};

#endif // GRAPH_H
