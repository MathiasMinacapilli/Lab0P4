
#include "TipoBici.hpp"

class Vehiculo {
private:
    int nro_serie;
    float porcentaje_bateria, precio_base;
public:
	void set_nro_serie(int);
	void set_porcentaje_bateria(float);
	void set_precio_base(float);
    virtual float darPrecioViaje(int, int) = 0;
};

// Monopatin es subclase de Vehiculo
class Monopatin: public Vehiculo {
private:
    bool tieneLuces;
public:
	Monopatin(int, float, float, bool=false);
    float darPrecioViaje(int, int);
    ~Monopatin();
};

// Bicicleta subclase de Vehiculo
class Bicicleta: public Vehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
	Bicicleta(int, float, float, TipoBici, int);
    float darPrecioViaje(int, int);
    ~Bicicleta();
};

