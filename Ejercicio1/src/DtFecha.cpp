
#include "../include/DtFecha.hpp"

// Constructor
DtFecha::DtFecha(int dia, int mes, int anio) {
    /* Crea el datavalue DtFecha asignando a los atributos los parametros
    dia, mes y anio respectivamente */
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

//Getters
int DtFecha::getDia() {
    /* Retorna el dia del datavalue DtFecha */
    return this->dia;
}
   
int DtFecha::getMes() {
    /* Retorna el mes del datavalue DtFecha */
    return this->mes;
}
    
int DtFecha::getAnio() {
    /* Retorna el anio del datavalue DtFecha */
    return this->anio;
}

//Sobrecarga el operador >=
bool operator>=(DtFecha fecha1, DtFecha fecha2) {
    if(fecha1.getAnio() != fecha2.getAnio())
        return fecha1.getAnio() >= fecha2.getAnio();
    else if(fecha1.getMes() != fecha2.getMes())
        return fecha1.getMes() >= fecha2.getMes();
    else 
        return fecha1.getDia() >= fecha2.getDia();
}
