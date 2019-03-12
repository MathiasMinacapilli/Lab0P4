#include "../include/DtViajeBase.hpp"

// Clase DtViajeBase
DtViajeBase::DtViajeBase(DtFecha fecha, int duracion, int distancia) {
    this->fecha = fecha;
    this->duracion = duracion;
    this->distancia = distancia;
}

DtFecha DtViajeBase::getFecha() {
    return this->fecha;
}

int DtViajeBase::getDuracion() {
    return this->duracion;
}

int DtViajeBase::getDistancia() {
    return this->distancia;
}

//Clase DtViaje
DtViaje::DtViaje(float precio_total, DtVehiculo vehiculo) {
    this->precio_total = precio_total;
    this->vehiculo = vehiculo;
}

float DtViaje::getPrecioTotal() {
    return this->precio_total
}

DtVehiculo DtViaje::getVehiculo() {
    return this->vehiculo
}
