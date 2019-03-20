#include "DtViajeBase.hpp"
#include "DtFecha.hpp"
#include "DtVehiculo.hpp"

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
