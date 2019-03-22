#include "../include/DtBicicleta.hpp"

//DtBicicleta, subclase de DtVehiculo
DtBicicleta::DtBicicleta(int nro_serie, float porcentaje, float precio_base, TipoBici tipo, int cant_cambios) : DtVehiculo(nro_serie, porcentaje, precio_base) {
    this -> tipo = tipo;
    this -> cant_cambios = cant_cambios;
}

TipoBici DtBicicleta::getTipo() const{
    return tipo;
}

int DtBicicleta::getCantCambios() const{
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
