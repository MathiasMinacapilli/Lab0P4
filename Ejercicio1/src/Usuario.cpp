
#include "../include/Usuario.hpp"
#include <stdlib.h>


Usuario::Usuario(string ci, string nombre, DtFecha fecha_ingreso, int cant_viajes) {
    this->ci = ci;
    this->nombre = nombre;
    this->fecha_ingreso = fecha_ingreso;
    this->cant_viajes = cant_viajes;
    // Inicializo arreglo de Viajes
    for (int i = 0; i < 100; i++) {
        this->viajes[i] = nullptr;
    }
}

// --------Getters--------
std::string Usuario::getCi() const {
    /* Retorna la cedula del usuario de tipo string */
    return this->ci;
}
std::string Usuario::getNombre() const{
    /* Retorna el nombre del usuario de tipo string */
    return this->nombre;
}
DtFecha Usuario::getFechaIngreso() const{
    /* Retorna la fecha de ingreso del usuario de tipo DtFecha */
    return this->fecha_ingreso;
}
int Usuario::getCantViajes() const{
    /* Retorna la cantidad de viajes a los que está linkeado el usuario */
    return this->cant_viajes;
}
Viaje** Usuario::getViajes() {
    /* Retorna el array de viajes linkeado al usuario */
   return this->viajes;
}

// --------Setters--------
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

void Usuario::setCantViajes(int cant_viajes) {
    /* Le asigna al atributo cant_viajes del usuario el parametro cant_viajes */
    this ->cant_viajes = cant_viajes;
}

void Usuario::agregarViaje(Viaje* viaje) {
    /* Agrega un viaje al usuario en el arreglo viajes[100] y devuelve 1, en caso de ya haber
    100 viajes no hace nada y devuelve 0 */
    if (this->cant_viajes < 100) {
        // Si el arreglo no está lleno agrego el viaje al final
        this->viajes[cant_viajes] = viaje;
        this->cant_viajes++;

    }
}

Usuario::~Usuario() {
    //Libero la memoria de todos los viajes
    int i = 0;
    while (i<cant_viajes) {
        delete this->viajes[i];
        i++;
    }
}
