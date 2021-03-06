#ifndef _BICICLETA_HPP
#define _BICICLETA_HPP

#include "Vehiculo.hpp"

// Bicicleta subclase de Vehiculo
class Bicicleta : public Vehiculo {
private:
    TipoBici tipo;
    int cant_cambios;
public:
	//constructor y destructor
	Bicicleta(int, float, float, TipoBici, int);
	~Bicicleta();
	//getters
	TipoBici get_tipo() const;
	int get_cant_cambios() const;
	//setters
	void set_tipo(TipoBici);
	void set_cant_cambios(int);

    float darPrecioViaje(int, int);

};

#endif
