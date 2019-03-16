/*** Laboratorio 0 de Programacion 4 ***/
/*** Ejercicio 1 ***/

#include "include/DtFecha.hpp"
#include "include/DtVehiculo.hpp"
#include "include/DtViajeBase"
#include "include/TipoBici.hpp"
#include "include/Usuario.hpp"
#include "include/Vehiculo.hpp"
#include "include/Viaje.hpp"

#include <iostream>
#include <stdio.h>

#define MAX_USUARIOS ... //AGREGAR NUMERO
#define MAX_VEHICULOS ... //AGREGAR NUMERO

Usuario arreglo_usuarios[MAX_USUARIOS];
//arreglo de punteros a vehiculos?
Vehiculo* arreglo_vehiculos[MAX_VEHICULOS];

void registrarUsuario(std::string ci, std::string nombre) {

}
void agregarVehiculo(const DtVehiculo& vehiculo) {

}
void ingresarViaje(string ci, int nroSerieVehiculo, const DtViajeBase& viaje) {

}
DtViaje** verViajesAntesDeFecha(const DtFecha& fecha, string ci, int& cantViajes) {
    return nullptr;
}
void eliminarViajes(string ci, const DtFecha& fecha) {

}
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {

}
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
    return nullptr;
}

// main
int main() {
    int i = 0;
    bool salir = false;
    while(!salir) {
        std::cout << 'Bienvenido. Elija la opción deseada. \n'
            << '1) Registrar un Usuario \n'
            << '2) Agregar un Vehiculo \n'
            << '3) Agregar un Viaje \n'
            << '4) Ver viajes de un Usuario \n'
            << '5) Eliminar viajes de un Usuario \n'
            << '6) Cambiar bateria de un Vehiculo \n'
            << '7) Obtener Vehiculos \n'
            << '0) Salir \n'
            << 'Opción: ';
        std::cin >> i;
        switch(i) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            salir = true;
            break;
        }
    }
    
    
    
    
    
    
    
    
    
    
    return 0;
}
