#include "../include/DtVehiculo.hpp"
#include "../include/TipoBici.hpp"

//<<DataType>> DtVehiculo
int DtVehiculo::getNroSerie() {
  return nro_serie;
}

float DtVehiculo::getPorcentaje() {
  return porcentaje;
}

float DtVehiculo::getPrecioBase() {
  return precio_base;
}

//~DtVehiculo()??

//<<DataType>> DtMonopatin, heredero de DtVehiculo
bool DtMonopatin::getTieneLuces() {
  return tieneLuces;
}

//<<DataType>> DtBicicleta, heredero de DtVehiculo
DtBicicleta::DtBicicleta() {
  //??
}

TipoBici DtBicicleta::getTipo() {
  return tipo;
}

int DtBicicleta::getCantCambios() {
  return cant_cambios;
}

//~DtBicicleta()??
