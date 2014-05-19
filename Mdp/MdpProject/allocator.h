#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include "flightmatrix.h"
#include "city.h"
#include "village.h"
#include "country.h"
#include "graph.h"

namespace HolidayHelper {

template <class Location>
class Allocator
{
public:
    Allocator();
    graph<Location> *pointer();
};

}

#endif // ALLOCATOR_H
