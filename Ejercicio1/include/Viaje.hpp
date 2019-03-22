#ifndef _VIAJE_HPP
#define _VIAJE_HPP


#include "DtFecha.hpp"
#include "Vehiculo.hpp"

class Viaje {
private:
    DtFecha fecha;
    int duracion, distancia;
    Vehiculo vehiculo; //porque Vehiculo no es instanciable
    //Obs: ver como linkear con un tipo de vehiculo determinado
public:
    //constructor
    Viaje(DtFecha, int, int, Vehiculo);
    //Setters
    DtFecha getFecha();
    int getDuracion();
    int getDistancia();
    Vehiculo getVehiculo();

    //Getters
    void setFecha(DtFecha);
    void setDuracion(int);
    void setDistancia(int);
    
    ~Viaje();
};

#endif
