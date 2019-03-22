#ifndef _DTMONOPATIN_HPP
#define _DTMONOPATIN_HPP

#include "DtVehiculo.hpp"

using namespace std;

//DtMonopatin, subclase de DtVehiculo
class DtMonopatin: public DtVehiculo {
private:
    bool tieneLuces;
public:
    DtMonopatin(int=0, float=0, float=0, bool=false);
    bool getTieneLuces();
    ~DtMonopatin();
};

ostream &operator<< (ostream&, DtMonopatin);

#endif
