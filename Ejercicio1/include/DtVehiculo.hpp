
#include "TipoBici.hpp"
#include <iostream>

class DtVehiculo {
private:
    int nro_serie;
    float porcentaje, precio_base;
public:
    DtVehiculo(int=0, float=0, float=0);
    int getNroSerie();
    float getPorcentaje();
    float getPrecioBase();
    ~DtVehiculo();
};



//DtMonopatin, subclase de DtVehiculo
class DtMonopatin: public DtVehiculo {
private:
    bool tieneLuces;
public:
    DtMonopatin(int=0, float=0, float=0, bool=false);
    bool getTieneLuces();
    DtMonopatin operator<<();
    ~DtMonopatin();
};

ostream &operator<< (ostream&, DtMonopatin);

//DtBicicleta, subclase de DtVehiculo
class DtBicicleta: public DtVehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
    DtBicicleta(int=0, float=0, float=0, TipoBici, int=0);
    TipoBici getTipo();
    int getCantCambios();
    DtBicicleta operator<<();
    ~DtBicicleta();
};

ostream &operator<< (ostream&, DtBicicleta);
