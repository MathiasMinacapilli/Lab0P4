#include "../include/DtViajeBase.hpp"
#include "../include/DtViaje.hpp"

DtViaje::DtViaje(DtFecha fecha, int duracion, int distancia, float precio_total, DtVehiculo* vehiculo)
    :DtViajeBase(fecha, duracion, distancia) {
        this->precio_total = precio_total;
        this->vehiculo = vehiculo;
}

float DtViaje::getPrecioTotal() const{
    return this->precio_total;
}

DtVehiculo* DtViaje::getVehiculo() const{
    return this->vehiculo;
}

DtViaje::~DtViaje(){}
