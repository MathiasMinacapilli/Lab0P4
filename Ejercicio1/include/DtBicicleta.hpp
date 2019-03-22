#ifndef _DTBICICLETA_HPP
#define _DTBICICLETA_HPP

#include "DtVehiculo.hpp"

using namespace std;

//DtBicicleta, subclase de DtVehiculo
class DtBicicleta: public DtVehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
    DtBicicleta(int=0, float=0, float=0, TipoBici=Paseo, int=0);

    TipoBici getTipo() const;
    int getCantCambios() const;

    ~DtBicicleta();
};

ostream &operator<< (ostream&, DtBicicleta);

#endif
