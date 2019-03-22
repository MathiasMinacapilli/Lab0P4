#ifndef _DTVIAJE_HPP
#define _DTVIAJE_HPP

#include "DtViajeBase.hpp"
#include "DtFecha.hpp"
#include "DtVehiculo.hpp"

class DtViaje: public DtViajeBase {
private:
    float precio_total;
    DtVehiculo vehiculo;
public:
    DtViaje(DtFecha, int, int, float, DtVehiculo);
    
    float getPrecioTotal() const;
    DtVehiculo getVehiculo() const;

    ~DtViaje();
};

#endif
