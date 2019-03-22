#ifndef _VEHICULO_HPP
#define _VEHICULO_HPP

#include "Vehiculo.hpp"

// Bicicleta subclase de Vehiculo
class Bicicleta: public Vehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
	//constructor y destructor
	Bicicleta(int, float, float, TipoBici, int);
	~Bicicleta();
	//getters
	TipoBici get_tipo();
	int get_cant_cambios();
	//setters
	void set_tipo(TipoBici);
	void set_cant_cambios(int);

    float darPrecioViaje(int, int);

};

#endif
