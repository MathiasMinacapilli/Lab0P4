
#include "DtFecha.hpp"
#include "DtVehiculo.hpp"

class Viaje {
private:
    DtFecha fecha;
    int duracion, distancia;
    DtVehiculo vehiculo; //porque Vehiculo no es instanciable
    //Obs: ver como linkear con un tipo de vehiculo determinado
public:
    //Setters
    DtFecha getFecha();
    int getDuracion();
    int getDistancia();

    //Getters
    void setFecha(DtFecha);
    void setDuracion(int);
    void setDistancia(int);
    
    ~Viaje();
};
