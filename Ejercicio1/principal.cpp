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
#include <typeinfo>
#include <algorithm>
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

string conseguir_cedula() {
    cout << "Ingrese la cedula del Usuario sin guion ni digito y con verificador \n "
        << "Cedula: ";
    string ci;
    cin >> ci;
    while ((ci.size() != 8) || (!son_digitos(ci))) {
        cout << "Cedula no valida. Ingrese la cedula del Usuario sin guion y con digito verificador \n "
            << "Cedula: ";
        cin >> ci;
    }
    return ci;
}

void conseguir_datos_vehiculo(int &nro_serie, float &porcentaje, float &precio_base) {
    cout << "Ingrese el numero de serie \n "
        << "Nº de serie: ";
    cin >> nro_serie;
    cout << "Ingrese el porcentaje de bateria \n "
        << "% bateria: ";
    cin >> porcentaje;
    cout << "Ingrese el precio base del Vehiculo \n "
        << "Precio base: ";
    cin >> precio_base;
}

DtFecha conseguir_fecha(int &dia, int &mes, int &anio) {
    cout << "Ingrese la fecha del viaje \n"
        << "DD/MM/AAAA: ";
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
    int i=0;
    while (!encontre && i<tope_usuario){
        if (arreglo_usuarios[i]->getCi().compare(cid)==0)
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
        if (arreglo_vehiculos[i]->get_nro_serie() == numserie)
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
      throw new invalid_argument ("Ya existe un Usuario con esa ci");
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
    else {
        if ((buscar_vehiculo(vehiculo.getNroSerie()) == -1) && (0 <= vehiculo.getPorcentaje()) && (vehiculo.getPorcentaje() <= 100) && (vehiculo.getPrecioBase() >= 0)) {
            const DtVehiculo* v = &vehiculo;
            
            const DtBicicleta* dtb = dynamic_cast<DtBicicleta*>(const_cast<DtVehiculo*>(v));
            if (dtb != nullptr) {
                Bicicleta *bici = new Bicicleta(dtb->getNroSerie(), dtb->getPorcentaje(), dtb->getPrecioBase(), dtb->getTipo(), dtb->getCantCambios());
                arreglo_vehiculos[tope_vehiculo] = bici;
                cout << "agregue bici:)";
            }

            else { //es monopatin
                DtMonopatin* dtm = static_cast<DtMonopatin*>(const_cast<DtVehiculo*>(v));
            else //es monopatin
                {
                
                const DtMonopatin* dtm = dynamic_cast<DtMonopatin*>(const_cast<DtVehiculo*>(v));
                if (dtm == nullptr)
                    cout << "peligro";
                Monopatin *mono = new Monopatin(dtm->getNroSerie(), dtm->getPorcentaje(), dtm->getPrecioBase(), dtm->getTieneLuces());
                arreglo_vehiculos[tope_vehiculo] = mono;
                }
             tope_vehiculo++;
            
                { DtMonopatin* dtm = dynamic_cast<DtMonopatin*>(const_cast<DtVehiculo*>(v));
                Monopatin *mono = new Monopatin(dtm->getNroSerie(), dtm->getPorcentaje(), dtm->getPrecioBase(), dtm->getTieneLuces());
                arreglo_vehiculos[tope_vehiculo] = mono;
            }
            tope_vehiculo++;
        }
        else 
            throw new invalid_argument("Verifique Parametros");
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
  if ((posicion_usuario != -1) && (posicion_vehiculo != -1) &&
      (viaje.getDuracion() > 0) && (viaje.getDistancia() > 0) &&
      (viaje.getFecha() >= arreglo_usuarios[posicion_usuario] -> getFechaIngreso())) {
        Viaje* trip= new Viaje(viaje.getFecha(), viaje.getDuracion(), viaje.getDistancia(), arreglo_vehiculos[posicion_vehiculo]);
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
    DtViaje** arreglo_dtv = nullptr;
    int j=0;
    int posicion_usuario = buscar_usuario(ci);
    if(posicion_usuario != -1) { // Si encontre el usuario con esa ci
        Viaje** viajes_usuario = (arreglo_usuarios[posicion_usuario]->getViajes());
        for(int i = 0; i < arreglo_usuarios[posicion_usuario]->getCantViajes(); i++) {
            //Cuento la cantidad de viajes que hay con menor fecha que la recibida por parametro
            if(!(viajes_usuario[i]->getFecha() >= fecha))
                j++;
        }
        
        cantViajes = j;
        if (j!=0){
           
            int k=0; 
            for (int i = 0; i<j; i++){
                if (!(viajes_usuario[i]->getFecha() >= fecha)){
                    
                    Vehiculo* v = (viajes_usuario[i]->getVehiculo());
                    
                    Bicicleta* bici = dynamic_cast<Bicicleta*>(v);
                    if (bici != nullptr) {
                        DtBicicleta* b = new DtBicicleta(bici->get_nro_serie(), bici->get_porcentaje_bateria(), bici->get_precio_base(), bici->get_tipo(), bici->get_cant_cambios());
                    
                         arreglo_dtv[k] = new DtViaje(viajes_usuario[i]->getFecha(), viajes_usuario[i]->getDuracion(), viajes_usuario[i]->getDistancia(), viajes_usuario[i]->getVehiculo()->darPrecioViaje(viajes_usuario[i]->getDuracion(), viajes_usuario[i]->getDistancia()), b); 
                    }    
                    else {
                        Monopatin* mono=dynamic_cast<Monopatin*>(v);
                        DtMonopatin* m = new DtMonopatin(mono->get_nro_serie(), mono->get_porcentaje_bateria(), mono->get_precio_base(), mono->get_luces());
                    
                         arreglo_dtv[k] = new DtViaje(viajes_usuario[i]->getFecha(), viajes_usuario[i]->getDuracion(), viajes_usuario[i]->getDistancia(), viajes_usuario[i]->getVehiculo()->darPrecioViaje(viajes_usuario[i]->getDuracion(), viajes_usuario[i]->getDistancia()), m); 
                    }
                    
            
                    k++;
                }
            }
                    
        } 
        return arreglo_dtv;
    }
        
    else {
        cantViajes = 0;
        return nullptr;
    }

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
        Viaje** viajes = arreglo_usuarios[posicion_usuario]->getViajes();
        int j = (arreglo_usuarios[posicion_usuario] -> getCantViajes())-1;
        for (int i = arreglo_usuarios[posicion_usuario] -> getCantViajes()-1; i >= 0; i--) {
            if (viajes[i]->getFecha() == fecha) {
                if (j == i){
                    delete viajes[i];
                    viajes[i]=nullptr;
                }
                else {
                    delete (viajes[i]);
                    viajes[i]=viajes[j];
                    viajes[j]=nullptr;
                } 
                  
              j--;
            }
        }
        arreglo_usuarios[posicion_usuario] -> setCantViajes(j);
    }
    else
        throw new invalid_argument ("No existe el Usuario ingresado");
}

/*
Modifica el porcentaje de carga de la bateria del vehículo identificado por nroSerieVehiculo.
En caso de que( el vehículo no exista,
o la carga ingresada no se encuentre entre 0 y 100 se levanta una excepción std::invalid_argument.
*/
void cambiarBateriaVehiculo(int nroSerieVehiculo, float cargaVehiculo) {
    int posicion_vehiculo = buscar_vehiculo(nroSerieVehiculo);
    if ((posicion_vehiculo != -1) && (0 <= cargaVehiculo) && (cargaVehiculo <= 100))
        arreglo_vehiculos[posicion_vehiculo]->set_porcentaje_bateria(cargaVehiculo);
    else
        throw new invalid_argument ("No se pudo cambiar la bateria del vehiculo");

}

/*
Devuelve un arreglo con los vehículos del sistema.
cantVehiculos es un parámetro de salida donde se
devuelve la cantidad de vehículos (corresponde a la cantidad de valores DtVehiculo que se devuelven).
*/
DtVehiculo** obtenerVehiculos(int& cantVehiculos) {
    cantVehiculos = tope_vehiculo;
    if (tope_vehiculo>0) {
        DtVehiculo** arreglo_dtv =  new DtVehiculo*[tope_vehiculo];
        for (int i=0; i<tope_vehiculo; i++){
            Bicicleta *bici = dynamic_cast<Bicicleta*>(arreglo_vehiculos[i]);
            if (bici != nullptr) //arreglo_vehiculos[i] es bici {
                arreglo_dtv[i] = new DtBicicleta(bici->get_nro_serie(), bici->get_porcentaje_bateria(), bici->get_precio_base(), bici->get_tipo(), bici->get_cant_cambios());
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

// main
int main() {
    tope_usuario = 0;
    tope_vehiculo = 0;
    int i = 0;
    bool salir = false;
    
    string msj;
	//Hay que fijarse que se ingrese todo bien?
    while(!salir) {
        //system("clear");
        cout << "Bienvenido. Elija la opción deseada. \n"
            << "------------- " << msj << " -------------" << "\n"
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
        /* 1) Registrar un Usuario */
        case 1:
        	try {
                system("clear");
	            cout << "Ingrese el nombre del Usuario \n "
	                << "Nombre: ";
                string nombre1;
	            cin >> nombre1;
	            string ci1 = conseguir_cedula();
	            registrarUsuario(ci1, nombre1);
	        } catch(exception* e) {
	        	msj =  e->what();
	        	break;
	        }
            msj = "Usuario agregado correctamente.";
            break;
            
        /* 2) Agregar un Vehiculo */
        case 2: //
        	try {
                system("clear");
        		cout << "Indique ingresando M o B si ingresa un Monopatin o Bicicleta respectivamente: \n ";
        		string V;
        		cin >> V;
                while ((V != "M") && (V != "B")) {
                    cout << "Caracter no valido. Indique ingresando M o B si ingresa un Monopatin o Bicicleta respectivamente: \n ";
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
                        cout << "Numero no valido. Indique ingresando 1 si tiene luces, de lo contrario, 0: \n ";
                        cin >> luz;
                    }
        			if (luz == 1)
        				tieneLuces = true;
        			else
        				tieneLuces = false;
        			DtMonopatin dtm(nro_serie, porcentaje, precio_base, tieneLuces);
        			const DtVehiculo* dtv = &dtm;
        			agregarVehiculo(*dtv);
        		} else {
                    TipoBici tb;
        			conseguir_datos_vehiculo(nro_serie, porcentaje, precio_base);
                    // Como hacer el chequeo aca
        			cout << "Ingrese el tipo de Bicicleta, (Paseo o Montana) \n "
        				<< "Tipo de Bici: ";
        			string tipo;
        			cin >> tipo;
                    while(tipo != "Paseo" && tipo != "Montana") {
                        cout << "Ingrese un tipo valido (Paseo o Montana) \n";
                        cin >> tipo;
                    }
                    if(tipo == "Paseo")
                        tb = Paseo;
                    else
                        tb = Montana;
        			cout << "Ingrese la cantidad de cambios \n "
        				<< "Cantidad de cambios: ";
        			int cant_cambios;
        			cin >> cant_cambios;
                    while (cant_cambios <= 0) {
                        cout << "Numero no valido. Ingrese la cantidad de cambios \n "
                            << "Cantidad de cambios: ";
                        cin >> cant_cambios;
                    }
        			DtBicicleta dtb(nro_serie, porcentaje, precio_base, tb, cant_cambios);
                    const DtVehiculo* dtv = &dtb;
                    //const DtVehiculo* v = &dtv;
                    //DtBicicleta* b = dynamic_cast<DtBicicleta*>(const_cast<DtVehiculo*>(dtv));
                    //if (b == nullptr)
                      //  cout << "no entendemos \n \n";
                    cout << "casi agregar vehiculo";
        			agregarVehiculo(*dtv);
                } 
            }catch(exception* e) {
        		msj = e->what();
        		break;
        	}
        	msj = "Vehiculo agregado correctamente.";
            break;
            
        /* 3) Ingresar un Viaje */
        case 3:
            system("clear");
            try {
                string ci3 = conseguir_cedula();
                cout << "Ingrese el numero de serie del Vehiculo \n "
                    << "Nº de serie: ";
                int nro_serie_vehiculo;
                cin >> nro_serie_vehiculo;
                // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
                int dia, mes, anio;
                DtFecha fecha3 = conseguir_fecha(dia, mes, anio);
                cout << "Ingrese la duracion del viaje \n "
                    << "Duracion: ";
                int duracion;
                cin >> duracion;
                cout << "Ingrese la distancia del viaje \n "
                    << "Distancia: ";
                int distancia;
                cin >> distancia;
                DtViajeBase viaje(fecha3, duracion, distancia);
                ingresarViaje(ci3, nro_serie_vehiculo, viaje);
            } catch(exception* e) {
                msj = e->what();
                break;
            }
            msj = "Viaje ingresado correctamente.";
            break;
            
        /* 4) Ver viajes de un Usuario */
        case 4: {
            system("clear");
            string ci4 = conseguir_cedula();
            // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
            int dia, mes, anio;
            DtFecha fecha4 = conseguir_fecha(dia, mes, anio);
            int cantViajes = 0;
            DtViaje** viajes = verViajesAntesDeFecha(fecha4, ci4, cantViajes);
            if (cantViajes == 0) {
                cout << "No hay viajes del Usuario con cedula "
                    << ci4
                    << " antes del " << dia << "/" << mes << "/" << anio << "\n";
            } else {
                DtViaje* unViaje;
                while (cantViajes != 0) {
                    unViaje = viajes[cantViajes - 1];
                    cout << "Informacion del viaje nº " << cantViajes << ": \n "
                        << "Fecha: " << unViaje->getFecha().getDia() << "/" << unViaje->getFecha().getMes() << "/" << unViaje->getFecha().getAnio() << "\n"
                        << "Duracion: " << unViaje->getDuracion() << "\n"
                        << "Distancia: " << unViaje->getDistancia() << "\n"
                        << "Nº de serie del Vehiculo: " << unViaje->getVehiculo()->getNroSerie() << "\n"
                        << "Precio total: " << unViaje->getPrecioTotal() << "\n";
                    cantViajes--;
                }
            }
        }
        break;
        
        /* 5) Eliminar viajes de un Usuario */
        case 5:
            system("clear");
            try {
                string ci5 = conseguir_cedula();
                // Tendria que hacer chequeo aca tambien, mod de 10 y 1000?
                int dia, mes, anio;
                DtFecha fecha5 = conseguir_fecha(dia, mes, anio);
                eliminarViajes(ci5, fecha5);
            } catch(exception* e) {
                msj = e->what();
                break;
            }
            msj = "Viajes eliminados satisfactoriamente. ";
            break;
            
        /* 6) Cambiar bateria de un Vehiculo */
        case 6:
            system("clear");
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
                msj = e->what();
                break;
            }
            msj = "Porcentaje de Bateria cambiado.";
            break;
            
        /* 7) Obtener Vehiculos */
        case 7: {
            system("clear");
            int cantVehiculos = 0;
            DtVehiculo** vehiculos = obtenerVehiculos(cantVehiculos);
            if (cantVehiculos == 0) {
                msj = "No hay vehiculos registrados en el sistema. \n";
            } else {
                DtVehiculo* unVehiculo;
                while (cantVehiculos != 0) {
                    unVehiculo = vehiculos[cantVehiculos - 1];
                    cout << "Informacion del vehiculo nº " << cantVehiculos << ": \n "
                        << "Nº de serie: " << unVehiculo->getNroSerie() << "\n"
                        << "% bateria: " << unVehiculo->getPorcentaje() << "\n"
                        << "Precio base: " << unVehiculo->getPrecioBase() << "\n";
                    // nunca va a entrar al else porque hace el casteo igual, nunca va a ser nullptr
                    DtBicicleta* dummybici;
                    // DtBicicleta *dtb = static_cast<DtBicicleta*>(unVehiculo);
                    if (/*dtb != nullptr*/ typeid(unVehiculo).name() == typeid(dummybici).name()) {
                        DtBicicleta *dtb = static_cast<DtBicicleta*>(unVehiculo);
                        cout << "Tipo de Bicicleta: " << dtb->getTipo() << "\n"
                            << "Cantidad de cambios: " << dtb->getCantCambios() << "\n";
                    } else {
                        DtMonopatin *dtm = static_cast<DtMonopatin*>(unVehiculo);
                        cout << "Tiene luces: ";
                        if (dtm->getTieneLuces())
                            cout << "Si \n";
                        else
                            cout << "No \n";
                    }
                    cantVehiculos--;
                }
                cout << "\nPresione cualquier tecla y luego enter para continuar";
                string enter;
                cin >> enter;
                msj = "";
            }
        }
        break;
        case 0: 
            salir = true;
            cout << "Hasta pronto! :D\n";
            break;
        }
    }

    return 0;
}
