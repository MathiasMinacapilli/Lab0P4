/*** Laboratorio 0 de Programacion 4 ***/
/*** Ejercicio 1 ***/

#include "include/Bicicleta.hpp"
#include "include/DtBicicleta.hpp"
#include "include/DtFecha.hpp"
#include "include/DtMonopatin.hpp"
#include "include/DtVehiculo.hpp"
#include "include/DtViajeBase.hpp"
#include "include/DtViaje.hpp"
#include "include/Monopatin.hpp"
#include "include/TipoBici.hpp"
#include "include/Usuario.hpp"
#include "include/Vehiculo.hpp"
#include "include/Viaje.hpp"

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <algorithm> //all_of
#include <stdlib.h> //system("");

using namespace std;

#define MAX_USUARIOS 100 //AGREGAR NUMERO
#define MAX_VEHICULOS 100 //AGREGAR NUMERO

int tope_usuario, tope_vehiculo;
Usuario *arreglo_usuarios[MAX_USUARIOS];
//arreglo de punteros a vehiculos
Vehiculo *arreglo_vehiculos[MAX_VEHICULOS];

/*
Retorna true si y solo si str esta compuesto solamente por digitos
*/
static bool son_digitos(string ci) {
    return all_of(ci.begin(), ci.end(), ::isdigit);
}

static string conseguir_cedula() {
    cout << "Ingrese la cédula del usuario sin guión y con dígito verificador. \n"
        << " Cédula: ";
    string ci;
    cin >> ci;
    while ((ci.size() != 8) || (!son_digitos(ci))) {
        cout << "Cédula no válida. Ingrese la cédula del usuario sin guión y con dígito verificador. \n"
            << " Cédula: ";
        cin >> ci;
    }
    return ci;
}

static void conseguir_datos_vehiculo(int &nro_serie, float &porcentaje, float &precio_base) {
    cout << "Ingrese el número de serie. \n"
        << " Nº de serie: ";
    cin >> nro_serie;
    cout << "Ingrese el porcentaje de batería. \n"
        << " Porcentaje (%) batería: ";
    cin >> porcentaje;
    cout << "Ingrese el precio base del vehículo. \n"
        << " Precio base: ";
    cin >> precio_base;
}

static DtFecha conseguir_fecha() {
    int dia, mes, anio;
    cout << "Ingrese la fecha del viaje. \n"
        << " dd/mm/aaaa: ";
    cin >> dia;
    cin.get();
    cin >> mes;
    cin.get();
    cin >> anio;
    return DtFecha(dia, mes, anio);
}

/*
Busca si existe la cedula cid en el arreglo_usuarios.
Si existe, devuelve el numero de posicion del arreglo.
Sino, devuelve -1.
*/
static int buscar_usuario(string cid) {
    bool encontre = false;
    int i = 0;
    while (!encontre && i<tope_usuario) {
        if (arreglo_usuarios[i] -> getCi().compare(cid) == 0)
            encontre = true;
        else
            i++;
    }
    if (encontre)
        return i;
    else
        return -1;
}

/*
Busca si existe el vehiculo con numserie en el arreglo_vehiculos.
Si existe, devuelve el numero de posicion de ese vehiculo.
Sino, devuelve -1.
*/
static int buscar_vehiculo(int numserie) {
    bool encontre = false;
    int i = 0;
    while (!encontre && i<tope_vehiculo) {
        if (arreglo_vehiculos[i] -> get_nro_serie() == numserie)
            encontre = true;
        else
            i++;
    }
    if (encontre)
        return i;
    else
        return -1;
}

