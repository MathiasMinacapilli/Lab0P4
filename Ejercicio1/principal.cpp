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

using namespace std;

#define MAX_USUARIOS ... //AGREGAR NUMERO
#define MAX_VEHICULOS ... //AGREGAR NUMERO

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
/*
Busca si existe la cedula cid en el arreglo_usuarios.
Si existe, devuelve el numero de posicion del arreglo.
Sino, devuelve -1.
*/
static int buscar_usuario(string cid) {
    bool encontre = false;
    int i=0;
    while (!encontre && i<tope_usuario){
        if (arreglo_usuarios[i]->ci.compare(cid)==0)
            encontre = true;
        else i++;
    }
    if (encontre)
        return i;
    else return -1;
}

/*
Busca si existe el vehiculo con numserie en el arreglo_vehiculos.
Si existe, devuelve el numero de posicion de ese vehiculo.
Sino, devuelve -1.
*/
static int buscar_vehiculo(int numserie) {
    bool encontre = false;
    int i=0;
    while (!encontre && i<tope_vehiculo){
        if (arreglo_vehiculos[i]->nro_serie == numserie)
            encontre = true;
        else i++;
    }
    if (encontre)
        return i;
    else return -1;

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
    DtFecha fecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    arreglo_usuarios[tope_usuario] = new Usuario(ci, nombre, fecha /*, 0*/);
    tope_usuario++;
  }
  else
      throw new invalid_argument ("Ya existe usuario con esa ci");
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
        throw new invalid_argument("No hay mas lugar para vehiculos");

    else

        if ((buscar_vehiculo(vehiculo.getNroSerie()) == -1) && (0 <= vehiculo.getPorcentaje()) && (vehiculo.getPorcentaje() <= 100) && (vehiculo.getPrecioBase() >= 0)) {
            DtVehiculo* v = &vehiculo;
            DtBicicleta *dtb = dynamic_cast<DtBicicleta*>(v)
            if (dtb) {
                Bicicleta *bici = new Bicicleta(dtb->getNroSerie(), dtb->getPorcentaje(), dtb->getPrecioBase(), dtb->getTipo(), dtb->getCantCambios());
                arreglo_vehiculos[tope_vehiculo] = bici;
            }
            else //es monopatin
                { DtMonopatin* dtm = dynamic_cast<DtMonopatin*>(v);
                Monopatin *mono = new Monopatin(dtm->getNroSerie(), dtm->getPorcentaje(), dtm->getPrecioBase(), dtm->getTieneLuces());
                arreglo_vehiculos[tope_vehiculo] = mono;
                }
             tope_vehiculo++;
    }
    else throw new invalid_argument("verifique parametros")
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
  if ((posicion_usuario != -1) && (posicion_vehiculo != -1) &&
      (viaje.getDuracion() > 0) && (viaje.getDistancia() > 0) &&
      (viaje.getFecha() >= arreglo_usuarios[posicion_usuario] -> getFechaIngreso())) {
        Viaje trip(viaje.getFecha(), viaje.getDuracion(), viaje.getDistancia(), arreglo_vehiculos[posicion_vehiculo]);
        arreglo_usuarios[posicion_usuario] -> agregarViaje(trip);
  }
  else
      throw new invalid_argument ("No se pudo ingresar el viaje");
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
    DtViaje* arreglo_dtv; //= new DtViaje[2];
    DtViaje** vaf = nullptr;

    int posicion_usuario = buscar_usuario(ci);
    if(posicion_usuario != -1) {
        // Si encontre (o existe) el usuario con esa ci
        Viaje** viajes_usuario = arreglo_usuarios[posicion_usuario]->getViajes();
        int j=0;
        for(int i = 0; i < arreglo_usuarios[posicion_usuario]->getCantViajes(); i++) {
            //Cuento la cantidad de viajes que hay con menor fecha que la recibida por parametro
            //y voy agregando a mi arreglo para devolver
            if(!((*viajes_usuario)[i].getFecha() >= fecha)) {
                //agregar al arreglo de alguna forma y de algun tamaño
                j++;
            }
        }
        cantViajes = j;

    }
    DtViaje** vaf =  &arreglo_dtv;

    return vaf;
}

