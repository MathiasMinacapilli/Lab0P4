#include "../include/DtViajeBase.hpp"

// Clase DtViajeBase
DtViajeBase::DtViajeBase(DtFecha fecha, int duracion, int distancia) {
    this->fecha = fecha;
    this->duracion = duracion;
    this->distancia = distancia;
}

DtFecha DtViajeBase::getFecha() const{
    return this->fecha;
}

int DtViajeBase::getDuracion() const{
    return this->duracion;
}

int DtViajeBase::getDistancia() const{
    return this->distancia;
}

DtViajeBase:: ~DtViajeBase(){}
