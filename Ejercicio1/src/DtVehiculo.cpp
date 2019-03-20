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


//DtMonopatin, subclase de DtVehiculo
DtMonopatin::DtMonopatin(int nro_serie, float porcentaje, float precio_base, bool tieneLuces) : DtVehiculo(nro_serie, porcentaje, precio_base) {
    this -> tieneLuces = tieneLuces;
}

bool DtMonopatin::getTieneLuces() {
    return tieneLuces;
}

DtMonopatin::~DtMonopatin() {
}

ostream &operator<< (ostream& o, DtMonopatin dtm) {
    std::string luces;
    if (dtm.getTieneLuces)
        luces = "Si";
    else
        luces = "No";
    o << "- Numero Serie: " << dtm.getNroSerie() << "\n" << "- Porcentaje Bateria: " << dtm.getPorcentaje() << "\n" << "- Precio Base: $" << dtm.getPrecioBase() << "." << "\n" << "- Tiene luces: " << luces;
}

//DtBicicleta, subclase de DtVehiculo
DtBicicleta::DtBicicleta(int nro_serie, float porcentaje, float precio_base, TipoBici tipo, int cant_cambios) : DtVehiculo(nro_serie, porcentaje, precio_base) {
    this -> tipo = tipo;
    this -> cant_cambios = cant_cambios;
}

TipoBici DtBicicleta::getTipo() {
    return tipo;
}

int DtBicicleta::getCantCambios() {
    return cant_cambios;
}


DtBicicleta::~DtBicicleta() {
}

ostream &operator<< (ostream& o, DtBicicleta dtb) {
    std::string tipo;
    if (dtb.getTipo == Paseo)
        tipo = "Paseo";
    else
        tipo = "Montaña";
    o << "- Numero Serie: " << dtb.getNroSerie() << "\n" << "- Porcentaje Bateria: " << dtb.getPorcentaje() << "\n" << "- Precio Base: $" << dtb.getPrecioBase() << "." << "\n" << "- Tipo de Bicicleta: " << tipo << "\n" << "- Cantidad de cambios: " << dtb.getCantCambios();
}






