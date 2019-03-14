#include "../include/DtVehiculo.hpp"
#include "../include/TipoBici.hpp"

//DtVehiculo

DtVehiculo ::DtVehiculo(int nro_serie, float porcentaje, float precio_base) {
    this -> nro_serie = nro_serie;
    this -> porcentaje = porcentaje;
    this -> precio_base = precio_base;
    
}

int DtVehiculo::getNroSerie() {
  return nro_serie;
}

float DtVehiculo::getPorcentaje() {
  return porcentaje;
}

float DtVehiculo::getPrecioBase() {
  return precio_base;
}

DtVehiculo::~DtVehiculo() {
}

//DtMonopatin, subclase de DtVehiculo
DtMonopatin::DtMonopatin(bool tieneLuces) {
    this -> tieneLuces = tieneLuces;
}

bool DtMonopatin::getTieneLuces() {
  return tieneLuces;
}

//DtBicicleta, subclase de DtVehiculo
DtBicicleta::DtBicicleta(int nro_serie, float porcentaje, float precio_base, TipoBici tipo, int cant_cambios) {
  DtVehiculo(nro_serie, porcentaje, precio_base);
  this -> tipo = tipo;
}

TipoBici DtBicicleta::getTipo() {
  return tipo;
}

int DtBicicleta::getCantCambios() {
  return cant_cambios;
}


DtBicicleta::~DtBicicleta() {
}
