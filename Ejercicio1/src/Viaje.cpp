
#include "../include/Viaje.hpp"

//constructor
Viaje::Viaje(DtFecha fecha, int duracion, int distancia, Vehiculo* vehiculo){
    this->fecha = fecha;
    this->duracion = duracion;
    this->distancia = distancia;
    this->vehiculo = vehiculo;
}


DtFecha Viaje::getFecha() const{
    /* Retorna la fecha del Viaje */
    return this->fecha;
}
    
int Viaje::getDuracion() const{
    /* Retorna la duracion del Viaje */
    return this->duracion;
}
    
int Viaje::getDistancia() const{
    /* Retorna la distancia del Viaje */
    return this->distancia;
}


Vehiculo* Viaje::getVehiculo() const{
    return this->vehiculo;
}
    
void Viaje::setFecha(DtFecha fecha) {
    /* Le asigna al atributo fecha de Viaje el parametro fecha */
    this->fecha = fecha;
}

void Viaje::setDuracion(int duracion) {
    /* Le asigna al atributo duracion de Viaje el parametro duracion */
    this->duracion = duracion;
}

void Viaje::setDistancia(int distancia) {
    /* Le asigna al atributo distancia de Viaje el parametro duracion */
    this->distancia = distancia;
}

Viaje::~Viaje() {
    //destructor
}
