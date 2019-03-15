
#include "../include/Usuario.hpp"

std::string Usuario::getCi() {
    /* Retorna la cedula del usuario de tipo string */
    return this->ci;
}

std::string Usuario::getNombre() {
    /* Retorna el nombre del usuario de tipo string */
    return this->nombre;
}

DtFecha Usuario::getFechaIngreso() {
    /* Retorna la fecha de ingreso del usuario de tipo DtFecha */
    return this->fecha_ingreso;
}

void Usuario::setCi(std::string ci) {
    /* Le asigna al atributo ci del usuario el parametro ci */
    this->ci = ci;
}

void Usuario::setNombre(std::string nombre) {
    /* Le asigna al atributo nombre del usuario el parametro nombre */
    this->nombre = nombre;
}
    
void Usuario::setFechaIngreso(DtFecha fecha_ingreso) {
    /* Le asigna al atributo fecha_ingreso del usuario el parametro fecha_ingreso */
    this->fecha_ingreso = fecha_ingreso;
}
    
Usuario::~Usuario() {
    // destructor
}