#include "TipoBici.hpp"
#include <iostream>

class DtVehiculo {
private:
    int nro_serie;
    float porcentaje, precio_base;
public:
    int getNroSerie();
    float getPorcentaje();
    float getPrecioBase();
    ~DtVehiculo();
protected: 
    DtVehiculo(int=0, float=0, float=0);
};
