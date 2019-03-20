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

/*ostream &operator<< (ostream& o, DtVehiculo dtv) {
    o << '- Numero Serie: ' << dtv.getNroSerie() << '/n' << '- Porcentaje Bateria: ' << dtv.getPorcentaje() << '/n' << '- Precio Base: $' << dtv.getPrecioBase() << '.' << '/n';
}*/
