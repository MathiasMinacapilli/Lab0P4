#ifndef _VIAJE_HPP
#define _VIAJE_HPP


#include "DtFecha.hpp"
#include "Vehiculo.hpp"

class Viaje {
private:
    DtFecha fecha;
    int duracion, distancia;
    Vehiculo* vehiculo; //porque Vehiculo no es instanciable
    //Obs: ver como linkear con un tipo de vehiculo determinado
public:
    //constructor
    Viaje(DtFecha, int, int, Vehiculo*);
    //Getters
    DtFecha getFecha() const;
    int getDuracion() const;
    int getDistancia() const;
    Vehiculo* getVehiculo() const;

    //Setters
    void setFecha(DtFecha);
    void setDuracion(int);
    void setDistancia(int);
    
    ~Viaje();
};

#endif
