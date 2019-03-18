
#include "DtFecha.hpp"
#include "Viaje.hpp"

#include <vector>
#include <string>

class Usuario {
private:
    std::string ci, nombre;
    DtFecha fecha_ingreso;
    int cant_viajes; //tope del arreglo viajes[100]
    std::vector<Viaje> viajes[100];
public:
    //Constructos
    Usuario(string, string, DtFecha, int = 0);

    //Getters
    std::string getCi();
    std::string getNombre();
    DtFecha getFechaIngreso();

    //Setters
    void setCi(std::string);
    void setNombre(std::string);
    void setFechaIngreso(DtFecha);

    /* ¿Getter y setter de viajes y cant_viajes? */

    /*
    Agrega un viaje al usuario. De tener 100 viajes, no hace nada.
    */
    void agregarViaje(Viaje);


    ~Usuario();
};