/*
Elimina los viajes del usuario identificado por ci,
realizados en la fecha ingresada.
Si no existe un usuario registrado con esa cédula,
se levanta una excepción std::invalid_argument.
*/
void eliminarViajes(string ci, const DtFecha& fecha) {
    int posicion_usuario = buscar_usuario(ci);
    if (posicion_usario != -1) {
        Viajes* viajes = arreglo_usuarios[posicion_usario].getViajes();
        int j = arreglo_usuarios[posicion_usuario] -> cant_viajes;
        for (int i = arreglo_usuarios[posicion_usuario] -> cant_viajes; i >= 0; i--) {
            if (viajes[i].getFecha == fecha) {
              if (j != i)
                viajes[i] = viajes[j];
              j--;
            }
        }
        arreglo_usuarios[posicion_usario] -> setCantViajes(j);
    }
    else
        throw new invalid_argument ("No existe el usuario ingresado");
}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por nroSerieVehiculo.
En caso de que( el vehículo no exista,
o la carga ingresada no se encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {
    int posicion_vehiculo = buscar_vehiculo(nroSerieVehiculo);
    if ((posicion_vehiculo != -1) && (0 <= cargaVehiculo) && (cargaVehiculo <= 100))
        arreglo_vehiculos[posicion_vehiculo].set_porcentaje_bateria(cargaVehiculo);
    else
        throw new invalid_argument ("No se pudo cambiar la bateria del vehiculo");

}

/*
Devuelve un arreglo con los vehículos del sistema.
cantVehiculos es un parámetro de salida donde se
devuelve la cantidad de vehículos (corresponde a la cantidad de valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
    if (tope_vehiculo>0){
        DtVehiculo* arreglo_dtv = new DtVehiculo[tope_vehiculo]
        //creo puntero al arreglo de DTVehiculos
        DtVehiculo** puntero_dtv =  &arreglo_dtv;
        for (int i=0; i<tope_vehiculo; i++){

            *arreglo_dtv[i]->DtVehiculo()
        }

    }
    else
        return nullptr;
}

// main
int main() {
    tope_usuario = 0;
    tope_vehiculo = 0;
    int i = 0;
    bool salir = false;
	//Hay que fijarse que se ingrese todo bien?
    while(!salir) {
        cout << "Bienvenido. Elija la opción deseada. \n"
            << "1) Registrar un Usuario \n"
            << "2) Agregar un Vehiculo \n"
            << "3) Ingresar un Viaje \n"
            << "4) Ver viajes de un Usuario \n"
            << "5) Eliminar viajes de un Usuario \n"
            << "6) Cambiar bateria de un Vehiculo \n"
            << "7) Obtener Vehiculos \n"
            << "0) Salir \n"
            << "Opción: ";
        cin >> i;
        switch(i) {
        case 1:
        	try {
	            cout << "Ingrese el nombre del Usuario \n "
	                << "Nombre: ";
	            string nombre;
	            cin >> nombre;
	            cout << "Ingrese la cedula del Usuario sin guion ni digito y con verificador \n "
	            	<< "Cedula: ";
	            string ci
	            cin >> ci;
                while ((ci.size() != 8) && (!son_digitos(ci))) {
                    cout << "Cedula no valida. Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                        << "Cedula: ";
                    cin >> ci;
                }
	            registrarUsuario(ci, nombre)
	        } catch(exception* e) {
	        	cout << e->what();
	        	break;
	        }
	        cout << "Usuario agregado. \n ";
            break;
        case 2: //
        	try {
        		cout << "Indique ingresando M o B si ingresa un Monopatin o Bicicleta respectivamente: \n ";
        		char V;
        		cin >> V;
                while ((V != M) && (V != B)) {
                    cout << "Caracter no valido. Indique ingresando M o B si ingresa un Monopatin o Bicicleta respectivamente: \n ";
                    cin >> V;
                }
        		if (V == M) {
        			cout << "Ingrese el numero de serie \n "
        				<< "Nº de serie: ";
        			int nro_serie;
        			cin >> nro_serie;
        			cout << "Ingrese el porcentaje de bateria \n "
        				<< "% bateria: ";
        			float porcentaje;
        			cin >> porcentaje;
        			cout << "Ingrese el precio base del Monopatin \n "
        				<< "Precio base: ";
        			float precio_base;
        			cin >> precio_base;
        			cout << "Indique ingresando 1 si tiene luces, de lo contrario, 0: \n ";
        			int luz;
        			cin >> luz;
                    while ((luz != 1) && (luz != 0)) {
                        cout << "Numero no valido. Indique ingresando 1 si tiene luces, de lo contrario, 0: \n ";
                        cin >> luz;
                    }
        			bool tieneLuces;
        			if (luz == 1)
        				tieneLuces = true
        			else
        				tieneLuces = false;
        			DtMonopatin dtm(nro_serie, porcentaje, precio_base, tieneLuces);
        			DtVehiculo& dtv = dtm;
        			agregarVehiculo(dtv);
        		} else {
        			cout << "Ingrese el numero de serie \n "
        				<< "Nº de serie: ";
        			int nro_serie;
        			cin >> nro_serie;
        			cout << "Ingrese el porcentaje de bateria \n "
        				<< "% bateria: ";
        			float porcentaje;
        			cin >> porcentaje;
        			cout << "Ingrese el precio base de la Bicicleta \n "
        				<< "Precio base: ";
        			float precio_base;
        			cin >> precio_base;
                    // Como hacer el chequeo aca
        			cout << "Ingrese el tipo de Bicicleta, Paseo o Montaña \n "
        				<< "Tipo de Bici: ";
        			TipoBici tipo;
        			cin >> tipo;
        			cout << "Ingrese la cantidad de cambios \n "
        				<< "Cantidad de cambios: ";
        			int cant_cambios;
        			cin >> cant_cambios;
                    while (cant_cambios <= 0) {
                        cout << "Numero no valido. Ingrese la cantidad de cambios \n "
                            << "Cantidad de cambios: ";
                        cin >> cant_cambios;
                    }
        			DtBicicleta dtb(nro_serie, porcentaje, precio_base, tipo, cant_cambios);
        			DtVehiculo& dtv = dtb;
        			agregarVehiculo(dtv);
        		}
        	} catch(exception* e) {
        		cout << e->what();
        		break;
        	}
        	cout << "Vehiculo agregado. \n ";
            break;
        case 3:
            try {
                cout << "Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                    << "Cedula: ";
                string cedula;
                cin >> cedula;
                while ((ci.size() != 8) && (!son_digitos(ci))) {
                    cout << "Cedula no valida. Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                        << "Cedula: ";
                    cin >> ci;
                }
                cout << "Ingrese el numero de serie del Vehiculo \n "
                    << "Nº de serie: ";
                int nro_serie_vehiculo;
                cin >> nro_serie_vehiculo;
                // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
                int dia, mes, anio;
                cout << "Ingrese la fecha del viaje \n"
                    << "DD/MM/AAAA: ";
                cin >> dia;
                cin.get();
                cin >> mes;
                cin.get();
                cin >> anio;
                DtFecha fecha(dia, mes, anio);
                cout << "Ingrese la duracion del viaje \n "
                    << "Duracion: ";
                int duracion;
                cin >> duracion;
                cout << "Ingrese la distancia del viaje \n "
                    << "Distancia: ";
                int distancia;
                cin >> distancia;
                DtViajeBase viaje(fecha, duracion, distancia);
                ingresarViaje(cedula, nro_serie_vehiculo, viaje);
            } catch(exception* e) {
                cout << e->what();
                break;
            }
            cout << "Viaje ingresado. \n ";
            break;
        case 4:
            cout << "Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                << "Cedula: ";
            string cedula;
            cin >> cedula;
            while ((ci.size() != 8) && (!son_digitos(ci))) {
                cout << "Cedula no valida. Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                << "Cedula: ";
                cin >> ci;
            }
            // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
            int dia, mes, anio;
                cout << "Ingrese la fecha del viaje \n"
                    << "DD/MM/AAAA: ";
                cin >> dia;
                cin.get();
                cin >> mes;
                cin.get();
                cin >> anio;
                DtFecha fecha(dia, mes, anio);
            int cantViajes = 0;
            DtViaje** viajes = verViajesAntesDeFecha(fecha, cedula, cantViajes);
            if (cantViajes == 0) {
                cout << "No hay viajes del Usuario con cedula "
                    << cedula
                    << " antes del " << dia << "/" << mes << "/" << anio;
            } else {
                DtViaje* unViaje;
                while (cantViajes != 0) {
                    unViaje = &viajes[cantViajes - 1];
                    cout << "Informacion del viaje nº " << cantViajes << ": \n "
                        << "Fecha: " << unViaje->getFecha().getDia() << "/" << unViaje->getFecha().getMes() << "/" << unViaje->getFecha().getAnio() << "\n"
                        << "Duracion: " << unViaje->getDuracion() << "\n"
                        << "Distancia: " << unViaje->getDistancia() << "\n"
                        << "Nº de serie del Vehiculo: " << unViaje->getVehiculo().getNroSerie() << "\n"
                        << "Precio total: " << unViaje->getPrecioTotal() << "\n";
                    cantViajes--;
                }
            }
            break;
        case 5:
            try {
                cout << "Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                    << "Cedula: ";
                string cedula;
                cin >> cedula;
                while ((ci.size() != 8) && (!son_digitos(ci))) {
                    cout << "Cedula no valida. Ingrese la cedula del Usuario sin guion y con digito verificador \n "
                        << "Cedula: ";
                    cin >> ci;
                }
                // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
                int dia, mes, anio;
                cout << "Ingrese la fecha del viaje \n"
                    << "DD/MM/AAAA: ";
                cin >> dia;
                cin.get();
                cin >> mes;
                cin.get();
                cin >> anio;
                DtFecha fecha(dia, mes, anio);
                eliminarViajes(cedula, fecha);
            } catch(exception* e) {
                cout << e->what();
                break;
            }
            cout << "Viajes eliminados. \n ";
            break;
        case 6:
            try {
                cout << "Ingrese el numero de serie del Vehiculo \n "
                    << "Nº de serie: ";
                int nro_serie_vehiculo;
                cin >> nro_serie_vehiculo;
                cout << "Ingrese el nuevo porcentaje de carga de la bateria del Vehiculo \n "
                    << "% bateria: ";
                float cargaVehiculo;
                cin >> cargaVehiculo;
                cambiarBateriaVehiculo(nro_serie_vehiculo, cargaVehiculo);
            } catch(exception* e) {
                cout << e->what();
                break;
            }
            cout << "Porcentaje de Bateria cambiado. \n ";
            break;
        case 7:
            int cantVehiculos = 0;
            DtVehiculo** vehiculos = obtenerVehiculos(cantVehiculos);
            if (cantVehiculos == 0) {
                cout << "No hay vehiculos registrados en el sistema. \n";
            } else {
                DtVehiculo* unVehiculo;
                while (cantVehiculos != 0) {
                    unVehiculo = &vehiculos[cantVehiculos - 1];
                    cout << "Informacion del vehiculo nº " << cantVehiculos << ": \n "
                        << "Nº de serie: " << unVehiculo->getNroSerie() << "\n"
                        << "% bateria: " << unVehiculo->getPorcentaje() << "\n"
                        << "Precio base: " << unVehiculo->getPrecioBase() << "\n";
                    DtBicicleta *dtb = dynamic_cast<DtBicicleta*>(unVehiculo);
                    if (dtb != nullptr) {
                        cout << "Tipo de Bicicleta: " << dtb->getTipo() << "\n"
                            << "Cantidad de cambios: " << dtb->getCantCambios() << "\n";
                    } else {
                        DtMonopatin *dtm = dynamic_cast<DtMonopatin*>(unVehiculo);
                        cout << "Tiene luces: ";
                        if (dtm->getTieneLuces)
                            cout << "Si \n";
                        else
                            cout << "No \n";
                    }
                    cantVehiculos--;
                }
            }
            break;
        case 0:
            salir = true;
            break;
        }
    }

    return 0;
}