/*
Registra un en el sistema.
La fecha de ingreso se obtiene del reloj de la máquina.
Si existe un usuario registrado con la misma cédula,
se levanta una excepción std::invalid_argument.
*/
void registrarUsuario(std::string ci, std::string nombre) {
    if (buscar_usuario(ci) == -1) {
        time_t t = time(0); //Se obtiene la fecha del momento
        tm* now = localtime(&t);
        DtFecha fecha(now -> tm_mday, now -> tm_mon + 1, now -> tm_year + 1900);
        arreglo_usuarios[tope_usuario] = new Usuario(ci, nombre, fecha , 0);
        tope_usuario++;
    }
    else
        throw new invalid_argument ("Ya existe un usuario con esa cédula de identidad.");
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
    if (tope_vehiculo == MAX_VEHICULOS)
        throw new invalid_argument ("No hay más lugar para vehículos.");
    else {
        if (buscar_vehiculo(vehiculo.getNroSerie()) == -1) {
            if (0 <= vehiculo.getPorcentaje() && vehiculo.getPorcentaje() <= 100) {
                if (vehiculo.getPrecioBase() >= 0) {
                    const DtVehiculo* v = &vehiculo;
                    const DtBicicleta* dtb = dynamic_cast<DtBicicleta*>(const_cast<DtVehiculo*>(v));
                    if (dtb != nullptr) {
                        Bicicleta *bici = new Bicicleta(dtb->getNroSerie(), dtb->getPorcentaje(), dtb->getPrecioBase(), dtb->getTipo(), dtb->getCantCambios());
                        arreglo_vehiculos[tope_vehiculo] = bici;
                    }
                    else { //Es monopatin
                        const DtMonopatin* dtm = dynamic_cast<DtMonopatin*>(const_cast<DtVehiculo*>(v));
                        Monopatin *mono = new Monopatin(dtm->getNroSerie(), dtm->getPorcentaje(), dtm->getPrecioBase(), dtm->getTieneLuces());
                        arreglo_vehiculos[tope_vehiculo] = mono;
                    }
                    tope_vehiculo++;
                }
                else
                    throw new invalid_argument ("Precio base ingresado inválido. Debe ingresar un valor positivo.");
            }
            else
                throw new invalid_argument ("Porcentaje ingresado inválido. Debe ser un porcentaje entre 0 y 100.");
        }
        else
            throw new invalid_argument ("Número de serie ingresado inválido. Ingrese otro valor.");
    }
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
    int posicion_usuario = buscar_usuario(ci);
    int posicion_vehiculo = buscar_vehiculo(nroSerieVehiculo);
    if (posicion_usuario != -1) {
        if (posicion_vehiculo != -1) {
            if (viaje.getDuracion() > 0) {
                if (viaje.getDistancia() > 0) {
                    if (viaje.getFecha() >= arreglo_usuarios[posicion_usuario] -> getFechaIngreso()) {
                        Viaje* trip = new Viaje(viaje.getFecha(), viaje.getDuracion(), viaje.getDistancia(), arreglo_vehiculos[posicion_vehiculo]);
                        arreglo_usuarios[posicion_usuario] -> agregarViaje(trip);
                    }
                    else
                        throw new invalid_argument ("Fecha ingresada inválida.");
                }
                else
                    throw new invalid_argument ("Distancia ingresada inválida.");
            }
            else
                throw new invalid_argument ("Duración ingresada inválida.");
        }
        else
            throw new invalid_argument ("No existe vehículo ingresado");
    }
    else
        throw new invalid_argument ("No existe usuario ingresado.");
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
    int j = 0;
    cantViajes = 0;
    DtViaje** arreglo_dtv = new DtViaje*[100];
    for (int i =0; i<100; i++)
        arreglo_dtv[i] = nullptr;
    int posicion_usuario = buscar_usuario(ci);
    if(posicion_usuario != -1) { // Si se encontro el usuario con esa cedula de identidad
        Viaje** viajes_usuario = (arreglo_usuarios[posicion_usuario] -> getViajes());
        for(int i = 0; i < arreglo_usuarios[posicion_usuario] -> getCantViajes(); i++) {
            //Cuenta la cantidad de viajes que hay con menor fecha que la recibida por parametro.
            if(!(viajes_usuario[i] -> getFecha() >= fecha))
                j++;
        }
        cantViajes = j;
        if (j != 0) {
            int k = 0;
                for (int i = 0; i<j; i++){
                    if (!(viajes_usuario[i] -> getFecha() >= fecha)) {
                        Vehiculo* v = (viajes_usuario[i] -> getVehiculo());;
                        Bicicleta* bici = dynamic_cast<Bicicleta*>(v);
                        if (bici != nullptr) {
                            DtBicicleta* b = new DtBicicleta(bici -> get_nro_serie(), bici -> get_porcentaje_bateria(), bici -> get_precio_base(), bici -> get_tipo(), bici -> get_cant_cambios());
                            arreglo_dtv[k] = new DtViaje(viajes_usuario[i] -> getFecha(), viajes_usuario[i] -> getDuracion(), viajes_usuario[i] -> getDistancia(), viajes_usuario[i] -> getVehiculo() -> darPrecioViaje(viajes_usuario[i] -> getDuracion(), viajes_usuario[i] -> getDistancia()), b);
                        }
                        else {
                            Monopatin* mono=dynamic_cast<Monopatin*>(v);
                            DtMonopatin* m = new DtMonopatin(mono -> get_nro_serie(), mono -> get_porcentaje_bateria(), mono -> get_precio_base(), mono -> get_luces());
                            arreglo_dtv[k] = new DtViaje(viajes_usuario[i] -> getFecha(), viajes_usuario[i] -> getDuracion(), viajes_usuario[i] -> getDistancia(), viajes_usuario[i] -> getVehiculo() -> darPrecioViaje(viajes_usuario[i] -> getDuracion(), viajes_usuario[i] -> getDistancia()), m);
                        }
                        k++;
                    }
                }
        }
    }
    return arreglo_dtv;
}

