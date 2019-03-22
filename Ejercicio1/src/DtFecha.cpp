
#include "../include/DtFecha.hpp"

// Constructor
DtFecha::DtFecha(int dia, int mes, int anio) {
    /* Crea el datavalue DtFecha asignando a los atributos los parametros
    dia, mes y anio respectivamente */
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

// Getters
int DtFecha::getDia() const {
    /* Retorna el dia del datavalue DtFecha */
    return this->dia;
}
   
int DtFecha::getMes() const {
    /* Retorna el mes del datavalue DtFecha */
    return this->mes;
}
    
int DtFecha::getAnio() const {
    /* Retorna el anio del datavalue DtFecha */
    return this->anio;
}

// Sobrecarga de operadores
bool DtFecha::operator>=(const DtFecha &fecha2) {
    if(this->getAnio() != fecha2.getAnio())
        return this->getAnio() >= fecha2.getAnio();
    else if(this->getMes() != fecha2.getMes())
        return this->getMes() >= fecha2.getMes();
    else 
        return this->getDia() >= fecha2.getDia();
}

bool DtFecha::operator==(const DtFecha &f2) {
    return (this->getAnio() == f2.getAnio()) && 
        (this->getMes() == f2.getMes()) && 
        (this->getDia() == f2.getDia());
}
