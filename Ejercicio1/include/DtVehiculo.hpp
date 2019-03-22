#ifndef _DTVEHICULO_HPP
#define _DTVEHICULO_HPP

#include "TipoBici.hpp"
#include <iostream>

class DtVehiculo {
private:
    int nro_serie;
    float porcentaje, precio_base;
public:
    int getNroSerie() const;
    float getPorcentaje() const;
    float getPrecioBase() const;
    
    ~DtVehiculo();
protected: 
    DtVehiculo(int=0, float=0, float=0);
};

#endif
