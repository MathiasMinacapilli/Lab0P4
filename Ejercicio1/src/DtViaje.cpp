#include "../include/DtViajeBase.hpp"
#include "../include/DtViaje.hpp"

DtViaje::DtViaje(float precio_total, DtVehiculo vehiculo) {
    this->precio_total = precio_total;
    this->vehiculo = vehiculo;
}

float DtViaje::getPrecioTotal() {
    return this->precio_total;
}

DtVehiculo DtViaje::getVehiculo() {
    return this->vehiculo;
}
