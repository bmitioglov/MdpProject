#include "allocator.h"

template <class Location>
Allocator<Location>::Allocator()
{
}

template <class Location>
Location *Allocator<Location>::pointer() {
    Location *loc = new Location();
    return loc;
}

template class Allocator<City>;
template class Allocator<Village>;
template class Allocator<Country>;


