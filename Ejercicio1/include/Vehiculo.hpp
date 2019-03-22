#ifndef _VEHICULO_HPP
#define _VEHICULO_HPP


#include "TipoBici.hpp"

class Vehiculo {
private:
    int nro_serie;
    float porcentaje_bateria, precio_base;
protected: //protected para que no se pueda instanciar afuera de las subclases
	//constructor y desturctor
	Vehiculo(int=0, float=0, float=0);
	~Vehiculo();
public:
	//setters
	void set_nro_serie(int);
	void set_porcentaje_bateria(float);
	void set_precio_base(float);
	//getters
	int get_nro_serie();
	float get_porcentaje_bateria();
	float get_precio_base();
    virtual float darPrecioViaje(int, int) = 0;
};

#endif
