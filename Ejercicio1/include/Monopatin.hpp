#ifndef _MONOPATIN_HPP
#define _MONOPATIN_HPP

#include "Vehiculo.hpp"

// Monopatin es subclase de Vehiculo
class Monopatin: public Vehiculo {
private:
    bool tieneLuces;
public:
	//constructor y destructor
	Monopatin(int, float, float, bool=false);
	~Monopatin();
	//getter
	bool get_luces();
	//setter
	void set_tieneLuces(bool);

    float darPrecioViaje(int, int);

};

#endif
