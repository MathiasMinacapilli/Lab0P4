#include "../include/Monopatin.hpp"

//clase Monopatin

//constructor con parametros
Monopatin::Monopatin(int num, float bateria, float pb, bool luces)
	:Vehiculo(num, bateria, pb){
		this->tieneLuces=luces;

}

//getter
bool Monopatin::get_luces() const{
	return this->tieneLuces;
}

//setter
void Monopatin::set_tieneLuces(bool luces){
	this->tieneLuces = luces;
}

//operacion polimorfica
float Monopatin::darPrecioViaje(int duracion, int distancia){
	if (tieneLuces)
		return ((0.5*duracion) + (distancia*get_precio_base()));
	else //no tiene luces
		return distancia*get_precio_base();
}


//destructor
Monopatin::~Monopatin(){}
