
#include "DtFecha.hpp"
#include "Viaje.hpp"

#include <string>

class Usuario {
private:
    std::string ci, nombre;
    DtFecha fecha_ingreso;
    int cant_viajes; //tope del arreglo viajes[100]
    Viaje viajes[100];
public:
    std::string getCi();
    std::string getNombre();
    DtFecha getFechaIngreso();
    void setCi();
    void setNombre();
    void setFechaIngreso();
};
