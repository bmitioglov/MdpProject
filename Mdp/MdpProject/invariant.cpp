#include "invariant.h"
#include <QMessageBox>

using namespace Vertex;

template <class Location>
Invariant<Location>::Invariant()
{
}

template <class Location>
void Invariant<Location>::checkLoc(graph<Location> *obj) {
    if (obj->location == NULL) {
        QMessageBox::critical(0, "Detection error", "Error in the object! (property: location)");
        return;
    }
}

template <class Location>
void Invariant<Location>::checkMatrix(graph<Location> *obj) {
    if (obj->fmatrix.matrix.length() == 0) {
        QMessageBox::critical(0, "Detection error", "Error in the object (property: matrix)!");
        return;
    }
}

template class Invariant<City>;
template class Invariant<Village>;
template class Invariant<Country>;
