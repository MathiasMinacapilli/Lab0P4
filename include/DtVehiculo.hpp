
#include "TipoBici.hpp"

class DtVehiculo {
private:
    int nro_serie;
    float porcentaje, precio_base;
public:
    DtVehiculo(int=0, float=0, float=0);
    int getNroSerie();
    float getPorcentaje();
    float getPrecioBase();
    //~DtVehiculo()??
};

//DtMonopatin, heredero de DtVehiculo
class DtMonopatin: public DtVehiculo {
private:
    bool tieneLuces;
public:
    DtMonopatin(bool=false);
    bool getTieneLuces();
    //~DtMonopatin()??
};

//DtBicicleta, heredero de DtVehiculo
class DtBicicleta: public DtVehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
    DtBicicleta();
    TipoBici getTipo();
    int getCantCambios();
    //~DtBicicleta()??
};
