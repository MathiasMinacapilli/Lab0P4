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
