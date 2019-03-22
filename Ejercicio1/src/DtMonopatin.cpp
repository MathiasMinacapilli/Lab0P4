#include "../include/DtMonopatin.hpp"

//DtMonopatin, subclase de DtVehiculo
DtMonopatin::DtMonopatin(int nro_serie, float porcentaje, float precio_base, bool tieneLuces) : DtVehiculo(nro_serie, porcentaje, precio_base) {
    this -> tieneLuces = tieneLuces;
}

bool DtMonopatin::getTieneLuces() const{
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
