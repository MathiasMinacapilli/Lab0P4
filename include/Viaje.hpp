
#include "DtFecha.hpp"

class Viaje {
private:
    DtFecha fecha;
    int duracion, distancia;
public:
    DtFecha getFecha();
    int getDuracion();
    int getDistancia();
    void setFecha();
    void setDuracion();
    void setDistancia();
};
