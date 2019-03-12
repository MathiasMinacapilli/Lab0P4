 
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

//DtViaje sub(data) de D
class DtViaje: public DtViajeBase {
private:
    float precio_total;
    DtVehiculo vehiculo;
public:
    DtViaje(float, DtVehiculo);
    float getPrecioTotal();
    DtVehiculo getVehiculo();
    ~DtViajeBase();
};
