
#ifndef _USUARIO_HPP
#define _USUARIO_HPP

#include "DtFecha.hpp"
#include "Viaje.hpp"

#include <vector>
#include <string>
using namespace std;

class Usuario {
private:
    std::string ci, nombre;
    DtFecha fecha_ingreso;
    int cant_viajes; //tope del arreglo viajes[100]
    Viaje *viajes[100];
public:
    //Constructor
    Usuario(string, string, DtFecha, int);

    //Getters
    std::string getCi() const;
    std::string getNombre() const;
    DtFecha getFechaIngreso() const;
    int getCantViajes() const;
    Viaje** getViajes();

    //Setters
    void setCi(std::string);
    void setNombre(std::string);
    void setFechaIngreso(DtFecha);
    void setCantViajes(int);
    
    //Agrega un viaje al usuario
    int agregarViaje(Viaje*);

    //Destructor
    ~Usuario();
};
#endif
