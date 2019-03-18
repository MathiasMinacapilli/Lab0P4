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
#include <ctime>
#include <stdio.h>

using namespace std;

#define MAX_USUARIOS ... //AGREGAR NUMERO
#define MAX_VEHICULOS ... //AGREGAR NUMERO

int tope_usuario, tope_vehiculo;
Usuario *arreglo_usuarios[MAX_USUARIOS];
//arreglo de punteros a vehiculos?
Vehiculo* arreglo_vehiculos[MAX_VEHICULOS];

/*
Busca si existe la cedula ci en el arreglo_usuarios.
Si existe, devuelve el numero de posicion del arreglo.
Sino, devuelve -1.
*/
static int existe_usuario(string ci) {

}

/*
Busca si existe el vehiculo con nroSerieVehiculo en el arreglo_vehiculos.
Si existe, devuelve el numero de posicion de ese vehiculo.
Sino, devuelve -1.
*/
static int existe_vehiculo(string ci) {

}



/*
Registra un en el sistema.
La fecha de ingreso se obtiene del reloj de la máquina.
Si existe un usuario registrado con la misma cédula,
se levanta una excepción std::invalid_argument.
*/
void registrarUsuario(std::string ci, std::string nombre) {
  if (existe_usuario(ci) == -1) {
    time_t t = time(0); //Se obtiene la fecha del momento
    tm* now = localtime(&t);
    DtFecha fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    arreglo_usuarios[tope_usuario] = new Usuario(ci, nombre, fecha /*, 0*/);
    tope_usuario++;
  }
  else //??
}

/*
Agrega un nuevo vehículo al sistema.
Controlar que se cumplen:
(1) no existe un vehículo con el mismo número de serie,
(2) porcentaje como valor entre 0 y 100 y
(3) precio base positivo.
De no ser así, se levanta una excepción std::invalid_argument.
*/
void agregarVehiculo(const DtVehiculo& vehiculo) {

}

/*
Crea un viaje entre el usuario y el vehículo identificados por ci y nroSerieVehiculo, respectivamente.
Controlar que se cumplen:
(1) existe un usuario registrado con esa ci,
(2) existe un vehículo registrado con ese nro serie,
(3) duración y distancia positivas y
(4) fecha del viaje posterior o igual a la fecha de ingreso del usuario.
De no ser así, se levanta una excepción std::invalid_argument.
*/
void ingresarViaje(string ci, int nroSerieVehiculo, const DtViajeBase& viaje) {
  int posicion_usuario = existe_usuario(ci);
  int posicion_vehiculo = existe_vehiculo(nroSerieVehiculo);
  if ((posicion_usuario != -1) && (posicion_vehiculo != -1) &&
      (viaje.getDuracion() > 0) && (viaje.getDistancia() > 0) &&
      (viaje.getFecha() >= arreglo_usuarios[posicion_usuario] -> getFechaIngreso())) {
        Viaje trip(viaje.getFecha(), viaje.getDuracion(), viaje.getDistancia(), arreglo_vehiculos[posicion_vehiculo]);
        arreglo_usuarios[posicion_usuario] -> agregarViaje(trip);
  }
  else //??
}


/*
Devuelve un arreglo con información detallada de los viajes
realizados por el usuario antes de cierta fecha.
Para poder implementar esta operación se deberá sobrecargar
el operador < (menor que) del tipo de datos (data type) DtFecha.
cantViajes es un parámetro de salida donde se devuelve la cantidad
de viajes encontrados (corresponde a la cantidad de valores DtViaje que se devuelven).
*/
DtViaje** verViajesAntesDeFecha(const DtFecha& fecha, string ci, int& cantViajes) {
    return nullptr;
}

/*
Elimina los viajes del usuario identificado por ci,
realizados en la fecha ingresada.
Si no existe un usuario registrado con esa cédula,
se levanta una excepción std::invalid_argument.
*/
void eliminarViajes(string ci, const DtFecha& fecha) {

}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por nroSerieVehiculo.
En caso de que el vehículo no exista,
o la carga ingresada no se encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {

}

/*
Devuelve un arreglo con los vehículos del sistema.
cantVehiculos es un parámetro de salida donde se
devuelve la cantidad de vehículos (corresponde a la cantidad de valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
    return nullptr;
}

// main
int main() {
    tope_usuario = 0;
    tope_vehiculo = 0;
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
