
#include "../include/Viaje.hpp"


DtFecha Viaje::getFecha() {
    /* Retorna la fecha del Viaje */
    return this->fecha;
}
    
int Viaje::getDuracion() {
    /* Retorna la duracion del Viaje */
    return this->duracion;
}
    
int Viaje::getDistancia() {
    /* Retorna la distancia del Viaje */
    return this->distancia;
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