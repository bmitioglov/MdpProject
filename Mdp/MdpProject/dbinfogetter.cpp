#include "dbinfogetter.h"


MatrixGetter::MatrixGetter()
{

}

void MatrixGetter::getCountries(){
    MatrixGetterDAO* mgetterDAO = &MatrixGetterDAO();
    mgetterDAO->getAllCountries();
}
