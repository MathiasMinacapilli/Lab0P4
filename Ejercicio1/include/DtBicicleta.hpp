#include "DtVehiculo.hpp"

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
