#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include "flightmatrix.h"
#include "city.h"
#include "village.h"
#include "country.h"

template <class Location>
class Allocator
{
public:
    Allocator();
    Location *pointer();
};

#endif // ALLOCATOR_H
