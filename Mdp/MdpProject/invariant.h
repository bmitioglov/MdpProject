#ifndef INVARIANT_H
#define INVARIANT_H

#include "graph.h"
#include "city.h"
#include "village.h"
#include "country.h"

template <class Location>
class Invariant
{
public:
    Invariant<Location>();
    void checkLoc(graph<Location> *obj);
    void checkMatrix(graph<Location> *obj);
};

#endif // INVARIANT_H
