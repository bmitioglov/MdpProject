#include "allocator.h"

using namespace HolidayHelper;
using namespace Vertex;

template <class Location>
Allocator<Location>::Allocator()
{
}

template <class Location>
graph<Location> *Allocator<Location>::pointer() {
    graph<Location> *loc = new graph<Location>();
    return loc;
}

template class Allocator<City>;
template class Allocator<Village>;
template class Allocator<Country>;


