
#include "DtFecha.hpp"
#include "Viaje.hpp"

#include <vector>
#include <string>

class Usuario {
private:
    std::string ci, nombre;
    DtFecha fecha_ingreso;
    int cant_viajes; //tope del arreglo viajes[100]
    Viaje *viajes[100];
public:
    //Constructor
    Usuario(string, string, DtFecha, int = 0);

    //Getters
    std::string getCi();
    std::string getNombre();
    DtFecha getFechaIngreso();

    //Setters
    void setCi(std::string);
    void setNombre(std::string);
    void setFechaIngreso(DtFecha);

    //Getters Viaje
    int getCantViajes();
    Viaje** getViajes();
    
    //Setter Viaje
    void setCantViajes
    
    /* Agrega un viaje al usuario. De tener 100 viajes, no hace nada. */
    void agregarViaje(Viaje);

    ~Usuario();
};