/*
Elimina los viajes del usuario identificado por ci,
realizados en la fecha ingresada.
Si no existe un usuario registrado con esa cédula,
se levanta una excepción std::invalid_argument.
*/
void eliminarViajes(string ci, const DtFecha& fecha) {
    int posicion_usuario = buscar_usuario(ci);
    if (posicion_usuario != -1) {
        Viaje** viajes = arreglo_usuarios[posicion_usuario] -> getViajes();
        int j = (arreglo_usuarios[posicion_usuario] -> getCantViajes())-1;
        for (int i = arreglo_usuarios[posicion_usuario] -> getCantViajes()-1; i >= 0; i--) {
            if (viajes[i] -> getFecha() == fecha) {
                if (j == i) {
                    delete viajes[i];
                    viajes[i] = nullptr;
                }
                else {
                    delete (viajes[i]);
                    viajes[i] = viajes[j];
                    viajes[j] = nullptr;
                }
                j--;
            }
        }
        arreglo_usuarios[posicion_usuario] -> setCantViajes(j);
    }
    else
        throw new invalid_argument ("No existe el usuario ingresado.");
}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por nroSerieVehiculo.
En caso de que( el vehículo no exista,
o la carga ingresada no se encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {
    int posicion_vehiculo = buscar_vehiculo(nroSerieVehiculo);
    if ((posicion_vehiculo != -1) && (0 <= cargaVehiculo) && (cargaVehiculo <= 100))
        arreglo_vehiculos[posicion_vehiculo] -> set_porcentaje_bateria(cargaVehiculo);
    else
        throw new invalid_argument ("No se pudo cambiar la batería del vehículo ingresado.");
}

/*
Devuelve un arreglo con los vehículos del sistema.
cantVehiculos es un parámetro de salida donde se
devuelve la cantidad de vehículos (corresponde a la cantidad de valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
    cantVehiculos = tope_vehiculo;
    if (tope_vehiculo > 0) {
        DtVehiculo** arreglo_dtv = new DtVehiculo*[tope_vehiculo];
        for (int i=0; i<tope_vehiculo; i++) {
            Bicicleta *bici = dynamic_cast<Bicicleta*>(arreglo_vehiculos[i]);
            if (bici != nullptr) //arreglo_vehiculos[i] es Bicicleta
                arreglo_dtv[i] = new DtBicicleta(bici -> get_nro_serie(), bici -> get_porcentaje_bateria(), bici -> get_precio_base(), bici -> get_tipo(), bici -> get_cant_cambios());
            else {
                Monopatin* mono = dynamic_cast<Monopatin*>(arreglo_vehiculos[i]);
                if (mono != nullptr) //arreglo_vehiculos[i] es monopatin
                    arreglo_dtv[i] = new DtMonopatin(mono->get_nro_serie(), mono->get_porcentaje_bateria(), mono->get_precio_base(), mono->get_luces());
            }
        }
        return arreglo_dtv;
    }
    else
        return nullptr;
}

int main() {
    tope_usuario = 0;
    tope_vehiculo = 0;
    int i = 0;
    bool salir = false;
    string msj = "";
    system("clear");
    while(!salir) {
        cout << "--------------------" << msj << "-------------------- \n \n"
            << " - Bienvenido. Elija la opción deseada -  \n \n"
            << " 1) Registrar un usuario. \n"
            << " 2) Agregar un vehículo. \n"
            << " 3) Ingresar un viaje. \n"
            << " 4) Ver viajes de un usuario. \n"
            << " 5) Eliminar viajes de un usuario. \n"
            << " 6) Cambiar batería de un vehículo. \n"
            << " 7) Obtener vehículos. \n"
            << " 0) Salir. \n \n"
            << " Opción: ";
        cin >> i;
        switch(i) {

        /* 1) Registrar un usuario */
        case 1:
        	try {
                system("clear");
                cout << "\nIngrese el nombre del usuario. \n"
                    << " Nombre: ";
                string nombre1;
	            cin >> nombre1;
	            string ci1 = conseguir_cedula();
	            registrarUsuario(ci1, nombre1);
	        } catch(exception* e) {
                msj =  e -> what();
	        	break;
	        }
            system("clear");
            msj = "Usuario agregado correctamente.";
            break;

        /* 2) Agregar un vehículo */
        case 2:
        	try {
                system("clear");
        		cout << "\nIndique ingresando M o B si ingresa un monopatín o una bicicleta respectivamente: \n ";
        		string V;
        		cin >> V;
                while ((V != "M") && (V != "B")) {
                    cout << "Caracter no válido. Indique ingresando M o B si ingresa un monopatín o una bicicleta respectivamente: \n ";
                    cin >> V;
                }
                int nro_serie;
                float porcentaje, precio_base;
        		    if (V == "M") {
                    int luz;
                    bool tieneLuces;
                    conseguir_datos_vehiculo(nro_serie, porcentaje, precio_base);
                    cout << "Indique ingresando 1 si tiene luces, de lo contrario, 0: \n ";
                    cin >> luz;
                    while ((luz != 1) && (luz != 0)) {
                        cout << "Número no válido. Indique ingresando 1 si tiene luces, de lo contrario, 0: \n ";
                        cin >> luz;
                    }
                    if (luz == 1)
                        tieneLuces = true;
                    else
                        tieneLuces = false;
                    DtMonopatin dtm(nro_serie, porcentaje, precio_base, tieneLuces);
                    const DtVehiculo* dtv = &dtm;
                    agregarVehiculo(*dtv);
                    }
                    else {
                        TipoBici tb;
                        conseguir_datos_vehiculo(nro_serie, porcentaje, precio_base);
                        cout << "Ingrese el tipo de bicicleta, (Paseo o Montana). \n"
                            << " Tipo de bicicleta: ";
                        string tipo;
                        cin >> tipo;
                    while(tipo != "Paseo" && tipo != "Montana") {
                        cout << "Tpo de bicicleta inválido. Ingrese un tipo de bicicleta válido (Paseo o Montana) \n"
                          << " Tipo de bicicleta: ";
                        cin >> tipo;
                    }
                    if(tipo == "Paseo")
                        tb = Paseo;
                    else
                        tb = Montana;
                    cout << "Ingrese la cantidad de cambios de la bicicleta. \n"
                        << " Cantidad de cambios: ";
                    int cant_cambios;
                    cin >> cant_cambios;
                    while (cant_cambios <= 0) {
                        cout << "Número no válido. Ingrese la cantidad de cambios (número positivo). \n"
                            << " Cantidad de cambios: ";
                        cin >> cant_cambios;
                    }
                    DtBicicleta dtb(nro_serie, porcentaje, precio_base, tb, cant_cambios);
                    const DtVehiculo* dtv = &dtb;
                    agregarVehiculo(*dtv);
                    }
          } catch(exception* e) {
                system("clear");
        		msj = e -> what();
        		break;
            }
            system("clear");
        	msj = "Vehículo agregado correctamente.";
            break;

        /* 3) Ingresar un viaje */
        case 3:
            system("clear");
            try {
                string ci3 = conseguir_cedula();
                cout << "\nIngrese el número de serie del vehículo. \n"
                    << " Nº de serie: ";
                int nro_serie_vehiculo;
                cin >> nro_serie_vehiculo;
                DtFecha fecha3 = conseguir_fecha();
                cout << "Ingrese la duración del viaje. \n"
                    << " Duracion: ";
                int duracion;
                cin >> duracion;
                cout << "Ingrese la distancia del viaje. \n "
                    << " Distancia: ";
                int distancia;
                cin >> distancia;
                DtViajeBase viaje(fecha3, duracion, distancia);
                ingresarViaje(ci3, nro_serie_vehiculo, viaje);
            } catch(exception* e) {
                system("clear");
                msj = e -> what();
                break;
            }
            system("clear");
            msj = "Viaje ingresado correctamente.";
            break;

        /* 4) Ver viajes de un usuario */
        case 4: {
            system("clear");
            string ci4 = conseguir_cedula();
            DtFecha fecha4 = conseguir_fecha();
            int cantViajes = 0;
            DtViaje** viajes = verViajesAntesDeFecha(fecha4, ci4, cantViajes);
            if (cantViajes == 0) {
                msj = "No hay viajes antes de la fecha ingresada de dicho usuario.";
            } else {
                DtViaje* unViaje;
                while (cantViajes != 0) {
                    unViaje = viajes[cantViajes - 1];
                    cout << "\nInformación del viaje nº " << cantViajes << ": \n"
                        << " Fecha: " << unViaje -> getFecha().getDia() << "/" << unViaje -> getFecha().getMes() << "/" << unViaje -> getFecha().getAnio() << "\n"
                        << " Duración: " << unViaje -> getDuracion() << "\n"
                        << " Distancia: " << unViaje -> getDistancia() << "\n"
                        << " Nº de serie del vehículo: " << unViaje -> getVehiculo() -> getNroSerie() << "\n"
                        << " Precio total: " << unViaje -> getPrecioTotal() << "\n";
                    cantViajes--;
                }
                for (int i=0; i<cantViajes; i++)
                    delete (viajes)[i];
                cout << "\nPresione cualquier tecla y luego enter para continuar";
                string enter;
                cin >> enter;
                system("clear");
                msj = "Lista mostrada correctamente.";
            }
        }
        break;

        /* 5) Eliminar viajes de un usuario */
        case 5: 
            system("clear");
            try {
                string ci5 = conseguir_cedula();
                DtFecha fecha5 = conseguir_fecha();
                eliminarViajes(ci5, fecha5);
            } catch(exception* e) {
                msj = e -> what();
                break;
            }
            system("clear");
            msj = "Viajes eliminados satisfactoriamente.";
            break;

        /* 6) Cambiar batería de un vehículo */
        case 6:
            system("clear");
            try {
                cout << "\nIngrese el número de serie del vehículo. \n"
                    << " Nº de serie: ";
                int nro_serie_vehiculo;
                cin >> nro_serie_vehiculo;
                cout << "Ingrese el nuevo porcentaje de carga de la batería del vehículo \n"
                    << " Porcentaje (%) batería: ";
                float cargaVehiculo;
                cin >> cargaVehiculo;
                cambiarBateriaVehiculo(nro_serie_vehiculo, cargaVehiculo);
            } catch(exception* e) {
                msj = e -> what();
                break;
            }
            system("clear");
            msj = "Porcentaje de batería cambiado.";
            break;

        /* 7) Obtener vehículos */
        case 7: {
            system("clear");
            int cantVehiculos = 0;
            DtVehiculo** vehiculos = obtenerVehiculos(cantVehiculos);
            if (cantVehiculos == 0) {
                system("clear");
                msj = "No hay vehículos registrados en el sistema.";
            } else {
                DtVehiculo* unVehiculo;
                while (cantVehiculos != 0) {
                    unVehiculo = vehiculos[cantVehiculos - 1];
                    cout << "\nInformación del vehículo nº " << cantVehiculos << ": \n"
                        << " Nº de serie: " << unVehiculo -> getNroSerie() << "\n"
                        << " Porcentaje (%) batería: " << unVehiculo -> getPorcentaje() << "\n"
                        << " Precio base: " << unVehiculo -> getPrecioBase() << "\n";
                    DtBicicleta *dtb = dynamic_cast<DtBicicleta*>(unVehiculo);
                    if (dtb != nullptr) {
                        if (dtb -> getTipo() == Paseo)
                            cout << " Tipo de bicicleta: Paseo \n";
                        else cout << " Tipo de bicicleta: Montaña \n";
                            cout << " Cantidad de cambios: " << dtb -> getCantCambios() << "\n";
                    }
                    else {
                        DtMonopatin *dtm = static_cast<DtMonopatin*>(unVehiculo);
                        cout << "Tiene luces: ";
                        if (dtm -> getTieneLuces())
                            cout << "Si \n";
                        else
                            cout << "No \n";
                    }
                    cantVehiculos--;
                }
                cout << "\nPresione cualquier tecla y luego enter para continuar";
                string enter;
                cin >> enter;
                system("clear");
                msj = "";
            }
        }
        break;

        /* 0) Salir */
        case 0: {
            salir = true;
            if (tope_usuario != 0) {
                for (int i=0; i<tope_usuario; i++)
                    delete arreglo_usuarios[i];
            }
            if (tope_vehiculo !=0) {
                for (int i=0; i<tope_vehiculo; i++)
                    delete arreglo_vehiculos[i];
            }
            cout << "\nHasta pronto! :D\n \n";
        }
        break;

        /* Número ingresado incorrecto */
        default: {
            system("clear");
            msj = "Número inválido. Ingrese valor entre 0 y 7.";
        }
        break;

        } //fin switch
    } //fin while
    return 0;
} //fin main
