#ifndef _DTVIAJEBASE_HPP
#define _DTVIAJEBASE_HPP

#include "DtFecha.hpp"
#include "DtVehiculo.hpp"
 
class DtViajeBase {
private:
    DtFecha fecha;
    int duracion, distancia;
public:
    DtViajeBase(DtFecha, int, int);
    DtFecha getFecha();
    int getDuracion();
    int getDistancia();
    ~DtViajeBase();
};
#endif
